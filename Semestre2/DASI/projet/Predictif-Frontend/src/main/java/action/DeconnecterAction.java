/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package action;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import metier.modele.Client;
import metier.service.Service;

/**
 *
 * @author mphung
 */
public class DeconnecterAction extends Action{
    @Override
    public void executer(HttpServletRequest request){
        HttpSession session = request.getSession();
        session.removeAttribute("mailClient");
        session.removeAttribute("mdpClient");
        session.removeAttribute("mailEmploye");
        session.removeAttribute("mdpEmploye");
        request.setAttribute("succes", Boolean.TRUE);
    }
}
