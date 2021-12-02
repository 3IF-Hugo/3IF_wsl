/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------
#if ! defined ( Catalogue_H )
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"
#include "Element.h"
#include "LinkedList.h"
#include "TrajetCompose.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// 
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterTrajetSimple ( const char* villeDepart, const char* villeArrivee, const char* moyenTransport );
    /* Méthode pour ajouter un trajet simple :
        @param1 const char* : ville de départ
        @param2 const char* : ville d'arrivée
        @param3 const char* : moyen de transport
    */

    TrajetCompose* AjouterTrajetCompose ( const char* villeDepart, const char* villeArrivee );
    /* Méthode pour ajouter un trajet composé :
        @param1 const char* : ville de départ globale
        @param2 const char* : ville d'arrivée globale
        @return TrajetCompose* : le trajet composé qui vient d'être créé et ajouté dans le catalogue
    */

    void AjouterSousTrajetSimple(const char* villeDepart, const char* villeArrivee, const char* moyenTransport, TrajetCompose *unTrajetComp);
    /* Méthode pour ajouter une étape à un trajet composé :
        @param1 const char* : ville de départ de l'étape
        @param2 const char* : ville d'arrivée de l'étape
        @param3 const char* : moyen de transport
        @param4 TrajetCompose* : le trajet composé dans lequel ajouter l'étape
    */

    void Rechercher(const char* depart, const char* arrivee);
    /* Méthode pour rechercher un trajet :
        @param1 const char* : ville de départ
        @param2 const char* : ville d'arrivée
    */

    void Afficher();

//------------------------------------------------- Surcharge d'opérateurs
    Catalogue & operator = ( const Catalogue & unCatalogue );
 
//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );
    // Constructeur de copie
 
    Catalogue ( );
    
    virtual ~Catalogue ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
LinkedList *catalogueTrajet;
};

#endif // Catalogue_H

