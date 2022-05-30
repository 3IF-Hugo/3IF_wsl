/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package metier;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.ManyToOne;

/**
 *
 * @author hgrel
 */
@Entity
public class Employe {
    
    @ManyToOne
    private Agence agence;
    
    @Id
    @GeneratedValue(strategy=GenerationType.IDENTITY)
    private Long id;
    private int heureDeb;
    private int heureFin;
    private boolean dispo;
    private Double distanceParcourue;
    private String motDePasse;
    
    private String nom;
    private String prenom;
    @Column(unique=true)
    private String mail;
    private String numTelephone;

    public Employe() {
    }

    public Employe(int heureDeb, int heureFin, boolean dispo, Double distanceParcourue, String motDePasse, String nom, String prenom, String mail, String numTelephone) {
        //this.agence = uneAgence;
        this.heureDeb = heureDeb;
        this.heureFin = heureFin;
        this.dispo = dispo;
        this.distanceParcourue = distanceParcourue;
        this.motDePasse = motDePasse;
        this.nom = nom;
        this.prenom = prenom;
        this.mail = mail;
        this.numTelephone = numTelephone;
    }

    public void setAgence(Agence agence) {
        this.agence = agence;
        this.agence.getListEmploye().add(this);
    }

    public Agence getAgence() {
        return agence;
    }

    public Long getId() {
        return id;
    }

    public int getHeureDeb() {
        return heureDeb;
    }

    public int getHeureFin() {
        return heureFin;
    }

    public boolean isDispo() {
        return dispo;
    }

    public Double getDistanceParcourue() {
        return distanceParcourue;
    }

    public String getMotDePasse() {
        return motDePasse;
    }

    public String getNom() {
        return nom;
    }

    public String getPrenom() {
        return prenom;
    }

    public String getMail() {
        return mail;
    }

    public String getNumTelephone() {
        return numTelephone;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public void setHeureDeb(int heureDeb) {
        this.heureDeb = heureDeb;
    }

    public void setHeureFin(int heureFin) {
        this.heureFin = heureFin;
    }

    public void setDispo(boolean dispo) {
        this.dispo = dispo;
    }

    public void setDistanceParcourue(Double distanceParcourue) {
        this.distanceParcourue = distanceParcourue;
    }

    public void setMotDePasse(String motDePasse) {
        this.motDePasse = motDePasse;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }

    public void setMail(String mail) {
        this.mail = mail;
    }

    public void setNumTelephone(String numTelephone) {
        this.numTelephone = numTelephone;
    }
    
    
    
    
}
