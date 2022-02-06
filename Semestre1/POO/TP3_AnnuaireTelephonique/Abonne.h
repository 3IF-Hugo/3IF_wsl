/*************************************************************************
                           Abonne  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Abonne> (fichier Abonne.h) ----------------
#if ! defined ( Abonne_H )
#define Abonne_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include <iostream>
class Annuaire;
//------------------------------------------------------------------------
// Rôle de la classe <Abonne>
//      ...
//------------------------------------------------------------------------
struct Renseignements
{
    string prenom;
    string adresse;
    string telephone;
    Renseignements(string p = "", string ad = "", string tel = "") : prenom(p), adresse(ad), telephone(tel)
    {}
};

class Abonne
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    friend istream & operator>>(istream & is, Abonne & a);

    friend ostream & operator<<(ostream & os, Abonne & a);

    friend class Annuaire;
//-------------------------------------------- Constructeurs - destructeur
    Abonne ( const Abonne & unAbonne );

    Abonne(string name = "", Renseignements r = Renseignements()) : nom(name), infos(r)
    {}

    // Abonne ( );

    virtual ~Abonne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string nom;
Renseignements infos;
};

#endif // Abonne_H

