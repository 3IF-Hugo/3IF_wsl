/*************************************************************************
                           LinkedList  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <LinkedList> (fichier LinkedList.cpp) ------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include "Element.h"
#include "LinkedList.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void LinkedList::ajouter ( Trajet *unTrajet )
//Algorithme :
{
    Element *e = new Element(unTrajet);
    if(elemDebut == NULL)
    {
        elemDebut = e;
        elemFin = e;
        e->setElemNext(NULL);
    }
    else
    {
        elemFin->setElemNext(e);
        elemFin = e;
        elemFin->setElemNext(NULL);
    }
} //----- Fin de Méthode

void LinkedList::afficher()
// Algorithme :
//
{
    Element *parcours = elemDebut;
    int n = 1;
    while(parcours != NULL)
    {
        cout << n << ". ";
        n++;
        parcours->getTrajet()->Afficher();
        parcours = parcours->getElemNext();
    }
    cout << endl;
} //----- Fin de Méthode

void LinkedList::Rechercher(Trajet *unTrajet)
{
    int cpt = 0;
	Element *elemSearch = elemDebut;
    
    if(elemSearch == NULL)							
	{
        cout << "Liste vide, aucun trajet disponible." << endl;
	}

	while(elemSearch != NULL)
	{
		if(!strcmp(elemSearch->getTrajet()->getVilleDepart(),unTrajet->getVilleDepart()) && !strcmp(elemSearch->getTrajet()->getVilleArrivee(), unTrajet->getVilleArrivee()))
		{
            cout << "Nous avons trouvé votre trajet : " << endl;
            elemSearch->getTrajet()->Afficher();
            cpt++;
		}

		elemSearch = elemSearch->getElemNext();

		if(elemSearch == NULL && cpt == 0)							
		{
            cout << "Nous n'avons pas trouvé le trajet demandé." << endl;
			break;
		}
	}	
}

// type LinkedList::Méthode ( LinkedListe des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*LinkedList & LinkedList::operator = ( const LinkedList & unLinkedList )
// Algorithme :
//
{
} //----- Fin de operator =
*/


//-------------------------------------------- Constructeurs - destructeur
LinkedList::LinkedList()
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <LinkedList>" << endl;
    #endif
    elemDebut = NULL;
    elemFin = NULL;
} //----- Fin du constructeur de LinkedList


// LinkedList::LinkedList ( )
// Algorithme :
//
// {
//     #ifdef MAP
//         cout << "Appel au constructeur de <LinkedList>" << endl;
//     #endif
//     trajet = NULL;
//     trajetNext = NULL;
//} //----- Fin du constructeur par défaut de LinkedList


LinkedList::~LinkedList ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au destructeur de <LinkedList>" << endl;
    #endif
    delete elemDebut;
} //----- Fin de ~LinkedList

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

