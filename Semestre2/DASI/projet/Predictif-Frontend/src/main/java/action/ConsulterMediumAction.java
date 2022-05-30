/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package action;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import metier.modele.Client;
import metier.modele.Medium;
import metier.service.Service;

/**
 *
 * @author hgrel
 */
public class ConsulterMediumAction extends Action{
    @Override
    public void executer(HttpServletRequest request){
        Service service = new Service();
        List<Medium> listMedium = service.consulterListeMedium();
        List<String> typeMedium = new ArrayList<>();
        for(int i = 0; i < listMedium.size(); i++){
            typeMedium.add(listMedium.get(i).getClass().getSimpleName());
        }
        request.setAttribute("typeMedium", typeMedium);
        request.setAttribute("listMedium", listMedium);
    }
}
