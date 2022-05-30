/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package serialisation;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.reflect.TypeToken;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import metier.modele.Medium;

/**
 *
 * @author hgrel
 */
public class SerialisationMedium extends Serialisation{
    @Override
    public void serialiser(HttpServletRequest request, HttpServletResponse response)throws IOException{
        JsonObject jsonClient = new JsonObject();
        List<Medium> listMedium = (List<Medium>) request.getAttribute("listMedium");
        List<String> typeMedium = (List<String>) request.getAttribute("typeMedium");
        Gson gson = new Gson();
        System.out.println("Je suis la ");
        JsonElement elementList = gson.toJsonTree(listMedium, new TypeToken<List<Medium>>() {}.getType());
        System.out.println("Je suis ici ");
        JsonElement elementType = gson.toJsonTree(typeMedium, new TypeToken<List<String>>() {}.getType());
        //System.out.println(elementList);
        jsonClient.add("listMedium", elementList);
        jsonClient.add("typeMedium", elementType);
        
        PrintWriter out = this.getWriter(response);
        Gson gsonBuilder = new GsonBuilder().setPrettyPrinting().create();
        gsonBuilder.toJson(jsonClient, out);
        //System.out.println(gsonBuilder.toJson(jsonClient));
        out.close();

    }
}
