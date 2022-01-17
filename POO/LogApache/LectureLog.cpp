/*************************************************************************
                           LectureLog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <LectureLog> (fichier LectureLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "LectureLog.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
InfoLog & LectureLog::getNextLog(ifstream & fic, InfoLog & logLine)
{
    // Il faut enlever le chemin absolu du referer (pas de intranet.insa-lyon.fr)
    if(fic)
    {
        string temp;
        stringstream scraping;
        getline(fic, temp, '\n');
        scraping << temp;
        //IP
        scraping >> logLine.infos.IP;
        //UserLogName
        scraping >> logLine.infos.userLogName;
        //UserName
        scraping >> logLine.infos.userName;
        //Date + heure
        scraping >> logLine.infos.date;
        logLine.infos.date.erase(0, 1);
        //Séparation date et heure
        int posSplit = logLine.infos.date.find_first_of(":");
        logLine.infos.heure = logLine.infos.date.substr(posSplit+1, logLine.infos.date.size()-posSplit-1);
        logLine.infos.date.erase(posSplit, logLine.infos.date.size()-posSplit);
        //Fuseau horaire
        scraping >> logLine.infos.fuseauHoraire;
        logLine.infos.fuseauHoraire.pop_back();
        //Type d'action (GET, OPTION, ...)
        scraping >> logLine.infos.typeAction;
        logLine.infos.typeAction.erase(0, 1);
        //URL de la target
        scraping >> logLine.infos.destinataire;
        //Type de doc
        if(logLine.infos.destinataire.find(".") != string::npos)
        {
            posSplit = logLine.infos.destinataire.find_last_of(".");
            logLine.infos.typeDoc = logLine.infos.destinataire.substr(posSplit+1, logLine.infos.date.size()-posSplit-1);
        }
        //HTML/1.1
        scraping >> logLine.infos.HTML;
        logLine.infos.HTML.pop_back();
        //Status
        scraping >> logLine.infos.status;
        //Qte de data échangée (- si pas spécifiée)
        scraping >> logLine.infos.qteData;
        //Referer
        scraping >> logLine.infos.referer;
        logLine.infos.referer.erase(0,1);
        logLine.infos.referer.pop_back();
        //Navigateur utilisé
        scraping >> logLine.infos.clientNav;
        temp = "";
        while(temp.back() != '"')
        {
            scraping >> temp;
            logLine.infos.clientNav += " "+temp;
        }
        logLine.infos.clientNav.erase(0,1);
        logLine.infos.clientNav.pop_back();
    }
    return logLine;
}
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
// LectureLog & LectureLog::operator = ( const LectureLog & unLectureLog )
// // Algorithme :
// //
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
LectureLog::LectureLog ( const LectureLog & unLectureLog )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LectureLog>" << endl;
#endif
} //----- Fin de LectureLog (constructeur de copie)


LectureLog::LectureLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LectureLog>" << endl;
#endif
} //----- Fin de LectureLog


LectureLog::~LectureLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LectureLog>" << endl;
#endif
} //----- Fin de ~LectureLog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

