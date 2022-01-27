/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : Janvier 2022
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Graphe> (fichier Graphe.h) ----------------
#if ! defined ( Graphe_H )
#define Graphe_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include <iostream>
#include <map>
#include "InfoLog.h"
class test;
//------------------------------------------------------------------------
// Rôle de la classe <Graphe>
//      ...
//------------------------------------------------------------------------
struct Cle1
{
    string source;
    string destinataire;
    Cle1(string src = "", string dest = "") : source(src), destinataire(dest)
    {}
};

//Map pour le graphe
//typedef map<Cle1, int> Tgraph;
typedef pair<string, string> Cle;
typedef map<Cle, int> Tgraph;

//Map pour destinataire/nb de hit
typedef map<string, int> Classement;

//Map pour la recherche du top10
typedef multimap<int, string> Top10;

class Graphe
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    //friend bool operator< (const Cle1 & uneCle, const Cle1 & uneAutre);

    //friend ostream & operator<<(ostream & os, Tgraph::const_iterator & g);

    friend ostream & operator<<(ofstream & os, const Cle1 & uneCle);
    
    //friend bool operator==(const Cle1 & uneCle, const Cle1 & uneAutre);

    friend class test;

    void LectureFichier(string nomFic, int optG, int optE, int optT);

    void Ajouter(const InfoLog & log);

    void AjouterClassement(const InfoLog & log);

    void FaireTop10();

    void AfficherTop10();
    
    //void Afficher(string nom = "", ostream & f = cout) const;

    void Generer(string nomFic = "");
//-------------------------------------------- Constructeurs - destructeur
    Graphe ( const Graphe & unGraphe );

    //Graphe(string nomfic = "");

    Graphe ( );

    //~Graphe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Tgraph parcours;
Classement classement;
Top10 top10;
};

#endif // Graphe_H

