/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( ELEMENT_H )
#define ELEMENT_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Element
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Trajet * getTrajet ();
    //Mode d'emploi :
    //
    //Contrat :
    //

    void setTrajet (Trajet *unTrajet);
    //Mode d'emploi :
    //
    //Contrat :
    //

    Element * getElemNext ();
    //Mode d'emploi :
    //
    //Contrat :
    //

    void setElemNext (Element *unElem);
    //Mode d'emploi :
    //
    //Contrat :
    //

    // type Méthode ( liste des paramètres );
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
    Element ( Trajet *unTrajet);

    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Element ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Element ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Trajet *trajet;
Element *elemNext;

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // ELEMENT_H

