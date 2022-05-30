/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.util.Calendar;
import java.util.Date;
import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.TypedQuery;
import metier.Agence;
import metier.Client;
import metier.Employe;
import metier.Mission;

/**
 *
 * @author hgrel
 */
public class MissionDao {
    
    public static void creer(Mission mission){
        JpaUtil.obtenirContextePersistance().persist(mission);
    }
    
    public static void modifier(Mission mission){
        JpaUtil.obtenirContextePersistance().merge(mission);
    }
    
    public static Mission chercherMissionEnCours(Long idEmploye){
        Mission mission;
        EntityManager em = JpaUtil.obtenirContextePersistance();
        String query = "select m from Mission m WHERE m.unEmploye.id = :idEmploye AND m.statut IS NULL";
        TypedQuery<Mission> typedQuery = em.createQuery(query, Mission.class);
        typedQuery.setParameter("idEmploye", idEmploye);
        
        if(typedQuery.getResultList().isEmpty()){
            mission = null;
        }else{
            mission = (Mission) typedQuery.getSingleResult();
        }
        return mission;
    }
    
    public static List<Mission> chercherMissionsClient (Long idClient){
        List<Mission> historique;
        JpaUtil.creerContextePersistance();
        EntityManager em = JpaUtil.obtenirContextePersistance();
        String query = "select m from Mission m WHERE m.unClient.id = :idClient AND m.statut IS NOT NULL ORDER BY m.id DESC";
        TypedQuery<Mission> typedQuery = em.createQuery(query, Mission.class);
        typedQuery.setParameter("idClient", idClient);
        historique = (List<Mission>) typedQuery.getResultList();
        return historique;
    }
    
    public static List<Mission> chercherMissionsEmploye (Long idEmploye) throws ParseException {
        List<Mission> historique;
        Calendar calendar = Calendar.getInstance();
        SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");
        String strDate = dateFormat.format(calendar.getTime());
        Date aujourdhui = dateFormat.parse(strDate);
        calendar.add(Calendar.DATE, 1);
        strDate = dateFormat.format(calendar.getTime());
        Date demain = dateFormat.parse(strDate);
        
        JpaUtil.creerContextePersistance();
        EntityManager em = JpaUtil.obtenirContextePersistance();
        String query = "select m from Mission m WHERE m.unEmploye.id = :idEmploye AND m.statut IS NOT NULL AND m.dateHeureDemande BETWEEN :start AND :end ORDER BY m.id DESC";
        TypedQuery<Mission> typedQuery = em.createQuery(query, Mission.class);
        typedQuery.setParameter("idEmploye", idEmploye);
        typedQuery.setParameter("start", aujourdhui);
        typedQuery.setParameter("end", demain);
        historique = (List<Mission>) typedQuery.getResultList();
        return historique;
    }
}
