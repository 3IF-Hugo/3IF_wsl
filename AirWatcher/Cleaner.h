/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Interface de la classe <Cleaner> (fichier Cleaner.h) ----------------
using namespace std;
#include <string>
#include <iostream>
#if ! defined ( CLEANER_H )
#define CLEANER_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cleaner>
//
//
//------------------------------------------------------------------------

class Cleaner
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    string getCleanerId();
    // Mode d'emploi :
    //
    // Contrat :
    //

    double getLatitude();
    // Mode d'emploi :
    //
    // Contrat :
    //

    double getLongitude();
    // Mode d'emploi :
    //
    // Contrat :
    //

    time_t getTimestampStart();
    // Mode d'emploi :
    //
    // Contrat :
    //

    time_t getTimestampStop();
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Cleaner & operator = ( const Cleaner & unCleaner );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Cleaner ( const Cleaner & unCleaner );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cleaner (string cleanerId = "", double latitude = 0.0, double longitude = 0.0, time_t timestampStart = 0, time_t timestampStop = 0);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cleaner ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string cleanerId;
    double latitude;
    double longitude;
    time_t timestampStart;
    time_t timestampStop;
};

//-------------------------------- Autres définitions dépendantes de <Cleaner>

#endif // CLEANER_H