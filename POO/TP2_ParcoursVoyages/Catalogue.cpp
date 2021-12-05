/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//----- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) -----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::AjouterTrajetSimple ( const char* villeDepart, const char* villeArrivee, const char* moyenTransport )
// Algorithme :
//          Crée puis ajoute un nouveau trajet simple dans le catalogue de trajets
{
    TrajetSimple *nouveauTrajet = new TrajetSimple ( villeDepart, villeArrivee, moyenTransport );
    // nouveauTrajet->Afficher();
    catalogueTrajet->ajouter ( nouveauTrajet, 1);
} //----- Fin de Méthode

TrajetCompose* Catalogue::AjouterTrajetCompose ( const char* villeDepart, const char* villeArrivee )
// Algorithme :
//          Crée puis ajoute un nouveau trajet composé dans le catalogue de trajets.
//          Retourne le trajet créé. 
{
    TrajetCompose *nouveauTrajet = new TrajetCompose ( villeDepart, villeArrivee );
    catalogueTrajet->ajouter ( nouveauTrajet, 1 );
    return nouveauTrajet;
} //----- Fin de Méthode

void Catalogue::AjouterSousTrajetSimple(const char* villeDepart, const char* villeArrivee, const char* moyenTransport, TrajetCompose *unTrajetComp)
// Algorithme :
//          Crée puis ajoute un nouveau trajet simple dans le trajet composé correspondant.
{
    TrajetSimple *nouveauTrajet = new TrajetSimple ( villeDepart, villeArrivee, moyenTransport );
    unTrajetComp->ajouter(nouveauTrajet);
}

void Catalogue::Afficher()
{
    catalogueTrajet->afficher();
}

void Catalogue::Rechercher(const char* depart, const char* arrivee)
// Algorithme :
//          Crée un trajet avec les paramètres de recherche puis recherche ce trajet dans le catalogue
{
    Trajet *trajetRecherche = new Trajet(depart, arrivee);
    catalogueTrajet->Rechercher(trajetRecherche);
    delete trajetRecherche;
}

void Catalogue::RechercheAvancee(const char* depart, const char* arrivee)
// Algorithme :
//          Crée un trajet avec les paramètres de recherche puis recherche ce trajet dans le catalogue
{
    LinkedList * resultat = new LinkedList();
    if(catalogueTrajet->RechercheAvancee(depart, arrivee, 0, resultat))
    {
        resultat->afficher();
    }
    resultat->vider();
    delete resultat;
}

//------------------------------------------------- Surcharge d'opérateurs
// Catalogue & Catalogue::operator = ( const Catalogue & unCatalogue )
// // Algorithme :
// //
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
catalogueTrajet = new LinkedList();
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
delete catalogueTrajet;
} //----- Fin de ~Catalogue

