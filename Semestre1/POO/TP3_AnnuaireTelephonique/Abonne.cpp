/*************************************************************************
                           Abonne  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Abonne> (fichier Abonne.cpp) ------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Abonne.h"
//----------------------------------------------------------------- PUBLIC
const char SEP = '|';
//----------------------------------------------------- Méthodes publiques
istream & operator>>(istream & is, Abonne & a)
{
    getline(is, a.nom, SEP);
    getline(is, a.infos.prenom, SEP);
    getline(is, a.infos.adresse, SEP);
    getline(is, a.infos.telephone);
    return is;
}

ostream & operator<<(ostream & os, Abonne & a)
{
    os << a.nom << SEP << a.infos.prenom << SEP;
    os << a.infos.adresse << SEP;
    os << a.infos.telephone << endl;
    return os;
}

//-------------------------------------------- Constructeurs - destructeur
// Abonne::Abonne ( const Abonne & unAbonne )
//----- Fin de Abonne (constructeur de copie)

// Abonne::Abonne (string name = "", Renseignements r = Renseignements())
// Constructeur de Abonne

// Abonne::Abonne ( )
// Constructeur par défaut

// Abonne::~Abonne ( )
// Destructeur de Abonne

