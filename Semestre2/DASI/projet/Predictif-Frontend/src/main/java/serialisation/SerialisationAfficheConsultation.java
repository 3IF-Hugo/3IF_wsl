/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package serialisation;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonObject;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Objects;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import metier.modele.Consultation;

/**
 *
 * @author hgrel
 */
public class SerialisationAfficheConsultation extends Serialisation{
    @Override
    public void serialiser(HttpServletRequest request, HttpServletResponse response)throws IOException{
        JsonObject jsonClient = new JsonObject();
        Boolean disponible = (Boolean) request.getAttribute("Disponible");
        if(Objects.equals(disponible, Boolean.FALSE)){
            Consultation c = (Consultation) request.getAttribute("Consultation");
            jsonClient.addProperty("succes", Boolean.TRUE);
            jsonClient.addProperty("Medium", c.getMedium().getDenomination());
            jsonClient.addProperty("Consultation", c.getNumero());
            jsonClient.addProperty("zodiaque", c.getClient().getProfilAstral().getZodiaque());
            jsonClient.addProperty("animal", c.getClient().getProfilAstral().getAnimalTotem());
            jsonClient.addProperty("astro", c.getClient().getProfilAstral().getAstroChinois());
            jsonClient.addProperty("couleur", c.getClient().getProfilAstral().getCouleurPB());
        } else {
            jsonClient.addProperty("succes", Boolean.FALSE);
        }
        PrintWriter out = this.getWriter(response);
        Gson gsonBuilder = new GsonBuilder().setPrettyPrinting().create();
        gsonBuilder.toJson(jsonClient, out);
        System.out.println(gsonBuilder.toJson(jsonClient));
        out.close();
    }
}
