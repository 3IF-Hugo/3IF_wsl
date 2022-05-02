/*************************************************************************
                           Service  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Interface de la classe <Service> (fichier Service.h) ----------------
using namespace std;
#include <string>
#include <iostream>
#include <list>
#include "Sensor.h"
#include <map>
#if ! defined ( SERVICE_H )
#define SERVICE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Service>
//
//
//------------------------------------------------------------------------

class Service
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    double** calculerStatistiques(list<Sensor> sensors, multimap <Sensor, Measurement> tousMeasurements, list<string> listeTypesDonnees, double latitude, double longitude, double rayonZone, int nbrJours);
    // Mode d'emploi :
    //
    // Contrat :
    //

    list<Sensor> trouverZonesSimilaires(string idCapteurRef, list<string> listeTypesDonnees, int pourcentageOpt);
    // Mode d'emploi :
    //
    // Contrat :
    //

    double * qualiteAirZone(double latitude, double longitude, double rayon = 5.0) ;
    // Mode d'emploi :
    //
    // Contrat :
    //

    int impactPurificateur(string idPurificateur) ;
    // Mode d'emploi :
    //
    // Contrat :
    //

    double * calculateMean(list<Sensor> sensors, Sensor sensorRef, time_t date, multimap<Sensor,Measurement> mesureO3, multimap<Sensor,Measurement> mesureSO2, multimap<Sensor,Measurement> mesureNO2, multimap<Sensor,Measurement> mesurePM10 ) ;
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool analyseSensor(list<Sensor> allSensors, Sensor sensorAnalyse, double rayon, time_t date, multimap<Sensor,Measurement> mesureO3, multimap<Sensor,Measurement> mesureSO2, multimap<Sensor,Measurement> mesureNO2, multimap<Sensor,Measurement> mesurePM10);
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Service & operator = ( const Service & unService );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Service ( const Service & unService );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Service ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Service ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Service>

#endif // SERVICE_H