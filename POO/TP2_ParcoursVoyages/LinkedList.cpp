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

void LinkedList::ajouter ( Trajet *unTrajet, int tri )
//Algorithme :
        //Ajoute un nouveau trajet dans le catalogue de trajets
{
    Element *e = new Element(unTrajet);     // Création du nouvel élément à ajouter
    //////SI LA LISTE EST VIDE//////
    if(elemDebut == NULL)
    {
        elemDebut = e;
        elemFin = e;
        e->setElemNext(NULL);
    }
    //////SI ON AJOUTE EN TRIANT PAR RAPPORT A LA PREMIERE LETTRE DE LA VILLE DE DEPART//////
    else if(tri)
    {
        Element *parcours = elemDebut;
        int done = 0;
        //Ajout en tête si la ville de départ du premier élément actuel est après le trajet à ajouter dans l'ordre alphabétique
        if(elemDebut->getTrajet()->getVilleDepart()[0] >= e->getTrajet()->getVilleDepart()[0])
        {
            e->setElemNext(elemDebut);
            elemDebut = e;
        }
        //Sinon
        else
        {
            //Parcours de la liste
            while(parcours->getElemNext() != NULL)
            {
                //Ajout de l'élément en milieu de liste si position adéquate trouvée
                if(parcours->getTrajet()->getVilleDepart()[0] <= e->getTrajet()->getVilleDepart()[0] && parcours->getElemNext()->getTrajet()->getVilleDepart()[0] >= e->getTrajet()->getVilleDepart()[0])
                {
                    e->setElemNext(parcours->getElemNext());
                    parcours->setElemNext(e);
                    done = 1;
                    break;
                }
                parcours = parcours->getElemNext();
            }
            //Sinon ajout en fin de liste
            if(parcours->getTrajet()->getVilleDepart()[0] <= e->getTrajet()->getVilleDepart()[0] && done == 0)
            {
                parcours->setElemNext(e);
                elemFin = e;
            }
        }
    }
    //////SI ON AJOUTE SANS TRIER//////
    else
    {
        elemFin->setElemNext(e);
        elemFin = e;
        elemFin->setElemNext(NULL);
    }
} //----- Fin de ajouter

void LinkedList::afficher()
// Algorithme :
//      Appelle la méthode Afficher() pour chaque trajet de la liste
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
//Algorithme :
        //Recherche un trajet de la liste dont la ville de départ et la ville d'arrivée
        //sont les mêmes que celles du trajet recherché
        //Ne prend pas en compte les sous trajets d'un trajet composé
{
    int cpt = 0;
	Element *elemSearch = elemDebut;
    //Si la liste est vide : pas de recherche
    if(elemSearch == NULL)							
	{
        cout << "Liste vide, aucun trajet disponible." << endl;
	}
    //Sinon
	while(elemSearch != NULL)
	{
        //Si correspondance des villes de départ et d'arrivée
		if(!strcmp(elemSearch->getTrajet()->getVilleDepart(),unTrajet->getVilleDepart()) && !strcmp(elemSearch->getTrajet()->getVilleArrivee(), unTrajet->getVilleArrivee()))
		{
            //Affichage du trajet
            cout << "Nous avons trouvé votre trajet : " << endl;
            elemSearch->getTrajet()->Afficher();
            cpt++;
		}

		elemSearch = elemSearch->getElemNext();                 //On regarde pour le trajet suivant (plusieurs trajets peuvent correspondre)
        //Si on est en fin de liste et que le trajet n'a pas été trouvé, on le notifie
		if(elemSearch == NULL && cpt == 0)							
		{
            cout << "Nous n'avons pas trouvé le trajet demandé." << endl;
			break;
		}
	}	
} //----- Fin de Rechercher

/*void LinkedList::RechercheAvancee(const char* depart, const char* arrivee, int init, LinkedList * listeTrajet)
{
    Element * parcours = elemDebut;
    int fini = 0;
    while(parcours != NULL && fini == 0)
    {
        if(strcmp(parcours->getTrajet()->getVilleDepart(), depart) == 0 && init == 0)
        {
            listeTrajet->ajouter(parcours->getTrajet(), 0);
        }else if(strcmp(listeTrajet->elemFin->getTrajet()->getVilleArrivee(), parcours->getTrajet()->getVilleDepart()) == 0)
        {
            listeTrajet->ajouter(parcours->getTrajet(), 0);
            if(strcmp(parcours->getTrajet()->getVilleArrivee(), arrivee) == 0)
            {
                fini = 1;
            }
            RechercheAvancee(depart, arrivee, 1, listeTrajet);
        }
        parcours = parcours->getElemNext();
    }
}*/

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
        //Initialise une liste vide
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
        //Delete le premier élément qui delete les élements suivants en cascade
{
    #ifdef MAP
        cout << "Appel au destructeur de <LinkedList>" << endl;
    #endif
    delete elemDebut;
} //----- Fin de ~LinkedList

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

