/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//------- Interface de la classe <Trajet> (fichier Trajet.h) -------------
#if ! defined ( LIST_H )
#define LIST_H

//#include "Element.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LinkedList>
//      Permet de crée une liste de trajets simples ou composés
//      Permet l'affichage des trajets de la liste
//      Permet la recherche d'un trajet
//------------------------------------------------------------------------

class LinkedList
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void ajouter(Trajet *unTrajet, int tri);
    // Mode d'emploi :
    //      @param1 Trajet* : un trajet
    //      @param2 int : ajout trié ou non
    // Contrat :
    //

    void afficher();

    void vider();

    void Rechercher(Trajet *unTrajet);
    // Mode d'emploi :
    //      @param1 Trajet* : un trajet

    int RechercheAvancee(const char* depart, const char* arrivee, int init, LinkedList * listeTrajet);
    // Mode d'emploi :
    //      @param1 const char* : ville de départ
    //      @param2 const char* : ville d'arrivée
    //      @param3 int : premier trajet trouvé ou non
    //      @param4 LinkedList* : liste des trajets
    //      @return int : 1 si la recherche est finie, 0 sinon
    // Contrat :
    //      Ne fonctionne qu'avec un catalogue de trajets simples

    void Sauvegarder(int mode, string fileName, const char * villeDep, const char * villeArr, int indiceDeb, int indiceFin);
    /* Mode d'emploi :
        @param1 int : le mode de sauvegarde qui implique des critères de sélection
        @param2 string : le nom du fichier de sauvegarde
        @param3 const char* : ville de départ comme critère de sélection
        @param4 const char* : ville d'arrivée comme critère de sélection
        @param5 int : numéro du premier trajet à sauvegarder (critère de sélection)
        @param6 int : numéro du dernier trajet à sauvegarder (critère de sélection)
        @call Sauvegarder : méthode de <LinkedList>
       Modes de sauvegardes :
        mode = 0 : Tout le catalogue sans critère de sélection
        mode = 1 : Que les trajets simples
        mode = 2 : Que les trajets composés
        mode = 3 : En fonction de la ville de départ
        mode = 4 : En fonction de la ville d'arrivée
        mode = 5 : En fonction de la ville de départ et de la ville d'arrivée
        mode = 6 : En fonction d'un intervalle d'indices de trajet
    */

    Element *getElemDebut();
    /* Mode d'emploi :
        @return Element* : le premier élément de la LinkedList
    */


//-------------------------------------------- Constructeurs - destructeur
    LinkedList ();

    virtual ~LinkedList ( );
    // Destructeur de <LinkedList>

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
Element *elemDebut;
Element *elemFin;

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // LIST_H

