/*************************************************************************
                           Annuaire  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Annuaire> (fichier Annuaire.cpp) ------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Annuaire.h"
#include <fstream>
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Annuaire::Ajouter(const Abonne & a)
{
    if(!a.nom.empty())
    {
        // pagesBlanches.insert(make.pair(a.nom, a.infos));
        pagesBlanches.insert(pair<string, Renseignements> (a.nom, a.infos));
    }
}

void Annuaire::Ajouter(string nomfic)
{
    ifstream file (nomfic.c_str());
    Abonne a;

    if(file)
    {
        while(file >> a)
        {
            Ajouter(a);
        }else{
            cerr << "Problème d'accés au fichier : " << nomfic << endl;
        }
    }
}

void Annuaire::Afficher(string nom, ostream & f) const
{
    Tdico::const_iterator debut;
    Tdico::const_iterator fin;

    if(nom.empty())
    {
        debut = pagesBlanches.begin();
        fin = pagesBlanches.end();
    }else{
        debut = pagesBlanches.lower_bound(nom);
        fin = pagesBlanches.upper_bound(nom);
    }

    while(debut != fin)
    {
        f << Abonne(debut->first, debut->second);
        debut++;
    }
}

list<Abonne> Annuaire::RechercheInverse(string tel) const
{
    Tdico::const_iterator debut;
    Tdico::const_iterator fin;
    debut = pagesBlanches.begin();
    fin = pagesBlanches.end();
    list<Abonne> la;

    while(debut != fin)
    {
        if(debut->second.telephone == tel)
        {
            la.push_back(Abonne(debut->first, debut->second));
        }
        debut++;
    }
    return la;
}

//-------------------------------------------- Constructeurs - destructeur
// Annuaire::Annuaire ( const Annuaire & unAnnuaire )
//----- Fin de Annuaire (constructeur de copie)

// Annuaire::Annuaire (string name = "", Renseignements r = Renseignements())
// Constructeur de Annuaire

// Annuaire::Annuaire ( )
// Constructeur par défaut

// Annuaire::~Annuaire ( )
// Destructeur de Annuaire

