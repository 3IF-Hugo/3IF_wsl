/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.TypedQuery;
import metier.Client;

/**
 *
 * @author hgrel
 */
public class ClientDao {
    public static void creer(Client client){
        JpaUtil.obtenirContextePersistance().persist(client);
    }
    
    public static Client chercherParId(Long clientId) {
        return JpaUtil.obtenirContextePersistance().find(Client.class, clientId); // renvoie null si l'identifiant n'existe pas
    }
    
    public static List<Client> listerTousClients(){
        EntityManager em = JpaUtil.obtenirContextePersistance();
        TypedQuery<Client> typedQuery = em.createQuery("select c from Client c Order by c.nom asc, c.prenom asc", Client.class);
        return typedQuery.getResultList();
    }
    
    
    public static Client chercherParMail(String mail){
        Client client;
        EntityManager em = JpaUtil.obtenirContextePersistance();
        String query = "select c from Client c WHERE c.mail= :mail";
        TypedQuery<Client> typedQuery = em.createQuery(query, Client.class);
        typedQuery.setParameter("mail", mail);
        client = (Client) typedQuery.getSingleResult();
        return client;
    }
}
