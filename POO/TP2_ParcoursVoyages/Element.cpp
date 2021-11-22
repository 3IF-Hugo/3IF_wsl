/*************************************************************************
                           Element  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Element> (fichier Element.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "Element.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
Trajet * Element::getTrajet()
// Algorithme :
//
{
    return trajet;
} //----- Fin de Méthode

void Element::setTrajet (Trajet *unTrajet)
// Algorithme :
//
{
    trajet = unTrajet;
} //----- Fin de Méthode

Element * Element::getElemNext()
// Algorithme :
//
{
    return elemNext;
} //----- Fin de Méthode

void Element::setElemNext (Element *unElem)
// Algorithme :
//
{
    elemNext = unElem;
} //----- Fin de Méthode

// type Element::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*Element & Element::operator = ( const Element & unElement )
// Algorithme :
//
{
} //----- Fin de operator =
*/


//-------------------------------------------- Constructeurs - destructeur
Element::Element ( Trajet *unTrajet )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Element>" << endl;
    #endif
    trajet = unTrajet;
    elemNext = NULL;
} //----- Fin du constructeur de Element


Element::Element ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Element>" << endl;
    #endif
    trajet = NULL;
    elemNext = NULL;
} //----- Fin du constructeur par défaut de Element


Element::~Element ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au destructeur de <Element>" << endl;
    #endif
    delete [] trajet;
    delete [] elemNext;
} //----- Fin de ~Element


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

