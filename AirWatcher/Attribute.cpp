/*************************************************************************
                           Attribute  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Réalisation de la classe <Attribute> (fichier Attribute.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Attribute.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Attribute::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Attribute::getAttributeId()
{
    return attributeId;
}

string Attribute::getUnit()
{
    return unit;
}

string Attribute::getDescription()
{
    return description;
}


//------------------------------------------------- Surcharge d'opérateurs
Attribute & Attribute::operator = ( const Attribute & unAttribute )
// Algorithme :
//
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Attribute::Attribute ( const Attribute & unAttribute )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Attribute>" << endl;
#endif
    attributeId = unAttribute.attributeId;
    unit = unAttribute.unit;
    description = unAttribute.description;
} //----- Fin de Attribute (constructeur de copie)

Attribute::Attribute (string attributeId, string unit, string description) : attributeId(attributeId), unit(unit), description(description)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Attribute>" << endl;
#endif
} //----- Fin de Attribute


Attribute::~Attribute ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Attribute>" << endl;
#endif
} //----- Fin de ~Attribute


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées