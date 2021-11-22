/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h" // POUR LES TESTS A ENLEVER
#include "Element.h"
#include "LinkedList.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::ajouter (Trajet *unTrajet)
// Algorithme :
//
{
    list->ajouter(unTrajet);
} //----- Fin de Méthode

void TrajetCompose::Afficher() const
// Algorithme :
//
{
    cout << "Trajet composé de " << villeDepart << " à " << villeArrivee << " comportant les sous-trajets suivants :" << endl;
    list->afficher();
} //----- Fin de Méthode

// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*TrajetCompose & TrajetCompose::operator = ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
} //----- Fin de operator =
*/


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose (const char *villeDep, const char *villeArr) : Trajet(villeDep, villeArr)
{
    list = new LinkedList();
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif
} //----- Fin du constructeur de TrajetCompose


TrajetCompose::TrajetCompose ( )
// Algorithme :
//
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
    delete[] villeDepart;
    delete[] villeArrivee;
    delete list;
} //----- Fin de ~TrajetCompose

/////////////TEST/////////////
// int main()
// {
    
//     const char* Paris = "Paris";
//     const char* Lyon = "Lyon";
//     const char* Valence = "Valence";
//     const char* Bordeaux = "Bordeaux";
//     const char* Montpellier = "Montpellier";
//     const char* Marseille = "Marseille";
//     const char* train = "train";
//     const char* avion = "avion";

//     Trajet *traj1 = new Trajet(Paris, Lyon);
//     TrajetSimple *traj2 = new TrajetSimple(Lyon, Valence, train);
//     TrajetSimple *traj4 = new TrajetSimple(Montpellier, Marseille, avion);

//     TrajetCompose *traj3 = new TrajetCompose(Valence, Montpellier);
//     TrajetSimple * traj3_1 = new TrajetSimple(Valence, Bordeaux, avion);
//     TrajetSimple * traj3_2 = new TrajetSimple(Bordeaux, Montpellier, train);
//     traj3->ajouter(traj3_1);
//     traj3->ajouter(traj3_2);
    
//     TrajetCompose *trajC = new TrajetCompose(Paris, Marseille);

//     trajC->ajouter(traj1);
//     trajC->ajouter(traj2);
//     trajC->ajouter(traj3);
//     trajC->ajouter(traj4);
//     trajC->Afficher();
    
    
//     //delete [] traj1;
//     //delete[] traj2;
    
//     return 0;
// }

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

