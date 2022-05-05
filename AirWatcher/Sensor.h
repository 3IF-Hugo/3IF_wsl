/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
using namespace std;
#include <string>
// #if ! defined ( SENSOR_H )
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include "PrivateUser.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
//enum StateSensorUser { Reliable, Unreliable };
//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
//
//
//------------------------------------------------------------------------

class Sensor
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool SetStateUnreliable();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getSensorID();
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

    StateSensorUser getState();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Sensor & operator = ( const Sensor & unSensor );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Sensor ( const Sensor & unSensor );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Sensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Sensor(string id, double lat, double log);

    virtual ~Sensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string sensorID;
    double latitude;
    double longitude;
    StateSensorUser state;
}; 

//-------------------------------- Autres définitions dépendantes de <Sensor>

// #endif // XXX_H

