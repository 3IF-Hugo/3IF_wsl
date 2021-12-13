/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher() const
{
    cout << "Trajet de " << villeDepart << " à " << villeArrivee << " en " << moyenTransport << endl;
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple (constructeur de copie)

TrajetSimple::TrajetSimple (const char *villeDep, const char *villeArr, const char *moyTrans) : Trajet(villeDep, villeArr)
/* Constructeur de <TrajetSimple>
        @param1 const char* : ville de départ
        @param2 const char* : ville d'arrivée
        @param3 const char* : moyen de transport
        @using constructeur de <Trajet>
*/
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
    this->moyenTransport = new char [strlen(moyTrans) + 1];
    strcpy(moyenTransport, moyTrans);
} //----- Fin du constructeur de TrajetSimple

TrajetSimple::TrajetSimple ( ) : Trajet()
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif
    delete [] moyenTransport;
} //----- Fin de ~TrajetSimple

