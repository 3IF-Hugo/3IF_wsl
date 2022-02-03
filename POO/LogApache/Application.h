/*************************************************************************
                           Application  -  description
                             -------------------
    début                : Janvier 2022
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Application> (fichier Application.h) ----------------
#if ! defined ( Application_H )
#define Application_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include <iostream>
#include <map>
#include "InfoLog.h"
class test;
//------------------------------------------------------------------------
// Rôle de la classe <Application>
//      Permet de remplir ligne par ligne la map parcours.
//      Permet de générer un Application .dot.
//      Permet de faire le top 10 et de l'afficher
//------------------------------------------------------------------------
struct Cle1
{
    string source;
    string destinataire;
    Cle1(string src = "", string dest = "") : source(src), destinataire(dest)
    {}
};

//Map pour le Application
//typedef map<Cle1, int> Tgraph;
typedef pair<string, string> Cle;
typedef map<Cle, int> Tgraph;

//Map pour destinataire/nb de hit
typedef map<string, int> Classement;

//Map pour la recherche du top10
typedef multimap<int, string> Top10;

class Application
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool LectureFichier(string nomFic, int optG, int optE, int optT);
    /* Méthode pour lire ligne par ligne le fichier en entrée suivant des caractéristiques
        @param1 string : le nom du fichier à lire
        @param2 int : l'option -g : 1 = renseignée, 0 : non renseignée
        @param3 int : l'option -e : 1 = renseignée, 0 : non renseignée
        @param4 int : l'option -t : x = renseignée et x est l'heure, -1 : non renseignée
        @call Ajouter : méthode de <Application>
        @call AjouterClassement : méthode de <Application>
        @call getNextLog : méthode de <LectureLog>
        @call Ajouter : méthode de <Application>
        @return bool : Retourne si on a pu lire correctement le fichier
    */

    void Ajouter(const InfoLog & log);
    /* Méthode pour ajouter certains argument de log dans la map parcours
        @param1 Infolog : un objet log contenant toutes les informations de la ligne concernée
    */

    void AjouterClassement(const InfoLog & log);
    /* Méthode pour ajouter certains argument de log dans la map classement
        @param1 Infolog : un objet log contenant toutes les informations de la ligne concernée
    */

    void FaireTop10();
    /* Méthode pour classer les destinataires ayant le plus de hit, utilise une multimap
    */

    void AfficherTop10();
    /* Méthode pour afficher les 10 destinataires ayant le plus de hit
    */
    
    void Generer(string nomFic);
    /* Méthode pour générer un fichier .dot ayant le nom fournit en entrée
        @param1 string : le nom du fichier dans lequel écrire
    */
//-------------------------------------------- Constructeurs - destructeur
    Application ( const Application & unApplication );

    Application ( );

    ~Application ( );
//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Tgraph parcours;
Classement classement;
Top10 top10;
};

#endif // Application_H

