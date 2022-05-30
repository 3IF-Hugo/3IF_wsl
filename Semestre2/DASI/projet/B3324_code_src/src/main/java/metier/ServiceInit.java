/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package metier;

import dao.AgenceDao;
import dao.EmployeDao;
import dao.JpaUtil;
import util.GeoNetApi;

/**
 *
 * @author hgrel et mphung
 */
public class ServiceInit {

    public ServiceInit() {
    }
    
    public static void initialisation() throws Exception{
        JpaUtil.creerContextePersistance();
        
        //Agence uneAgence = new Agence("Agence1", "20 avenue Albert Einstein, Villeurbanne");
        //Agence uneAgence2 = new Agence("Agence2", "130 Bd du 11 Novembre 1918, Villeurbanne");
        Agence uneAgence3 = new Agence("Agence3", "83 Av. Roger Salengro, 69100 Villeurbanne");
        Agence uneAgence4 = new Agence("Agence4", "39 Rue Georges Courteline, 69100 Villeurbanne");
        Agence uneAgence5 = new Agence("Agence5", "6 Imp. Alexandre Dumas, 69100 Villeurbanne");
        
        Employe unEmploye = new Employe(8, 12, true, 0.0,"mdp" , "GIYRAUD", "Vincent", "vincent.giyraud@yahoo.com", "0518940604");
        Employe unEmploye2 = new Employe(10, 15, true, 0.0,"kbenj" , "KLOEN", "Benjamin", "benjamin.kloen@yahoo.com", "0220989602");
        Employe unEmploye3 = new Employe(12, 19, true, 0.0,"patit" , "PATTIT", "Philipe", "ppattit@outlook.com", "0438848608");
        Employe unEmploye4 = new Employe(14, 20, true, 0.0,"baura" , "BAURGIOOS", "Rafael", "rafael.baurgioos@hotmail.com", "0535249412");
        Employe unEmploye5 = new Employe(12, 18, true, 0.0,"mdp" , "OGARWAL", "Alexandru", "aogarwal@outlook.com", "0456231397");
        
        try{
//            setAdresse(uneAgence);
//            setAdresse(uneAgence2);
            setAdresse(uneAgence3);
            setAdresse(uneAgence4);
            setAdresse(uneAgence5);
            
            unEmploye.setAgence(uneAgence3);
            unEmploye2.setAgence(uneAgence3);
            unEmploye3.setAgence(uneAgence4);
            unEmploye4.setAgence(uneAgence5);
            unEmploye5.setAgence(uneAgence5);
            
            JpaUtil.ouvrirTransaction();
            
//            AgenceDao.creer(uneAgence);
//            AgenceDao.creer(uneAgence2);
            AgenceDao.creer(uneAgence3);
            AgenceDao.creer(uneAgence4);
            AgenceDao.creer(uneAgence5);
            
            EmployeDao.creer(unEmploye);
            EmployeDao.creer(unEmploye2);
            EmployeDao.creer(unEmploye3);
            EmployeDao.creer(unEmploye4);
            EmployeDao.creer(unEmploye5);
            
            JpaUtil.validerTransaction();
        } catch (Exception ex){
            JpaUtil.annulerTransaction();
            ex.printStackTrace();
        } finally {
            JpaUtil.fermerContextePersistance();
        }
    }
    
    public static void setAdresse(Agence uneAgence){
        Double lat1 = GeoNetApi.getLatLng(uneAgence.getAdresseAgence()).lat;
        Double lng1 = GeoNetApi.getLatLng(uneAgence.getAdresseAgence()).lng;
        uneAgence.setLatitude(lat1);
        uneAgence.setLongitude(lng1);
    }
    
}
