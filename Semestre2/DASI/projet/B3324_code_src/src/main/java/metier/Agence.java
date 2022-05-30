/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package metier;

import java.util.ArrayList;
import java.util.List;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToMany;

/**
 *
 * @author hgrel
 */
@Entity
public class Agence {
    @Id
    @GeneratedValue(strategy=GenerationType.IDENTITY)
    private Long id;
    private String nomAgence;
    private String adresseAgence;
    private Double latitude;
    private Double longitude;
    
    @OneToMany (mappedBy ="agence")
    private List<Employe> listEmploye= new ArrayList<>();

    public void setListEmploye(List<Employe> listEmploye) {
        this.listEmploye = listEmploye;
    }

    public List<Employe> getListEmploye() {
        return listEmploye;
    }

    public Agence() {
    }
    
    public Agence(String nomAgence, String adresseAgence) {
        this.nomAgence = nomAgence;
        this.adresseAgence = adresseAgence;
    }

    public void setLatitude(Double latitude) {
        this.latitude = latitude;
    }

    public void setLongitude(Double longitude) {
        this.longitude = longitude;
    }

    public Double getLatitude() {
        return latitude;
    }

    public Double getLongitude() {
        return longitude;
    }

    public Long getId() {
        return id;
    }

    public String getNomAgence() {
        return nomAgence;
    }

    public String getAdresseAgence() {
        return adresseAgence;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public void setNomAgence(String nomAgence) {
        this.nomAgence = nomAgence;
    }

    public void setAdresseAgence(String adresseAgence) {
        this.adresseAgence = adresseAgence;
    }
    
    
    
    
}
