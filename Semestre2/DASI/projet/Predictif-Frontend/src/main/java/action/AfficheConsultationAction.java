/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package action;

import java.util.List;
import java.util.Objects;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import metier.modele.Consultation;
import metier.modele.Employe;
import metier.service.Service;

/**
 *
 * @author hgrel
 */
public class AfficheConsultationAction extends Action{
    @Override
    public void executer(HttpServletRequest request){
        HttpSession session = request.getSession();
        
        String sessionUserMail = (String) session.getAttribute("mailEmploye");
        String sessionUserMdp = (String) session.getAttribute("mdpEmploye");
        
        //System.out.println("sessionUser mail  :" +sessionUserMail);
        
        Service service = new Service();
        Employe e = service.authentifierEmploye(sessionUserMail, sessionUserMdp);
        List<Consultation> l = service.consulterHistoriqueEmploye(e);
        if(Objects.equals(e.getDisponibilite(), Boolean.FALSE)){
            Consultation c = null;
            for(int i = 0; i < l.size(); i++){
                if (l.get(i).getDateHeureFinAppel() == null)
                {
                    c = l.get(i);
                    System.out.println(c);
                    break;
                }
            }
            request.setAttribute("Consultation", c);
            request.setAttribute("Disponible", Boolean.FALSE);

        } else {
            request.setAttribute("Disponible", Boolean.TRUE);
        }
        
        
    }
}
