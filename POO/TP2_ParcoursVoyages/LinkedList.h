/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( LIST_H )
#define LIST_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class LinkedList
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void ajouter(Trajet *unTrajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void afficher();
    // Mode d'emploi :
    //
    // Contrat :
    //

    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Rechercher(Trajet *unTrajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    //Trajet & operator = ( const Trajet & unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LinkedList ();

    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    //LinkedList ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LinkedList ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Element *elemDebut;
Element *elemFin;

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // LIST_H

