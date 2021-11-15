/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet::Afficher() const
// Algorithme :
//
{
    cout << "Trajet de " << villeDepart << " à " << villeArrivee << endl;
    /*
    for(long unsigned int i=0; i < strlen(villeDepart); i++)
    {
        cout << villeDepart[i];
    }
    cout << endl;
    for(long unsigned int i=0; i < strlen(villeArrivee); i++)
    {
        cout << villeArrivee[i];
    }
    cout << endl;
    */
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*Trajet & Trajet::operator = ( const Trajet & unTrajet )
// Algorithme :
//
{
} //----- Fin de operator =
*/


//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
} //----- Fin de Trajet (constructeur de copie)

Trajet::Trajet ( const char *villeDep, const char *villeArr)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif
    villeDepart = new char [strlen(villeDep)+1];
    villeArrivee = new char [strlen(villeArr)+1];
    strcpy(villeDepart, villeDep);
    strcpy(villeArrivee, villeArr);
} //----- Fin du constructeur de Trajet

Trajet::Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
//villeDepart = NULL;
//villeArrivee = NULL;
} //----- Fin de Trajet

Trajet::~Trajet ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au destructeur de <Trajet>" << endl;
    #endif
    delete [] villeDepart;
    delete [] villeArrivee;
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

