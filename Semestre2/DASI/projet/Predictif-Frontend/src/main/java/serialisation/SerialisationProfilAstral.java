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
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import metier.modele.Client;

/**
 *
 * @author hgrel
 */
public class SerialisationProfilAstral extends Serialisation{
    @Override
    public void serialiser(HttpServletRequest request, HttpServletResponse response)throws IOException{
        JsonObject jsonClient = new JsonObject();
        Client client = (Client) request.getAttribute("Client");
        
        jsonClient.addProperty("zodiaque", client.getProfilAstral().getZodiaque());
        jsonClient.addProperty("astro", client.getProfilAstral().getAstroChinois());
        jsonClient.addProperty("animal", client.getProfilAstral().getAnimalTotem());
        jsonClient.addProperty("couleur", client.getProfilAstral().getCouleurPB());
        
        PrintWriter out = this.getWriter(response);
        Gson gsonBuilder = new GsonBuilder().setPrettyPrinting().create();
        gsonBuilder.toJson(jsonClient, out);
        System.out.println(gsonBuilder.toJson(jsonClient));
        out.close();

    }
}
