/*************************************************************************
                           Element  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <Element> (fichier Element.cpp) ----------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#define MAP

using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "Element.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
Trajet * Element::getTrajet()
// Algorithme :
//      Renvoie le trajet correspondant à l'élément
{
    return trajet;
} //----- Fin de getTrajet

void Element::setTrajet (Trajet *unTrajet)
// Algorithme :
//      Modifie le trajet correspondant à l'élément
{
    trajet = unTrajet;
} //----- Fin de setTrajet  

Element * Element::getElemNext()
// Algorithme :
//      Renvoie l'élément suivant
{
    return elemNext;
} //----- Fin de getElemNext

void Element::setElemNext (Element *unElem)
// Algorithme :
//      Modifie l'élément suivant
{
    elemNext = unElem;
} //----- Fin de setElemNext

//-------------------------------------------- Constructeurs - destructeur
Element::Element ( Trajet *unTrajet )
// Algorithme :
//      Initialise un élement avec un trajet
{
    #ifdef MAP
        cout << "Appel au constructeur de <Element>" << endl;
    #endif
    trajet = unTrajet;
    elemNext = NULL;
} //----- Fin du constructeur de Element


Element::Element ( )
// Algorithme :
//      Initialise un élement vide
{
    #ifdef MAP
        cout << "Appel au constructeur de <Element>" << endl;
    #endif
    trajet = NULL;
    elemNext = NULL;
} //----- Fin du constructeur par défaut de Element


Element::~Element ( )
// Algorithme :
//      Delete l'élement et son élement suivant s'il existe
{
    #ifdef MAP
        cout << "Appel au destructeur de <Element>" << endl;
    #endif
    delete trajet;
    if(elemNext != NULL)
    {
        delete elemNext;
    }
} //----- Fin de ~Element