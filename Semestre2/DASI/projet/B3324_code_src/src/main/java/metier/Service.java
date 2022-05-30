/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package metier;

import com.google.maps.model.LatLng;
import dao.AgenceDao;
import dao.ClientDao;
import dao.EmployeDao;
import util.GeoNetApi;
import dao.JpaUtil;
import dao.MissionDao;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Hugo Grel et Minh Phung
 */
public class Service {

    public Service() {
    }
    
    public static Client inscrireClient(Client client) throws Exception{
        JpaUtil.creerContextePersistance();
        try{
            Double lat = GeoNetApi.getLatLng(client.getAdresse()).lat;
            Double lng = GeoNetApi.getLatLng(client.getAdresse()).lng;
            client.setLatitude(lat);
            client.setLongitude(lng);
            JpaUtil.ouvrirTransaction();
            ClientDao.creer(client);
            JpaUtil.validerTransaction();
        } catch (Exception ex){
            JpaUtil.annulerTransaction();
            ex.printStackTrace();
            client = null;
        } finally {
            JpaUtil.fermerContextePersistance();
        }
        return client;
    }
    
    public static Client authentifierClient(String mail, String mdp){
        Client clientRetour = null;
        Client client;
        JpaUtil.creerContextePersistance();
        try{
            client = ClientDao.chercherParMail(mail);
            if(client != null){
                if(client.getMotDePasse().equals(mdp)){
                    clientRetour = client;
                }
            }
        } catch (Exception ex){
            ex.printStackTrace();
            clientRetour = null;
        } finally{
            JpaUtil.fermerContextePersistance();
        }
        return clientRetour;
    }
    
    public static Employe authentifierEmploye(String mail, String mdp){
        Employe employeRetour = null;
        Employe employe;
        JpaUtil.creerContextePersistance();
        try{
            employe = EmployeDao.chercherParMail(mail);
            if(employe != null){
                if(employe.getMotDePasse().equals(mdp)){
                    employeRetour = employe;
                }
            }
        } catch (Exception ex){
            ex.printStackTrace();
            employeRetour = null;
        } finally{
            JpaUtil.fermerContextePersistance();
        }
        return employeRetour;
    }
    
    public static Mission creerDemande(Mission mission, Client client){
       JpaUtil.creerContextePersistance();
       LatLng coordsClient = GeoNetApi.getLatLng(client.getAdresse());
       TreeMap<Double,Agence> map = new TreeMap<>();
       
       try{
            List <Agence> listAgence = AgenceDao.listerTousAgences();

            for (int i = 0; i < listAgence.size(); i++){
                LatLng coordsAgence = GeoNetApi.getLatLng(listAgence.get(i).getAdresseAgence());
                Double distanceVolDOiseau = GeoNetApi.getFlightDistanceInKm(coordsAgence, coordsClient);
                map.put(distanceVolDOiseau, listAgence.get(i));
            }
            Calendar calendar = GregorianCalendar.getInstance();
            int heureActuelle = calendar.get(Calendar.HOUR_OF_DAY);
            System.out.println(heureActuelle);
            Employe employe = EmployeDao.chercherEmployeDispo(map.firstEntry().getValue(), heureActuelle);
            for (Map.Entry<Double, Agence> entry : map.entrySet()){
                employe = EmployeDao.chercherEmployeDispo(entry.getValue(), heureActuelle);
                if (employe!= null){
                    break;
                }
            }
            
            employe.setDispo(false);
           
            mission.setUnEmploye(employe);
            mission.setUnClient(client);
            mission.setDateHeureDemande(Date.from(LocalDateTime.now().atZone(ZoneId.systemDefault()).toInstant()));
            
            JpaUtil.ouvrirTransaction();
            MissionDao.creer(mission);
            JpaUtil.validerTransaction();
            
       }catch(Exception ex){
            ex.printStackTrace();
            mission = null;
        } finally{
            JpaUtil.fermerContextePersistance();
        }
       
       return mission;
    }
    
    public static Mission cloturerMission(String commentaire, String statut, Employe employe){
        JpaUtil.creerContextePersistance();
        Mission missionRetour;
        try{
            JpaUtil.ouvrirTransaction();
            missionRetour = MissionDao.chercherMissionEnCours(employe.getId());
            
            missionRetour.setCommentaire(commentaire);
            missionRetour.setDateHeureCloture(Date.from(LocalDateTime.now().atZone(ZoneId.systemDefault()).toInstant()));
            missionRetour.setStatut(statut);
            employe.setDispo(true);
            
            LatLng coordsClient = GeoNetApi.getLatLng(missionRetour.getUnClient().getAdresse());
            LatLng coordsAgence = GeoNetApi.getLatLng(employe.getAgence().getAdresseAgence());
            Double distanceParcourue = GeoNetApi.getTripDistanceByCarInKm(coordsAgence, coordsAgence, coordsClient);
            Double distanceActuel = employe.getDistanceParcourue();
            employe.setDistanceParcourue(distanceParcourue+distanceActuel);
            
            EmployeDao.modifier(employe);
            MissionDao.modifier(missionRetour);
            
            JpaUtil.validerTransaction();
            
       }catch(Exception ex){
            ex.printStackTrace();
            missionRetour = null;
        } finally{
            JpaUtil.fermerContextePersistance();
        }
       
       return missionRetour;
    }
    
    public static List<Mission> chercherMissionsClient(Long idClient){
        JpaUtil.creerContextePersistance();
        List<Mission> mRetour;
        try{
            mRetour = MissionDao.chercherMissionsClient(idClient);
        } catch (Exception ex){
            JpaUtil.annulerTransaction();
            ex.printStackTrace();
            mRetour = null;
        } finally {
            JpaUtil.fermerContextePersistance();
        }
        return mRetour;
    }
    
    public static List<Mission> chercherMissionsEmploye(Long idEmploye){
        JpaUtil.creerContextePersistance();
        List<Mission> mRetour;
        try{
            mRetour = MissionDao.chercherMissionsEmploye(idEmploye);
        } catch (Exception ex){
            JpaUtil.annulerTransaction();
            ex.printStackTrace();
            mRetour = null;
        } finally {
            JpaUtil.fermerContextePersistance();
        }
        return mRetour;
    }
}
