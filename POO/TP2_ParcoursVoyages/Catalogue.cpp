/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::AjouterTrajetSimple ( const char* villeDepart, const char* villeArrivee, const char* moyenTransport )
{
    TrajetSimple *nouveauTrajet = new TrajetSimple ( villeDepart, villeArrivee, moyenTransport );
    catalogueTrajet->ajouter ( nouveauTrajet );
} //----- Fin de Méthode

TrajetCompose* Catalogue::AjouterTrajetCompose ( const char* villeDepart, const char* villeArrivee )
{
    TrajetCompose *nouveauTrajet = new TrajetCompose ( villeDepart, villeArrivee );
    catalogueTrajet->ajouter ( nouveauTrajet );
    return nouveauTrajet;
} //----- Fin de Méthode

void Catalogue::AjouterSousTrajetSimple(const char* villeDepart, const char* villeArrivee, const char* moyenTransport, TrajetCompose *unTrajetComp)
{
    TrajetSimple *nouveauTrajet = new TrajetSimple ( villeDepart, villeArrivee, moyenTransport );
    unTrajetComp->ajouter(nouveauTrajet);
}

void Catalogue::Afficher()
{
    catalogueTrajet->afficher();
}

void Catalogue::Rechercher(const char* depart, const char* arrivee)
{

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


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

