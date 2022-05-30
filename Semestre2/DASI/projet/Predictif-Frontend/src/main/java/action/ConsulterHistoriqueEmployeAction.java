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
import metier.modele.Client;
import metier.modele.Consultation;
import metier.modele.Employe;
import metier.service.Service;

/**
 *
 * @author mphung
 */
public class ConsulterHistoriqueEmployeAction extends Action{
    @Override
    public void executer(HttpServletRequest request){
        HttpSession session = request.getSession();
        
        String sessionUserMail = (String) session.getAttribute("mailEmploye");
        String sessionUserMdp = (String) session.getAttribute("mdpEmploye");
        
        Service service = new Service();
        Employe employe = service.authentifierEmploye(sessionUserMail, sessionUserMdp);
        List<Consultation> listConsultation = service.consulterHistoriqueEmploye(employe);
        List<String> listDenomination = new ArrayList<>();
        for(int i = 0; i < listConsultation.size(); i++){
            listDenomination.add(listConsultation.get(i).getMedium().getDenomination());
        }
        request.setAttribute("listConsultation", listConsultation);
        request.setAttribute("listDenomination", listDenomination);
    }
}
