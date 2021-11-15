/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher() const
// Algorithme :
//
{
    Trajet::Afficher();
    for(long unsigned int i=0; i < strlen(moyenTransport); i++)
    {
        cout << moyenTransport[i];
    }
    cout << endl;
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*TrajetSimple & TrajetSimple::operator = ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//
{
} //----- Fin de operator =
*/


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (const char *villeDep, const char *villeArr, const char *moyTrans)
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
    Trajet(villeDep, villeArr);
    this->moyenTransport = new char [strlen(moyTrans)];
    strcpy(moyenTransport, moyTrans);
} //----- Fin du constructeur de TrajetSimple


TrajetSimple::TrajetSimple ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
    moyenTransport = NULL;
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif
    delete[] moyenTransport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

