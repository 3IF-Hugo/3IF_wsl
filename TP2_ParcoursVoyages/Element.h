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
// Constitue un maillon de la liste chaînée
// Contient un trajet et pointe sur l'élément suivant
//------------------------------------------------------------------------

class Element
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Trajet * getTrajet ();
    //Mode d'emploi :
    //      @return Trajet*: le trajet correpsondant à l'élément

    void setTrajet (Trajet *unTrajet);
    //Mode d'emploi :
    //      @param1 Trajet*: un trajet 

    Element * getElemNext ();
    //Mode d'emploi :
    //      @return Element*: le prochain élément

    void setElemNext (Element *unElem);
    //Mode d'emploi :
    //      @param1 Element* : l'élément suivant

//-------------------------------------------- Constructeurs - destructeur
    Element ( Trajet *unTrajet);
    // Mode d'emploi (constructeur de copie) :
    //      @param1 Trajet* : un trajet

    Element ( );

    virtual ~Element ( );

//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Attributs protégés
Trajet *trajet;
Element *elemNext;

};

#endif // ELEMENT_H

