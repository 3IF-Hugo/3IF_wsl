/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.TypedQuery;
import metier.Agence;

/**
 *
 * @author hgrel
 */
public class AgenceDao {
    public static void creer(Agence agence){
        JpaUtil.obtenirContextePersistance().persist(agence);
    }
    
    public static List<Agence> listerTousAgences(){
        EntityManager em = JpaUtil.obtenirContextePersistance();
        TypedQuery<Agence> typedQuery = em.createQuery("select a from Agence a", Agence.class);
        return typedQuery.getResultList();
    }
    // lister une seule agence
    
    public static void 
    
}
