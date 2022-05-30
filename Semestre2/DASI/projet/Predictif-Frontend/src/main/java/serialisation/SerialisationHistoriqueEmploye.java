/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package serialisation;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.reflect.TypeToken;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import metier.modele.Consultation;

/**
 *
 * @author mphung
 */
public class SerialisationHistoriqueEmploye extends Serialisation {
    @Override
    public void serialiser(HttpServletRequest request, HttpServletResponse response)throws IOException{
        JsonObject jsonClient = new JsonObject();
        List<Consultation> listConsultation = (List<Consultation>) request.getAttribute("listConsultation");
        List<String> listDenomination = (List<String>) request.getAttribute("listDenomination");
        Gson gson = new Gson();
        System.out.println("Je suis la ");
        JsonElement elementList = gson.toJsonTree(listConsultation, new TypeToken<List<Consultation>>() {}.getType());
        JsonElement elementDenomList = gson.toJsonTree(listDenomination, new TypeToken<List<String>>() {}.getType());
        System.out.println("Je suis ici ");
        //System.out.println(elementList);
        jsonClient.add("listConsultation", elementList);
        jsonClient.add("listDenomination", elementDenomList);
        PrintWriter out = this.getWriter(response);
        Gson gsonBuilder = new GsonBuilder().setPrettyPrinting().create();
        gsonBuilder.toJson(jsonClient, out);
        //System.out.println(gsonBuilder.toJson(jsonClient));
        out.close();

    }
}
