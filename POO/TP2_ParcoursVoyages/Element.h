/*************************************************************************
                           Element  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//------ Interface de la classe <Element> (fichier Element.h) --------------
#if ! defined ( ELEMENT_H )
#define ELEMENT_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Element>
//
//
//------------------------------------------------------------------------

class Element
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Trajet * getTrajet ();

    void setTrajet (Trajet *unTrajet);
    //Mode d'emploi :
    //      @param1 Trajet*: un trajet 

    Element * getElemNext ();

    void setElemNext (Element *unElem);
    //Mode d'emploi :
    //      @param1 Element* : l'élément suivant


//------------------------------------------------- Surcharge d'opérateurs
    //Trajet & operator = ( const Trajet & unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Element ( Trajet *unTrajet);
    // Mode d'emploi (constructeur de copie) :
    //      @param1 Trajet* : un trajet

    Element ( );

    virtual ~Element ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Trajet *trajet;
Element *elemNext;

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // ELEMENT_H

