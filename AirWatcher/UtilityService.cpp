/*************************************************************************
                           UtilityService  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Réalisation de la classe <UtilityService> (fichier UtilityService.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <cmath>
#include <chrono>
#include <ctime>
#include <algorithm>

//------------------------------------------------------ Include personnel
#include "UtilityService.h"
#include "Measurement.h"
#include "Sensor.h"


//------------------------------------------------------------- Constantes
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

double * UtilityService::calculateMean(map<string, Sensor> sensors, Sensor sensorRef, time_t date, multimap<Sensor,Measurement> mesureO3, multimap<Sensor,Measurement> mesureSO2, multimap<Sensor,Measurement> mesureNO2, multimap<Sensor,Measurement> mesurePM10 )
{
    //On crée un tableau qui contiendra la moyenne des mesures pour chaque attribut
    //returnArray[0] : O3, returnArray[1] : SO2, return Array[2] : NO2, return Array[3] : PM10
    double* returnArray = new double[4];
    //On récupère les 4 mesures faites par chaque capteur de la liste "sensors" à la date "date" donnée en paramètres 
    map<string, Sensor>::iterator itList;
    unsigned long ecartSeconds;

    for(multimap<Sensor,Measurement>::iterator it = mesureO3.begin(); it != mesureO3.end(); ++it)
    {
        //On cherche si le sensor se trouve dans la liste "sensors" donnée en paramètre
        itList = sensors.find(it->first.getSensorID());
        //Si itList!=sensors.end() : *it se trouve dans la liste "sensors"
        //On vérifie que la date est valide : date égale à celle donnée en paramètre
        ecartSeconds = abs(difftime( it->second.getTimestamp(), date ));
        if(itList!=sensors.end() && ecartSeconds<86400)
        {
            returnArray[0] += it->second.getValue();    
        }
    }
    for(multimap<Sensor,Measurement>::iterator it = mesureSO2.begin(); it != mesureSO2.end(); ++it)
    {
        //On cherche si le sensor se trouve dans la liste "sensors" donnée en paramètre
        itList = sensors.find(it->first.getSensorID());
        //Si itList!=sensors.end() : *it se trouve dans la liste "sensors"
        //On vérifie que la date est valide : date égale à celle donnée en paramètre
        ecartSeconds = abs(difftime( it->second.getTimestamp(), date ));
        if(itList!=sensors.end() && ecartSeconds<86400)
        {
            returnArray[1] += it->second.getValue();    
        }
    }
    for(multimap<Sensor,Measurement>::iterator it = mesureNO2.begin(); it != mesureNO2.end(); ++it)
    {
        //On cherche si le sensor se trouve dans la liste "sensors" donnée en paramètre
        itList = sensors.find(it->first.getSensorID());
        //Si itList!=sensors.end() : *it se trouve dans la liste "sensors"
        //On vérifie que la date est valide : date égale à celle donnée en paramètre
        ecartSeconds = abs(difftime( it->second.getTimestamp(), date ));
        if(itList!=sensors.end() && ecartSeconds<86400)
        {
            returnArray[2] += it->second.getValue();    
        }
    }
    for(multimap<Sensor,Measurement>::iterator it = mesurePM10.begin(); it != mesurePM10.end(); ++it)
    {
        //On cherche si le sensor se trouve dans la liste "sensors" donnée en paramètre
        itList = sensors.find(it->first.getSensorID());
        //Si itList!=sensors.end() : *it se trouve dans la liste "sensors"
        //On vérifie que la date est valide : date égale à celle donnée en paramètre
        ecartSeconds = abs(difftime( it->second.getTimestamp(), date ));
        if(itList!=sensors.end() && ecartSeconds<86400)
        {
            returnArray[3] += it->second.getValue();    
        }
    }
    //On calcule la moyenne pour chaque type de mesures en divisant par la taille de "sensors" donc le nombre de mesures prises en compte
    for(int i = 0; i < my_sizeof(returnArray)/my_sizeof(returnArray[0]) ; ++i)
    {
        returnArray[i] /= sensors.size();
    }
    return returnArray;
}

bool UtilityService::analyseSensor(map<string, Sensor> allSensors, Sensor sensorAnalyse, double rayon, time_t date, multimap<Sensor,Measurement> mesureO3, multimap<Sensor,Measurement> mesureSO2, multimap<Sensor,Measurement> mesureNO2, multimap<Sensor,Measurement> mesurePM10)
{
    map<string, Sensor> listSensorDefectueux;
    double *moyenneMesure;
    Measurement mesureSensor[4];
    double distanceSensors;
    double pourcentageEcart;
    double latitudeRef = sensorAnalyse.getLatitude();
    double longitudeRef = sensorAnalyse.getLongitude();
    unsigned long ecartSeconds;

    for ( map<string, Sensor>::iterator it = allSensors.begin ( ) ; it != allSensors.end ( ) ; ++it )
    {
        distanceSensors = sqrt(pow(it->second.getLatitude()-latitudeRef,2)+pow(it->second.getLongitude()-longitudeRef,2));
        if(distanceSensors <= rayon)
        {
            listSensorDefectueux.insert(make_pair(it->first, it->second));
        }
    }
    //Stockage des 4 dernières mesures faites par le capteur à analyser dans le tableau mesureSensor
    for(multimap<Sensor,Measurement>::iterator it = mesureO3.begin(); it != mesureO3.end(); ++it)
    {
        ecartSeconds = abs(difftime( it->second.getTimestamp(), date ));
        if((it->first).getSensorID().compare(sensorAnalyse.getSensorID()) == 0 && ecartSeconds<86400)
        {
            mesureSensor[0] = it->second;    
        }
    }
    for(multimap<Sensor,Measurement>::iterator it = mesureSO2.begin(); it != mesureSO2.end(); ++it)
    {
        ecartSeconds = abs(difftime( it->second.getTimestamp(), date ));
        if((it->first).getSensorID().compare(sensorAnalyse.getSensorID()) == 0 && ecartSeconds<86400)
        {
            mesureSensor[1] = it->second;    
        }
    }
    for(multimap<Sensor,Measurement>::iterator it = mesureNO2.begin(); it != mesureNO2.end(); ++it)
    {
        ecartSeconds = abs(difftime( it->second.getTimestamp(), date ));
        if((it->first).getSensorID().compare(sensorAnalyse.getSensorID()) == 0 && ecartSeconds<86400)
        {
            mesureSensor[2] = it->second;    
        }
    }
    for(multimap<Sensor,Measurement>::iterator it = mesurePM10.begin(); it != mesurePM10.end(); ++it)
    {
        ecartSeconds = abs(difftime( it->second.getTimestamp(), date ));
        if((it->first).getSensorID().compare(sensorAnalyse.getSensorID()) == 0 && ecartSeconds<86400)
        {
            mesureSensor[3] = it->second;    
        }
    }
    //Stockage de la moyenne des mesures des capteurs proches dans le tableau moyenneMesure
    moyenneMesure = calculateMean(listSensorDefectueux,sensorAnalyse,date,mesureO3,mesureSO2,mesureNO2,mesurePM10);
    //On vérifie si l'écart entre la moyenne des mesures et la mesure du capteur est inférieur à +/-5%
    for(int i=0; i<4 ;++i)
    {
        pourcentageEcart = moyenneMesure[i] / mesureSensor[i].getValue()*100.0;
        if(abs(pourcentageEcart)>5.0)
        {
            free(moyenneMesure);
            return false;
        }
    }
    free(moyenneMesure);
    return true;
}




//------------------------------------------------- Surcharge d'opérateurs
// & UtilityService::operator = ( const UtilityService & UtilityService )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
UtilityService::UtilityService ( const UtilityService & unUtilityService )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Service>" << endl;
#endif
} //----- Fin de UtilityService (constructeur de copie)


UtilityService::UtilityService ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <UtilityService>" << endl;
#endif
} //----- Fin de UtilityService


UtilityService::~UtilityService( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <UtilityService>" << endl;
#endif
} //----- Fin de ~UtilityService


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

