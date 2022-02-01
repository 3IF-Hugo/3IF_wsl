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
    if(fic)
    {
        string temp;
        stringstream scraping;
        long unsigned int posSplit;
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
        posSplit = logLine.infos.date.find_first_of(":");
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
        //Suppression index.html pour temps/ target
        if((posSplit = logLine.infos.destinataire.find("index.html")) != string::npos)
        {
            logLine.infos.destinataire.erase(posSplit, logLine.infos.destinataire.size()-posSplit);
        }
        //Session ou ticket si présente pour target
        if((posSplit = logLine.infos.destinataire.find_first_of(";")) != string::npos)
        {
            logLine.infos.complement = logLine.infos.destinataire.substr(posSplit+1, logLine.infos.destinataire.size()-posSplit-1);
            logLine.infos.destinataire.erase(posSplit, logLine.infos.destinataire.size()-posSplit);
        }
        if((posSplit = logLine.infos.destinataire.find_first_of("?")) != string::npos)
        {
            logLine.infos.complement = logLine.infos.destinataire.substr(posSplit+1, logLine.infos.destinataire.size()-posSplit-1);
            logLine.infos.destinataire.erase(posSplit, logLine.infos.destinataire.size()-posSplit);
        }

        //Type doc
        if((posSplit = logLine.infos.destinataire.find_first_of(".")) != string::npos)
        {
            logLine.infos.typeDoc = logLine.infos.destinataire.substr(posSplit+1, logLine.infos.destinataire.size()-posSplit-1);
        }else
        {
            logLine.infos.typeDoc = "html";
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
        //Suppression session ou ticket si présente pour referer
        if((posSplit = logLine.infos.referer.find_first_of(";")) != string::npos)
        {
            logLine.infos.referer_complement = logLine.infos.referer.substr(posSplit+1, logLine.infos.referer.size()-posSplit-1);
            logLine.infos.referer.erase(posSplit, logLine.infos.referer.size()-posSplit);
        }
        if((posSplit = logLine.infos.referer.find_first_of("?")) != string::npos && logLine.infos.referer.find("url?") == string::npos && logLine.infos.referer.find("search?") == string::npos)
        {
            logLine.infos.referer_complement = logLine.infos.referer.substr(posSplit+1, logLine.infos.referer.size()-posSplit-1);
            logLine.infos.referer.erase(posSplit, logLine.infos.referer.size()-posSplit);
        }
        //Suppression index.html pour temps/ referer
        if((posSplit = logLine.infos.referer.find("index.html")) != string::npos)
        {
            logLine.infos.referer.erase(posSplit, logLine.infos.referer.size()-posSplit);
        }

        //Navigateur utilisé
        scraping >> temp;
        logLine.infos.clientNav = temp;
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

