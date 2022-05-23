/*************************************************************************
                           Attribute  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Interface de la classe <Attribute> (fichier Attribute.h) ----------------
using namespace std;
#include <string>
#include <iostream>
#if ! defined ( ATTRIBUTE_H )
#define ATTRIBUTE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribute>
//
//
//------------------------------------------------------------------------

class Attribute
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    string getAttributeId();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getUnit();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getDescription();
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Attribute & operator = ( const Attribute & unAttribute );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Attribute ( const Attribute & unAttribute );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Attribute (string AttributeId = "", string Unit = "", string description = "");
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Attribute ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string attributeId;
    string unit;
    string description;
};

//-------------------------------- Autres définitions dépendantes de <Attribute>

#endif // ATTRIBUTE_H