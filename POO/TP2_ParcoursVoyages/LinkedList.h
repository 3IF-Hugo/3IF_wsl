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

    //Element * getElemDebut();

//------------------------------------------------- Surcharge d'opérateurs
    //Trajet & operator = ( const Trajet & unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LinkedList ();

    virtual ~LinkedList ( );
    // Destructeur de <LinkedList>

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Element *elemDebut;
Element *elemFin;

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // LIST_H

