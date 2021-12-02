/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H

#include "Trajet.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//      Classe fille de Trajet.
//      Cette classe possède un attribut de plus que Trajet : 
//      le moyen de transport.
//      Elle permet l'affichage des composantes d'un trajet simple.
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher() const;

//------------------------------------------------- Surcharge d'opérateurs
   /*
    TrajetSimple & operator = ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi :
    //
    // Contrat :
    //
    */


//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const TrajetSimple & unTrajetSimple );
    // Constructeur de copie

    TrajetSimple (const char *villeDep, const char *villeArr, const char* moyTrans);
    // Mode d'emploi :
    //          @param1 const char* : ville de départ
    //          @param2 const char* : ville d'arrivée
    //          @param3 const char* : moyen de transport
    //          @using constructeur de <Trajet>
        
    TrajetSimple ( );

    virtual ~TrajetSimple ( );
    //Destructeur de <TrajetSimple>

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
char *moyenTransport;

};

#endif // TrajetSimple_H

