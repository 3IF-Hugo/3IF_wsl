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

class Graphe
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Ajouter(const InfoLog & log);
    
//-------------------------------------------- Constructeurs - destructeur
    Graphe ( const Graphe & unGraphe );

    Graphe(string nomfic = "");

    // Graphe ( );

    virtual ~Graphe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
typedef map<Cle1, int> Tgraph;
Tgraph parcours;
};

#endif // Graphe_H

