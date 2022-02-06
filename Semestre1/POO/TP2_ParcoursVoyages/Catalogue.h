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
// Crée les trajets et les insère dans une LinkedList
// Appelle des méthodes de LinkedList pour la recherche de trajet
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

   void RechercheAvancee(const char* depart, const char* arrivee);
    /* Méthode pour rechercher un trajet avec la possibilité de constituer un nouveau trajet à partir de ceux existants:
        @param1 const char* : ville de départ
        @param2 const char* : ville d'arrivée
    */

    void Sauvegarder(int mode, string nomDuFichier);
    /* Méthode pour sauvegarder le catalogue actuel dans un fichier txt
        @param1 int : le mode de sauvegarde qui implique des critères de sélection
        @param2 string : le nom du fichier de sauvegarde
        @call Sauvegarder : méthode de <LinkedList>
    */

    void Charger(int mode, string nomDuFichier, Catalogue *catalogueInput);
    /* Méthode pour appeller la méthode spécifique au mode sélectionné
        @param1 int : le mode de chargement qui implique des critères de sélection
        @param2 string : le nom du fichier de chargement
        @param3 Catalogue : le catalogue à mettre à jour
        @call ChargerModeX : appelle la méthode correspondant au mode sélectionné
    */

    void GetTrajetSimple(ifstream & fic, string str, Catalogue *catalogueInput);
    /* Méthode pour créer un trajet simple à partir de la lecture du fichier
        @param1 ifstream : le fichier dans lequel on agit
        @param2 string : un buffer, le mot courant
        @param3 Catalogue : le catalogue à mettre à jour
        @call AjouterTrajetSimple : méthode de <Catalogue>
    */

    void GetTrajetSimpleCondition(ifstream &fic, string str, Catalogue *catalogueInput, char * ville1, char * ville2, int choix1,  int choix2);
    /* Méthode pour créer un trajet simple à partir de la lecture du fichier s'il répond à la condition
        @param1 ifstream : le fichier dans lequel on agit
        @param2 string : un buffer, le mot courant
        @param3 Catalogue : le catalogue à mettre à jour
        @param4-5 char* : la ville de départ et d'arrivée sélectionnées
        @param6-7 int : les numéros correspondant à la place de la ville de départ et d'arrivée
        @call AjouterTrajetSimple : méthode de <Catalogue>
    */

    void GetTrajetCompose(ifstream & fic, string str, Catalogue *catalogueInput);
    /* Méthode pour créer un trajet composé à partir de la lecture du fichier
        @param1 ifstream : le fichier dans lequel on agit
        @param2 string : un buffer, le mot courant
        @param3 Catalogue : le catalogue à mettre à jour
        @call AjouterTrajetCompose : méthode de <Catalogue>
        @call AjouterSousTrajetSimple : méthode de <Catalogue>
    */

    void GetTrajetComposeCondition(ifstream &fic, string str, Catalogue *catalogueInput, char * ville1, char * ville2, int choix1,  int choix2);
    /* Méthode pour créer un trajet composé à partir de la lecture du fichier s'il répond à la condition
        @param1 ifstream : le fichier dans lequel on agit
        @param2 string : un buffer, le mot courant
        @param3 Catalogue : le catalogue à mettre à jour
        @param4-5 char* : la ville de départ et d'arrivée sélectionnées
        @param6-7 int : les numéros correspondant à la place de la ville de départ et d'arrivée
        @call AjouterTrajetCompose : méthode de <Catalogue>
        @call AjouterSousTrajetSimple : méthode de <Catalogue>
    */

    void ChargerMode1(string nomDuFichier, Catalogue *catalogueInput);
    /* Méthode spécifique au mode 1 pour charger tous les trajets d'un fichier texte dans le catalogue actuel
        @param1 string : le nom du fichier de chargement
        @param2 Catalogue : le catalogue à mettre à jour
        @call GetTrajetSimple : méthode de <Catalogue>
        @call GetTrajetCompose : méthode de <Catalogue>
    */

    void ChargerMode2(string nomDuFichier, Catalogue *catalogueInput);
    /* Méthode spécifique au mode 2 pour charger les trajets d'un fichier texte dans le catalogue actuel
        @param1 string : le nom du fichier de chargement
        @param2 Catalogue : le catalogue à mettre à jour
        @call GetTrajetSimple : méthode de <Catalogue>
        @call GetTrajetCompose : méthode de <Catalogue>
    */

    void ChargerMode3(string nomDuFichier, Catalogue *catalogueInput);
    /* Méthode spécifique au mode 3 et similaire à ChargerMode4 et ChargerMode5 
        Elles servent à charger les trajets d'un fichier texte dans le catalogue actuel suivant ville de départ/arrivée
        @param1 string : le nom du fichier de chargement
        @param2 Catalogue : le catalogue à mettre à jour
        @call GetTrajetSimpleCondition : méthode de <Catalogue>
        @call GetTrajetComposeCondition : méthode de <Catalogue>
    */

    void ChargerMode4(string nomDuFichier, Catalogue *catalogueInput);

    void ChargerMode5(string nomDuFichier, Catalogue *catalogueInput);

    void ChargerMode6(string nomDuFichier, Catalogue *catalogueInput);
    /* Méthode spécifique pour sélectionner un certain nombre de trajets d'un fichier texte dans le catalogue actuel
        @param1 string : le nom du fichier de chargement
        @param2 Catalogue : le catalogue à mettre à jour
        @call AjouterTrajetSimple : méthode de <Catalogue>
        @call AjouterTrajetCompose : méthode de <Catalogue>
        @call AjouterSousTrajetSimple : méthode de <Catalogue>
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

//----------------------------------------------------- Attributs protégés
LinkedList *catalogueTrajet;
};

#endif // Catalogue_H

