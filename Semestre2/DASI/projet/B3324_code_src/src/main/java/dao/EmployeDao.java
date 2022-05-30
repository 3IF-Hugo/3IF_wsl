/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import javax.persistence.EntityManager;
import javax.persistence.TypedQuery;
import metier.Agence;
import metier.Client;
import metier.Employe;

/**
 *
 * @author hgrel et mphung
 */
public class EmployeDao {
    public static void creer(Employe employe){
        JpaUtil.obtenirContextePersistance().persist(employe);
    }
    
    public static void modifier(Employe employe){
        JpaUtil.obtenirContextePersistance().merge(employe);
    }
    
    public static Employe chercherParMail(String mail){
        Employe employe;
        EntityManager em = JpaUtil.obtenirContextePersistance();
        String query = "select e from Employe e WHERE e.mail= :mail";
        TypedQuery<Employe> typedQuery = em.createQuery(query, Employe.class);
        typedQuery.setParameter("mail", mail);
        employe = (Employe) typedQuery.getSingleResult();
        return employe;
    }
    
    public static Employe chercherEmployeDispo(Agence uneAgence, int heureActuelle){
        Employe employe;
        EntityManager em = JpaUtil.obtenirContextePersistance();
        String query = "select e from Employe e WHERE e.agence= :uneAgence AND e.dispo = 1 AND e.heureDeb<=:heureActuelle AND e.heureFin>:heureActuelle";
        TypedQuery<Employe> typedQuery = em.createQuery(query, Employe.class);
        typedQuery.setParameter("uneAgence", uneAgence);
        typedQuery.setParameter("heureActuelle", heureActuelle);
        
        if(typedQuery.getResultList().isEmpty()){
            employe = null;
        }else{
            employe = (Employe) typedQuery.getResultList().get(0);
        }
        return employe;
    }
    
    // Cette methode est seulement pour obtenir un Employe pour le test
    public static Employe chercherEmployeEnCoursMission(){
        Employe employe;
        JpaUtil.creerContextePersistance();
        EntityManager em = JpaUtil.obtenirContextePersistance();
        String query = "select e from Employe e WHERE e.dispo = 0";
        TypedQuery<Employe> typedQuery = em.createQuery(query, Employe.class);
        
        if(typedQuery.getResultList().isEmpty()){
            employe = (Employe) null;
        }else{
            employe = (Employe)  typedQuery.getResultList().get(0);
        }
        return employe;
    }
}
