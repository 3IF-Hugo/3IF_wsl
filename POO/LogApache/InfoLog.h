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
    string userLogName;
    string userName;
    string date;
    string heure;
    string fuseauHoraire;
    string typeAction;
    string destinataire;
    string complement;
    string HTML;
    string typeDoc;
    string status;
    string qteData;
    string referer;
    string referer_complement;
    string clientNav;
    Renseignements(string ip = "", string userLN = "", string userN = "", string dt = "", string h = "", string fh = "", string ta = "", string dest ="", string comp = "-", string html = "",
    string td = "-", string st = "", string qd = "", string ref = "", string ref_comp = "-",
    string cN = "") : 
    IP(ip), userLogName(userLN), userName(userN), date(dt), heure(h), fuseauHoraire(fh), typeAction(ta), destinataire(dest), complement (comp), HTML(html), typeDoc(td), status(st), 
    qteData(qd), referer(ref), referer_complement(ref_comp), clientNav(cN)
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
    InfoLog ( const InfoLog & unInfoLog )
    {}

    InfoLog(Renseignements r = Renseignements()) : infos(r)
    {}

    // InfoLog ( );

    virtual ~InfoLog ( )
    {}
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

