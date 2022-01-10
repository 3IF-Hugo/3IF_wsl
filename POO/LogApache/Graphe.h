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

typedef map<Cle1, int> Tgraph;

class Graphe
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    friend bool operator< (const Cle1 & uneCle, const Cle1 & uneAutre);

    // friend ostream & operator<<(ostream & os, Tgraph::const_iterator & g);

    // friend ostream & operator<<(ofstream & os, const Cle1 & uneCle);
    
    friend bool operator==(const Cle1 & uneCle, const Cle1 & uneAutre);

    friend class test;

    void Ajouter(const InfoLog & log);
    
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
};

#endif // Graphe_H

