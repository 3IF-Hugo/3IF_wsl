/*************************************************************************
                           UtilityService  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Interface de la classe <UtilityService> (fichier UtilityService.h) ----------------
using namespace std;
#include <string>
#include <iostream>
#include <list>
#include "Measurement.h"
#include "Sensor.h"
#include <map>
#if ! defined ( UTILITYSERVICE_H )
#define UTILITYSERVICE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Service>
//
//
//------------------------------------------------------------------------

class UtilityService
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    double * calculateMean(map<string, Sensor> sensors, time_t date, multimap<Sensor,Measurement> mesureO3, multimap<Sensor,Measurement> mesureSO2, multimap<Sensor,Measurement> mesureNO2, multimap<Sensor,Measurement> mesurePM10 ) ;
    // Mode d'emploi :
    //
    // Contrat :
    //

    //bool analyseSensor(map<string, Sensor> allSensors, Sensor sensorAnalyse, double rayon, multimap<Sensor,Measurement> mesureO3, multimap<Sensor,Measurement> mesureSO2, multimap<Sensor,Measurement> mesureNO2, multimap<Sensor,Measurement> mesurePM10);
    bool analyseSensor(map<string, Sensor> allSensors, string sensorAnalyseID, double sensorAnalyseLatitude, double sensorAnalyseLongitude, double rayon, multimap<Sensor,Measurement> mesureO3, multimap<Sensor,Measurement> mesureSO2, multimap<Sensor,Measurement> mesureNO2, multimap<Sensor,Measurement> mesurePM10);
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    //UtilityService & operator = ( const UtilityService & unUtilityService );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    UtilityService ( const UtilityService & unUtilityService);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    UtilityService ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~UtilityService ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <UtilityService>

#endif // UTILITYSERVICE_H