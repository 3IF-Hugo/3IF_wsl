/*************************************************************************
                           Annuaire  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Annuaire> (fichier Annuaire.h) ----------------
#if ! defined ( Annuaire_H )
#define Annuaire_H

//--------------------------------------------------- Interfaces utilisées
#include "Abonne.h"
#include <map>
#include <list>
//------------------------------------------------------------------------
// Rôle de la classe <Annuaire>
//      ...
//------------------------------------------------------------------------

class Annuaire
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Ajouter(const Abonne & a);

    void Ajouter(string nomfic);

    void Afficher(string nom = "", ostream & f = cout) const;

    list<Abonne> RechercheInverse(string tel) const;

    void Sauvegarder(string nomfic);
//-------------------------------------------- Constructeurs - destructeur
    Annuaire ( const Annuaire & unAnnuaire );

    Annuaire(string nomfic = "");

    // Annuaire ( );

    virtual ~Annuaire ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
typedef multimap<string, Renseignements> Tdico;
Tdico pagesBlanches;
};

#endif // Annuaire_H

