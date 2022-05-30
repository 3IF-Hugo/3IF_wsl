/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import action.Action;
import action.AfficheConsultationAction;
import action.AuthentifierEmployeAction;
import action.AuthentifierUtilisateurAction;
import action.ConsulterHistoriqueClientAction;
import action.ConsulterHistoriqueEmployeAction;
import action.ConsulterMediumAction;
import action.ConsulterProfilAstralAction;
import action.DeclarerPretAction;
import action.DeconnecterAction;
import action.DemarrerAction;
import action.GenererPredictionAction;
import action.InscriptionClientAction;
import action.ReserverMediumAction;
import action.TerminerConsultationAction;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import com.google.gson.JsonObject;
import com.google.gson.GsonBuilder;
import com.google.gson.Gson;
import dao.JPaUtil;
import javax.servlet.http.HttpSession;
import serialisation.Serialisation;
import serialisation.SerialisationAfficheConsultation;
import serialisation.SerialisationHistoriqueClient;
import serialisation.SerialisationHistoriqueEmploye;
import serialisation.SerialisationMedium;
import serialisation.SerialisationPrediction;
import serialisation.SerialisationProfilAstral;
import serialisation.SerialisationSucces;

/**
 *
 * @author hgrel
 */
@WebServlet(urlPatterns = {"/ActionServlet"})
public class ActionServlet extends HttpServlet {
    String json;
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        HttpSession session = request.getSession(true);
        
        response.setContentType("text/html;charset=UTF-8");
        String todo = request.getParameter("todo");
        System.out.println("todo " + todo);
        Action action = null;
        Serialisation serialisation = null;
        switch(todo){
            case "connecterClient":{
                action = new AuthentifierUtilisateurAction();
                serialisation = new SerialisationSucces();
            }
            break;
            
            case "connecterEmploye":{
                action = new AuthentifierEmployeAction();
                serialisation = new SerialisationSucces();
            }
            break;
            
            case "inscription":{
                action = new InscriptionClientAction();
                serialisation = new SerialisationSucces();
            }
            break;
            
            case "profilAstral":{          
                action = new ConsulterProfilAstralAction();
                serialisation = new SerialisationProfilAstral();
            }
            break;
            
            case "consulter-medium":{          
                action = new ConsulterMediumAction();
                serialisation = new SerialisationMedium();
            }
            break;
            
            case "reserver":{          
                action = new ReserverMediumAction();
                serialisation = new SerialisationSucces();
            }
            break;
            
            case "afficheConsultation":{          
                action = new AfficheConsultationAction();
                serialisation = new SerialisationAfficheConsultation();
            }
            break;
            
            case "declarerPret":{          
                action = new DeclarerPretAction();
                serialisation = new SerialisationSucces();
            }
            break;
            
            case "demarrer":{          
                action = new DemarrerAction();
                serialisation = new SerialisationSucces();
            }
            break;
            
            case "generer":{          
                action = new GenererPredictionAction();
                serialisation = new SerialisationPrediction();
            }
            break;
            
            case "terminer":{          
                action = new TerminerConsultationAction();
                serialisation = new SerialisationSucces();
            }
            break;
            
            case "deconnecter":{
                action = new DeconnecterAction();
                serialisation = new SerialisationSucces();
            }
            break;
            
            case "consulter-historique-client":{
                action = new ConsulterHistoriqueClientAction();
                serialisation = new SerialisationHistoriqueClient();
            }
            break;
            
            case "consulter-historique-employe":{
                action = new ConsulterHistoriqueEmployeAction();
                serialisation = new SerialisationHistoriqueEmploye();
            }
            break;
        }
        
        if (action != null && serialisation != null){
            action.executer(request);
            serialisation.serialiser(request, response);
        } else {
            response.sendError(400, "Bad Request");
        }
                
//        if("connecter".equals(todo)){
//            String login = request.getParameter("login");
//            String password = request.getParameter("password");
//
//            Service service = new Service();
//            Client client = service.authentifierClient(login, password);
//            System.out.println(client);
//            JsonObject jsonClient = new JsonObject();
//            JsonObject jsonInfos = new JsonObject();
//                        
//            if(client != null){
//                //générer JSON true
//                jsonClient.addProperty("connexion", Boolean.TRUE);
//                
//                jsonInfos.addProperty("id", client.getId());
//                jsonInfos.addProperty("nom", client.getNom());
//                jsonInfos.addProperty("prenom", client.getPrenom());
//                jsonInfos.addProperty("mail", client.getMail());
//                
//                jsonClient.add("client", jsonInfos);
//            }else{
//                //générer JSON false
//                jsonClient.addProperty("connexion", Boolean.FALSE);
//            }
//            Gson gsonBuilder = new GsonBuilder().create();
//            json = gsonBuilder.toJson(jsonClient);
//        }
        
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            //out.println(json);
//            out.println("<!DOCTYPE html>");
//            out.println("<html>");
//            out.println("<head>");
//            out.println("<title>Servlet ActionServlet</title>");            
//            out.println("</head>");
//            out.println("<body>");
//            out.println("<h2>Servlet ActionServlet at " + request.getContextPath() + "</h2>");
//            out.println("<p>"+json+"</p>");
//            out.println("</body>");
//            out.println("</html>");
        }
    }
    
    @Override
  public void init() throws ServletException {
    super.init();
    JPaUtil.init();
  }

  @Override
  public void destroy() {
    JPaUtil.destroy();
    super.destroy();
  }
    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
