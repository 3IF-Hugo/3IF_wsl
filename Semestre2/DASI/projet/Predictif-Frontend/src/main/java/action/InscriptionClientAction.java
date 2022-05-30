/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package action;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.http.HttpServletRequest;
import metier.modele.Client;
import metier.service.Service;

/**
 *
 * @author hgrel
 */
public class InscriptionClientAction extends Action {
    @Override
    public void executer(HttpServletRequest request){
        String civ = request.getParameter("civ");
        String nom = request.getParameter("nom");
        String prenom = request.getParameter("prenom");
        String ddn = request.getParameter("ddn");
        String tele = request.getParameter("tele");
        String mail = request.getParameter("mail");
        String mdp = request.getParameter("password");
        String confMdp = request.getParameter("conf_password");
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        Date date;
        try {
            date = formatter.parse(ddn);
            Service service = new Service();
            if(mdp.equals(confMdp)){
                Client client = service.inscrireClient(new Client(civ, nom, prenom, date, tele, mail, mdp));
                if(client != null){
                    request.setAttribute("succes", Boolean.TRUE);
                }else{
                    request.setAttribute("succes", Boolean.FALSE);
                }
            } else {
                request.setAttribute("succes", Boolean.FALSE);
            }
            
        } catch (ParseException ex) {
            Logger.getLogger(InscriptionClientAction.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
