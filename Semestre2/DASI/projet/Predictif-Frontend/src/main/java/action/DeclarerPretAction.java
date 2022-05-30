/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package action;

import java.util.ArrayList;
import java.util.List;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import metier.modele.Consultation;
import metier.modele.Employe;
import metier.modele.Medium;
import metier.service.Service;

/**
 *
 * @author hgrel
 */
public class DeclarerPretAction extends Action{
    @Override
    public void executer(HttpServletRequest request){
        
        HttpSession session = request.getSession();
        
        String sessionUserMail = (String) session.getAttribute("mailEmploye");
        String sessionUserMdp = (String) session.getAttribute("mdpEmploye");
        
        //System.out.println("sessionUser mail  :" +sessionUserMail);
        
        Service service = new Service();
        Employe e = service.authentifierEmploye(sessionUserMail, sessionUserMdp);
        List<Consultation> l = service.consulterHistoriqueEmploye(e);
        Consultation c = null;
        for(int i = 0; i < l.size(); i++){
            if (l.get(i).getDateHeureDebutAppel() == null){
                c = l.get(i);
                break;
            }
        }
        c = service.seDeclarerPret(c);
        if (c != null){
            request.setAttribute("succes", Boolean.TRUE);
        } else {
            request.setAttribute("succes", Boolean.FALSE);
        }
    }
}
