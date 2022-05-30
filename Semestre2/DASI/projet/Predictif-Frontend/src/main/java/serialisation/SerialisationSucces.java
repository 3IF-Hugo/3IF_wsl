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

/**
 *
 * @author hgrel
 */
public class SerialisationSucces extends Serialisation{
    @Override
    public void serialiser(HttpServletRequest request, HttpServletResponse response)throws IOException{
        JsonObject jsonClient = new JsonObject();
        
        if(request.getAttribute("succes") == Boolean.TRUE){
            jsonClient.addProperty("succes", Boolean.TRUE);
        }else{
            jsonClient.addProperty("succes", Boolean.FALSE);
        }
                
        PrintWriter out = this.getWriter(response);
        Gson gsonBuilder = new GsonBuilder().setPrettyPrinting().create();
        gsonBuilder.toJson(jsonClient, out);
        out.close();
    }
}
