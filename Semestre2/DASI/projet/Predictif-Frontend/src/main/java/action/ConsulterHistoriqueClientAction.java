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
import metier.service.Service;

/**
 *
 * @author mphung
 */
public class ConsulterHistoriqueClientAction extends Action {
    @Override
    public void executer(HttpServletRequest request){
        HttpSession session = request.getSession();
        
        String sessionUserMail = (String) session.getAttribute("mailClient");
        String sessionUserMdp = (String) session.getAttribute("mdpClient");
        
        Service service = new Service();
        Client client = service.authentifierClient(sessionUserMail, sessionUserMdp);
        List<Consultation> listConsultation = service.consulterHistoriqueClient(client);
        List<String> listDenomination = new ArrayList<>();
        for(int i = 0; i < listConsultation.size(); i++){
            listDenomination.add(listConsultation.get(i).getMedium().getDenomination());
        }
        request.setAttribute("listConsultation", listConsultation);
        request.setAttribute("listDenomination", listDenomination);
    }
}
