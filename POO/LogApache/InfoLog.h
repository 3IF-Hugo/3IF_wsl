/*************************************************************************
                           InfoLog  -  description
                             -------------------
    début                : Janvier 2022
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <InfoLog> (fichier InfoLog.h) ----------------
#if ! defined ( InfoLog_H )
#define InfoLog_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
//------------------------------------------------------------------------
// Rôle de la classe <InfoLog>
//      ...
//------------------------------------------------------------------------
struct Renseignements
{
    string IP;
    string date;
    string heure;
    string destinataire;
    string typeDoc;
    string status;
    string qteData;
    string referer;
    string clientNav;
    Renseignements(string ip = "", string dt = "", string h = "", string dest ="",
    string td = "", string st = "", string qd = "", string ref = "",
    string cN = "") : 
    IP(ip), date(dt), heure(h), destinataire(dest), typeDoc(td), status(st), 
    qteData(qd), referer(ref), clientNav(cN)
    {}
};

class InfoLog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    friend class LectureLog;

    friend class Graphe;
//-------------------------------------------- Constructeurs - destructeur
    InfoLog ( const InfoLog & unInfoLog );

    InfoLog(Renseignements r = Renseignements()) : infos(r)
    {}

    // InfoLog ( );

    virtual ~InfoLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Renseignements infos;
};

#endif // InfoLog_H

