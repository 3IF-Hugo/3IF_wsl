/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ihm;

//@author Hugo Grel et Minh Phung

import dao.EmployeDao;
import util.GeoNetApi;
import dao.JpaUtil;
import metier.Client;
import metier.Service;
import static dao.JpaUtil.init;
import dao.MissionDao;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.Persistence;
import util.Message;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import metier.Agence;
import metier.Animal;
import metier.Employe;
import metier.Livraison;
import metier.Mission;
import metier.ServiceInit;

enum TypeIntervention {Livraison, Animal, Incident};  

/**
 *
 * @author hgrel
 */
public class Main {
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        JpaUtil.init();
        
        Client unClient = testerInscriptionClient();
        
        creerAgenceEtEmployes();
        
        AuthentificationEmploye();
        
        AuthentificationClient();
        
        demandeIntervention(unClient);
        
        Employe employeEnCours = EmployeDao.chercherEmployeEnCoursMission();
        
        cloturerMission(employeEnCours);
        
        employeEnCours = EmployeDao.chercherEmployeEnCoursMission();
        
        cloturerMission(employeEnCours);
        
        afficherHistoriqueClient(unClient);
        
        afficherHistoriqueEmploye(employeEnCours);
    }
    
    public static Client testerInscriptionClient() throws Exception{
        System.out.println("////////////////////////////////////////////////////////////////////////////////////////");
        System.out.println("Inscription du Client");
        System.out.println("---------------------");
        
        String adresse = "10 Rue Eugene Fourniere, Villeurbanne";
        String dateStr = "24/12/2000";
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        Date date = formatter.parse(dateStr);
        Client unClient = new Client("VILLEN", "Ali", "ali.villen@hotmail.com", "0269635308", date, adresse, "toto");
       
        Client retour = Service.inscrireClient(unClient);
        
        if(retour != null){
            Message.envoyerMail(
                "contact@react.if", 
                retour.getMail(),
                "Bienvenue chez REACT'IF",
                "Bonjour "+ retour.getPrenom()+", nous vous confirmons votre inscription au service REACT'IF. "
                        + "Un cas d'urgence? Rendez-vous vite sur notre site; vous pouvez compter "
                        + "sur nous pour résoudre votre problème avec rapidité et efficacité.");
        }else {
            Message.envoyerMail(
                "contact@react.if",
                retour.getMail(),
                "Echec de l'inscription chez REACT'IF",
                "Bonjour "+ retour.getPrenom()+", votre inscription au service REAT'IF a malencontreusement échoué... Merci de recommencer ultérieurement.");
        }
        System.out.println();
        return retour;
    }
    
    public static void creerAgenceEtEmployes() throws Exception{
        System.out.println("////////////////////////////////////////////////////////////////////////////////////////");
        System.out.println("Création des 5 agences et des 5 employés");
        System.out.println("-----------------------------------------");
        
        ServiceInit.initialisation();
    }
    
    public static void AuthentificationClient(){
        System.out.println("////////////////////////////////////////////////////////////////////////////////////////");
        System.out.println("Authentification du Client");
        System.out.println("---------------------------");
        
        Client clientRetour;
        String mdp = "toto";
        String mail = "ali.villen@hotmail.com";
        
        clientRetour = Service.authentifierClient(mail, mdp);
        
        if(clientRetour != null){
            System.out.println("> Succès Authentification, l'utilisateur " + mail + " est authentifié");
            System.out.println(clientRetour);
        }else {
            System.out.println("> Echec Authentification, le mail et/ou le mot de passe est invalide");
            System.out.println("Mail renseigné : " + mail + " et le mot de passe renseigné : " + mdp);
        }
        System.out.println("");
        System.out.println();
    }
    
    public static void AuthentificationEmploye(){
        System.out.println("////////////////////////////////////////////////////////////////////////////////////////");
        System.out.println("Authentification de l'Employe");
        System.out.println("------------------------------");
        
        Employe employeRetour;
        String mdp = "patit";
        String mail = "ppattit@outlook.com";
        
        employeRetour = Service.authentifierEmploye(mail, mdp);
        
        if(employeRetour != null){
            System.out.println("> Succès Authentification, l'employé " + employeRetour.getMail() + " est authentifié");
            System.out.println(employeRetour);
        }else {
            System.out.println("> Echec Authentification, le mail et/ou le mot de passe est invalide");
            System.out.println("Mail renseigné : " + employeRetour.getMail() + " et le mot de passe renseigné : " + mdp);
        }
        System.out.println("");
        System.out.println();
    }
    
    public static void demandeIntervention(Client client){
        System.out.println("////////////////////////////////////////////////////////////////////////////////////////");
        System.out.println("Demande d'intervention");
        System.out.println("-----------------------");
        
        String objet1 = "Un canapé";
        String entreprise = "LEROYMERLIN";
        String description = "Merci de receptionner mon meuble.";
        
        Livraison uneLivraison = new Livraison(objet1, entreprise, description);
        
        Mission missionRetour = Service.creerDemande(uneLivraison, client);
        
        if(missionRetour != null){
           System.out.println("> Succès de la création de la demande, l'employé qui s'en charge est : "+ missionRetour.getUnEmploye().getPrenom());
           StringWriter message = new StringWriter();
            
           PrintWriter notificationWriter = new PrintWriter(message);
           
            Date date = missionRetour.getDateHeureDemande();
            SimpleDateFormat formatter = new SimpleDateFormat("HH'h'mm");
            String heure = formatter.format(date);
           
            notificationWriter.println("Bonjour "+missionRetour.getUnEmploye().getPrenom()+". "
                    + "Merci de prendre en charge l'intervention \""+ missionRetour.getClass().getSimpleName()+"\" demandée à "+heure+" par "+
                    missionRetour.getUnClient().getPrenom() + " "+ missionRetour.getUnClient().getNom().toUpperCase()+" "+ missionRetour.getUnClient().getAdresse()+".");

            Message.envoyerNotification(
                    missionRetour.getUnEmploye().getNumTelephone(),
                    message.toString()
                );
        }else{
            System.out.println("> Echec de la création de la demande, aucun employé disponible");
        }
        
        System.out.println();
        System.out.println("Deuxième mission");
        
        String objet2 = "Chien";
        String description2 = "Merci de promener mon chien.";
        
        Animal unAnimal = new Animal(objet2, description2);
        
        Mission missionRetour2 = Service.creerDemande(unAnimal, client);
        
        if(missionRetour2 != null){
           System.out.println("> Succès de la création de la demande, l'employé qui s'en charge est : "+ missionRetour2.getUnEmploye().getPrenom());
        StringWriter message = new StringWriter();
            
           PrintWriter notificationWriter = new PrintWriter(message);
           
            Date date = missionRetour2.getDateHeureDemande();
            SimpleDateFormat formatter = new SimpleDateFormat("HH'h'mm");
            String heure = formatter.format(date);
           
            notificationWriter.println("Bonjour "+missionRetour2.getUnEmploye().getPrenom()+". "
                    + "Merci de prendre en charge l'intervention \""+ missionRetour2.getClass().getSimpleName()+"\" demandée à "+heure+" par "+
                    missionRetour2.getUnClient().getPrenom() + " "+ missionRetour2.getUnClient().getNom().toUpperCase()+" "+ missionRetour2.getUnClient().getAdresse()+".");

            Message.envoyerNotification(
                    missionRetour2.getUnEmploye().getNumTelephone(),
                    message.toString()
                );
        }else{
            System.out.println("> Echec de la création de la demande, aucun employé de disponible");
        }
        System.out.println();
    }
    
    public static void cloturerMission(Employe employe){
        System.out.println("////////////////////////////////////////////////////////////////////////////////////////");
        System.out.println("Clôture de la Mission");
        System.out.println("----------------------");
                
        String commentaire = "Tout est ok !";
        String statut = "Succès";
        
        Mission missionRetour = Service.cloturerMission(commentaire, statut, employe);
        
        if(missionRetour != null){
            StringWriter message = new StringWriter();
            
           PrintWriter notificationWriter = new PrintWriter(message);
           
           Date date = missionRetour.getDateHeureDemande();
            SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy 'à' HH'h'mm");
            String dateEtHeure = formatter.format(date);
            
            Date date2 = missionRetour.getDateHeureCloture();
            SimpleDateFormat formatter2 = new SimpleDateFormat("HH'h'mm");
            String heureRetour = formatter2.format(date2);
           
            notificationWriter.println("Bonjour "+missionRetour.getUnClient().getPrenom()+". " 
                    + "Votre demande d'intervention du "+ dateEtHeure +" a été cloturé à "+heureRetour+". "+ missionRetour.getCommentaire()+" Cordialement, "
                    + missionRetour.getUnEmploye().getPrenom() + ".");
            
            Message.envoyerNotification(
                    missionRetour.getUnEmploye().getNumTelephone(),
                    message.toString()
                );
        }
        System.out.println();
    }
    
    public static void afficherHistoriqueClient(Client client){
        System.out.println("////////////////////////////////////////////////////////////////////////////////////////");
        System.out.println("Affichage de l'historique du Client");
        System.out.println("------------------------------------");
        System.out.println();
        System.out.println("Historique des missions de client "+ client.getPrenom() +":");
        System.out.println();
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy HH'h'mm");
        List<Mission> historique = Service.chercherMissionsClient(client.getId());
        for (int i = 0; i < historique.size(); i++){
            System.out.println("----- " + historique.get(i).getClass().getSimpleName() + " -----");
            System.out.println("Date de creation : " + formatter.format(historique.get(i).getDateHeureDemande()));
            System.out.println("Date de cloture : " + formatter.format(historique.get(i).getDateHeureCloture()));
            System.out.println("Employe en charge : " + historique.get(i).getUnEmploye().getPrenom() + " " + historique.get(i).getUnEmploye().getNom().toUpperCase());
            System.out.println("Statut : " + historique.get(i).getStatut());
            System.out.println("Description : " + historique.get(i).getDescription());
            System.out.println("----- Fin de " + historique.get(i).getClass().getSimpleName() + " -----");
            System.out.println();
        }
        System.out.println();
    }
    
    public static void afficherHistoriqueEmploye(Employe employe) throws ParseException{
        System.out.println("////////////////////////////////////////////////////////////////////////////////////////");
        System.out.println("Affichage de l'historique de l'Employe");
        System.out.println("--------------------------------------");
        if(employe != null){
            System.out.println();
            System.out.println("Historique des missions de l'employe "+ employe.getPrenom() +":");
            System.out.println();
            SimpleDateFormat formatter = new SimpleDateFormat("HH:mm");
            List<Mission> historique = Service.chercherMissionsEmploye(employe.getId());
            for (int i = 0; i < historique.size(); i++){
                System.out.println("----- " + historique.get(i).getClass().getSimpleName() + " -----");
                System.out.println("Heure de cloture : " + formatter.format(historique.get(i).getDateHeureCloture()));
                System.out.println("Statut : " + historique.get(i).getStatut());
                System.out.println("Description : " + historique.get(i).getDescription());
                System.out.println("----- Fin de " + historique.get(i).getClass().getSimpleName() + " -----");
                System.out.println();
            }
            System.out.println("----- Fin de historique -----");
            System.out.println("Distance total parcourue par l'employé aujourd'hui : " + employe.getDistanceParcourue());
        }else{
            System.out.println("Aucun employé sélectionné");
        }
    }
}