/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package action;

import static java.lang.Integer.parseInt;
import java.util.List;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import metier.modele.Client;
import metier.modele.Consultation;
import metier.modele.Medium;
import metier.service.Service;

/**
 *
 * @author hgrel
 */
public class ReserverMediumAction extends Action{
    @Override
    public void executer(HttpServletRequest request){
        HttpSession session = request.getSession();
        
        String sessionUserMail = (String) session.getAttribute("mailClient");
        String sessionUserMdp = (String) session.getAttribute("mdpClient");
        
        //System.out.println("sessionUser mail  :" +sessionUserMail);
        
        Service service = new Service();
        Client client = service.authentifierClient(sessionUserMail, sessionUserMdp);
        List<Medium> listMedium = service.consulterListeMedium();
        String idMString = (String) request.getParameter("index");
        int idM = parseInt(idMString, 10);
        Medium m = listMedium.get(idM);
        Consultation c = service.creerConsultation(client, m);
        if (c!= null){
            request.setAttribute("succes", Boolean.TRUE);
        } else {
            request.setAttribute("succes", Boolean.FALSE);
        }
    }
}
