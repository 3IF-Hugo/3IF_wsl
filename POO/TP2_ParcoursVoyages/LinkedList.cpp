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

int LinkedList::RechercheAvancee(const char* depart, const char* arrivee, int init, LinkedList * listeTrajet)
//Algorithme :
//      Parcours l'ensemble des trajets disponibles autant de fois que nécessaire pour trouver une succession de trajets
//      permettant d'aller du depart à l'arrivée voulus si possible
{
    Element * parcours = elemDebut;
    int fini = 0, cpt = 0;                              // fini : 0 si on doit continuer à chercher 1 sinon
                                                        // cpt : si cpt = 0 après un parcours complet des trajets, on s'arrête
    //Parcours de la liste des trajets disponibles
    while(parcours != NULL && fini == 0)
    {
        //Si on n'a pas encore trouvé de trajet correspondant au départ
        if(init == 0 && strcmp(parcours->getTrajet()->getVilleDepart(), depart) == 0)
        {
            //DEBUG parcours->getTrajet()->Afficher(); //
            //DEBUG cout << "initialisation trouvée" << endl; //
            listeTrajet->ajouter(parcours->getTrajet(), 0);
            init = 1;
            ++cpt;
            if(strcmp(parcours->getTrajet()->getVilleArrivee(), arrivee) == 0)
            {
                //DEBUG cout << "fin trouvée" << endl; //
                fini = 1;
                break;
            }
        }
        if(init == 1 && strcmp(listeTrajet->elemFin->getTrajet()->getVilleArrivee(), parcours->getTrajet()->getVilleDepart()) == 0)
        {
            //DEBUG parcours->getTrajet()->Afficher(); //
            //DEBUG cout << "trajet hors init trouvé" << endl; //
            listeTrajet->ajouter(parcours->getTrajet(), 0);
            ++cpt;
            //DEBUG cout << "compare arrivee " << strcmp(parcours->getTrajet()->getVilleArrivee(), arrivee) << endl; //
            if(strcmp(parcours->getTrajet()->getVilleArrivee(), arrivee) == 0)
            {
                //DEBUG cout << "fin trouvée" << endl; //
                fini = 1;
                break;
            }
        }
        parcours = parcours->getElemNext();
    }
    ///DEBUG cout << "sortie while" << endl; //
    //DEBUG cout << "verif init : " << init << endl; //
    //DEBUG cout << "verif fini : " << fini << endl; //
    //DEBUG cout << "verif cpt : " << cpt << endl; //
    // Si trajet complet trouvé
    if(fini == 1)
    {
        cout << "Voici le trajet trouvé :" << endl;
    }
    // Si on a trouvé des trajets mais pas jusqu'à l'arrivée voulue, on reprend la rechercher depuis le début de la liste
    if(fini == 0 && cpt > 0)
    {
        //DEBUG cout << "C'est reparti pour une recherche" << endl;
        fini = RechercheAvancee(depart, arrivee, init, listeTrajet);
    }
    // Si on n'a trouvé aucun trajet possible, on s'arrête
    if(cpt == 0 && fini == 0)
    {
        cout << "Nous n'avons pas pu trouver votre trajet" << endl;
    }
    return fini;
} //----- Fin de RechercheAvancee

void LinkedList::vider()
//Algorithme :
//      Supprime les pointeurs vers les trajets pour tous les éléments de la liste
{
    Element *parcours = elemDebut;
    while(parcours != NULL)
    {
        //parcours->getTrajet()->vider();
        parcours->setTrajet(NULL);
        parcours = parcours->getElemNext();
    }
} //----- Fin de vider

// Element * LinkedList::getElemDebut()
// {
//     return elemDebut;
// }

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

