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
 * @author hgrel
 */
public class AuthentifierUtilisateurAction extends Action{
    @Override
    public void executer(HttpServletRequest request){
        String login = request.getParameter("login");
        String password = request.getParameter("password");
        
        HttpSession session = request.getSession();

        Service service = new Service();
        Client client = service.authentifierClient(login, password);
        
        if(client != null){
            request.setAttribute("succes", Boolean.TRUE);
            session.setAttribute("mailClient", request.getParameter("login"));
            session.setAttribute("mdpClient", request.getParameter("password"));
        }else{
            request.setAttribute("succes", Boolean.FALSE);
        }
    }
}
