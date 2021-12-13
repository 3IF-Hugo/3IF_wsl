/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) -

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#define MAP

using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include "Element.h"
#include "LinkedList.h"
#include "TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::ajouter (Trajet *unTrajet)
// Algorithme :
//          Ajoute un nouveau trajet dans le catalogue de trajets
{
    list->ajouter(unTrajet, 0);
} //----- Fin de Méthode

void TrajetCompose::Afficher() const
// Algorithme :
//          Affiche la ville de départ et d'arrivée globale
//          Affiche ensuite les trajets simples le composant
{
    cout << "Trajet composé de " << villeDepart << " à " << villeArrivee << " comportant les sous-trajets suivants :" << endl;
    list->afficher();
} //----- Fin de Méthode

void TrajetCompose::Sauvegarder()
{
    cout << "c" << endl;
    cout << villeDepart << endl;
    cout << villeArrivee << endl;
    Element *parcours = list->getElemDebut();
    while(parcours != NULL)
    {
        parcours->getTrajet()->Sauvegarder();
        parcours = parcours->getElemNext();
    }
    cout << "_c" << endl;
}

bool TrajetCompose::EstCompose()
{
    return true;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose (const char *villeDep, const char *villeArr) : Trajet(villeDep, villeArr)
/* Constructeur de <TrajetCompose>
        @param1 const char* : ville de départ
        @param2 const char* : ville d'arrivée
        @using constructeur de <Trajet>
*/
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif
    list = new LinkedList();
} //----- Fin du constructeur de TrajetCompose


TrajetCompose::TrajetCompose ( )
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetCompose>" << endl;
    #endif
    delete list;
} //----- Fin de ~TrajetCompose
