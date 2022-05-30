/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package metier;

import java.util.Date;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.ManyToOne;
import javax.persistence.Temporal;

/**
 *
 * @author hgrel
 */
@Entity
public abstract class Mission {
    @ManyToOne
    private Employe unEmploye;
    
    @ManyToOne
    private Client unClient;
    
    @Id
    @GeneratedValue(strategy=GenerationType.IDENTITY)
    private Long id;
    private String description;
    private String commentaire;
    private String statut;
    
    @Temporal(javax.persistence.TemporalType.TIMESTAMP)
    private Date dateHeureDemande;
    @Temporal(javax.persistence.TemporalType.TIMESTAMP)
    private Date dateHeureCloture;
    
    public Mission() {
    }
     
    public Mission(String description) {
        this.description = description;
    }

    public void setUnEmploye(Employe unEmploye) {
        this.unEmploye = unEmploye;
    }

    public void setUnClient(Client unClient) {
        this.unClient = unClient;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setCommentaire(String commentaire) {
        this.commentaire = commentaire;
    }

    public void setStatut(String statut) {
        this.statut = statut;
    }

    public void setDateHeureDemande(Date dateHeureDemande) {
        this.dateHeureDemande = dateHeureDemande;
    }

    public void setDateHeureCloture(Date dateHeureCloture) {
        this.dateHeureCloture = dateHeureCloture;
    }

    public Employe getUnEmploye() {
        return unEmploye;
    }

    public Client getUnClient() {
        return unClient;
    }

    public Long getId() {
        return id;
    }

    public String getDescription() {
        return description;
    }

    public String getCommentaire() {
        return commentaire;
    }

    public String getStatut() {
        return statut;
    }

    public Date getDateHeureDemande() {
        return dateHeureDemande;
    }

    public Date getDateHeureCloture() {
        return dateHeureCloture;
    }    
}
