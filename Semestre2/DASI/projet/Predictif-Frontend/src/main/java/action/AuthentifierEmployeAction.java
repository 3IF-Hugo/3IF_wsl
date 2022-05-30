/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package action;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import metier.modele.Employe;
import metier.service.Service;

/**
 *
 * @author hgrel
 */
public class AuthentifierEmployeAction extends Action{
    @Override
    public void executer(HttpServletRequest request){
        HttpSession session = request.getSession();
        
        String login = request.getParameter("login");
        String password = request.getParameter("password");

        Service service = new Service();
        Employe employe = service.authentifierEmploye(login, password);
        
        if(employe != null){
            request.setAttribute("succes", Boolean.TRUE);
            session.setAttribute("mailEmploye", request.getParameter("login"));
            session.setAttribute("mdpEmploye", request.getParameter("password"));
        }else{
            request.setAttribute("succes", Boolean.FALSE);
        }
        
    }
}
