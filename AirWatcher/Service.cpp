/*************************************************************************
                           Service  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Réalisation de la classe <Service> (fichier Service.cpp) ------------

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
#include "Service.h"
#include "Sensor.h"
#include "Measurement.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Service::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

double** Service::calculerStatistiques(list <Sensor> sensors, multimap <Sensor, Measurement> tousMeasurements, list <string> listeTypesDonnees, double latitude, double longitude, double rayonZone, int nbrJours){
    double [listeTypesDonnees.size()] [3] returnArray = {0.0};
    list<Sensor> listSensorsArea;
    int nbMeasurements;
    double distance;
    
    // Recuperer les capteurs dans la zone choisie
    for(list <Sensor>::iterator it = sensors.begin(); it != sensors.end(); it++){
        // Calcul de la distance simple en 2D, amelioration possible avec la formule de haversine
        distance = sqrt(pow(it->getLatitude() - latitude, 2) + pow(it->getLongitude() - longitude, 2)); 
        if (distance < rayonZone){
            listSensorsArea.push_back(*it);
        }
    }

    long long borneSup = static_cast<long long>(time(0)); //maintenant, en secondes
    long long borneInf = borneSup - nbrJours*24*3600;
    int iterateur = 0; // Variable pour remplacer l'index de l'element pointe par 'itl' - a la place de la fonction distance(listTypesDonnees, itl)

    // Calculer la moyenne, le min et max pour chaque type de donnees
    for(list <string>::iterator itl = listeTypesDonnees.begin(); itl != listeTypesDonnees.end(); itl++){
        for(auto itm = tousMeasurements.rbegin(); itm != tousMeasurements.rend(); itm++){
            
            // Moyenne (Calcluer la somme et diviser a la fin de cette boucle)
            if (static_cast<long long>(itm->second.getTimestamp()) < borneSup && static_cast<long long>(itm->second.getTimeStamp()) > borneInf && itm->second.attribute.attributeID == itl){
                //returnArray[distance(listTypesDonnees, itl)][0] += itm->second.value;
                returnArray[iterateur][0] += itm->second.getValue();
                
                // Max
                if (itm->second.value > returnArray[iterateur][1])
                {
                    //returnArray[distance(listTypesDonnees, itl)][1] = itm->second.value;
                    returnArray[iterateur][1] = itm->second.getValue();
                }

                // Min
                if (itm->second.value < returnArray[iterateur][2])
                {
                    //returnArray[distance(listTypesDonnees, itl)][2] = itm->second.value;
                    returnArray[iterateur][2] = itm->second.getValue();
                }
                nbMeasurements++;
            }
        }
        returnArray[iterateur][0] /= nbMeasurements;
        nbMeasurements = 0;
        iterateur++;
    }
    return returnArray;
}

bool Service::analyseSensor(list<Sensor> allSensors, Sensor sensorAnalyse, double rayon, time_t date, multimap<Sensor,Measurement> mesureO3, multimap<Sensor,Measurement> mesureSO2, multimap<Sensor,Measurement> mesureNO2, multimap<Sensor,Measurement> mesurePM10)
{
    list<Sensor> listSensorDefectueux;
    double moyenneMesure[4];
    Measurement mesureSensor[4];
    double distanceSensors;
    double pourcentageEcart;
    double latitudeRef = sensorAnalyse.getLatitude();
    double longitudeRef = sensorAnalyse.getLongitude();
    for ( list < Sensor >::iterator it = allSensors.begin ( ) ; it != allSensors.end ( ) ; ++it )
    {
        distanceSensors = sqrt(pow(it->getLatitude()-latitudeRef,2)+pow(it->getLongitude()-longitudeRef,2));
        if(distanceSensors <= rayon)
        {
            listSensorDefectueux.push_back(*it);
        }
    }
    //Stockage des 4 dernières mesures faites par le capteur à analyser dans le tableau mesureSensor
    for(multimap<Sensor,Measurement>::iterator it = mesureO3.begin(); it != mesureO3.end(); ++it)
    {
        //??? Surcharge du "==" pour Sensor ???
        if(it == sensorAnalyse && it->second->timestamp == date)
        {
            mesureSensor[0] = it->second->value;    
        }
    }
    for(multimap<Sensor,Measurement>::iterator it = mesureSO2.begin(); it != mesureSO2.end(); ++it)
    {
        if(it == sensorAnalyse && it->second->timestamp == date)
        {
            mesureSensor[1] = it->second->value;    
        }
    }
    for(multimap<Sensor,Measurement>::iterator it = mesureNO2.begin(); it != mesureNO2.end(); ++it)
    {
        if(it == sensorAnalyse && it->second->timestamp == date)
        {
            mesureSensor[2] = it->second->value;    
        }
    }
    for(multimap<Sensor,Measurement>::iterator it = mesurePM10.begin(); it != mesurePM10.end(); ++it)
    {
        if(it == sensorAnalyse && it->second->timestamp == date)
        {
            mesureSensor[3] = it->second->value;    
        }
    }
    //Stockage de la moyenne des mesures des capteurs proches dans le tableau moyenneMesure
    moyenneMesure = calculateMean(listSensorDefectueux,sensorAnalyse,date,mesureO3,mesureSO2,mesureNO2,mesurePM10);
    //On vérifie si l'écart entre la moyenne des mesures et la mesure du capteur est inférieur à +/-5%
    for(int i=0; i<mesureSensor.size();++i)
    {
        pourcentageEcart = moyenneMesure[i]/mesureSensor[i]*100;
        if(abs(pourcentageEcart)>5.0)
        {
            return false;
        }
    }
    return true;
}

double * Service::calculateMean(list<Sensor> sensors, Sensor sensorRef, time_t date, multimap<Sensor,Measurement> mesureO3, multimap<Sensor,Measurement> mesureSO2, multimap<Sensor,Measurement> mesureNO2, multimap<Sensor,Measurement> mesurePM10 )
{
    //On crée un tableau qui contiendra la moyenne des mesures pour chaque attribut
    //returnArray[0] : O3, returnArray[1] : SO2, return Array[2] : NO2, return Array[3] : PM10
    double returnArray[4] = {0.0,0.0,0.0,0.0};
    //On récupère les 4 mesures faites par chaque capteur de la liste "sensors" à la date "date" donnée en paramètres 
    list<Sensor>::iterator itList;
    for(multimap<Sensor,Measurement>::iterator it = mesureO3.begin(); it != mesureO3.end(); ++it)
    {
        //On cherche si le sensor se trouve dans la liste "sensors" donnée en paramètre
        itList = find(sensors.begin(), sensors.end(), *it);
        //Si itList!=sensors.end() : *it se trouve dans la liste "sensors"
        //On vérifie que la date est valide : date égale à celle donnée en paramètre
        if(itList!=sensors.end() && it->second->timestamp == date)
        {
            returnArray[0] += it->second->value;    
        }
    }
    for(multimap<Sensor,Measurement>::iterator it = mesureSO2.begin(); it != mesureSO2.end(); ++it)
    {
        //On cherche si le sensor se trouve dans la liste "sensors" donnée en paramètre
        itList = find(sensors.begin(), sensors.end(), *it);
        //Si itList!=sensors.end() : *it se trouve dans la liste "sensors"
        //On vérifie que la date est valide : date égale à celle donnée en paramètre
        if(itList!=sensors.end() && it->second->timestamp == date)
        {
            returnArray[1] += it->second->value;    
        }
    }
    for(multimap<Sensor,Measurement>::iterator it = mesureNO2.begin(); it != mesureNO2.end(); ++it)
    {
        //On cherche si le sensor se trouve dans la liste "sensors" donnée en paramètre
        itList = find(sensors.begin(), sensors.end(), *it);
        //Si itList!=sensors.end() : *it se trouve dans la liste "sensors"
        //On vérifie que la date est valide : date égale à celle donnée en paramètre
        if(itList!=sensors.end() && it->second->timestamp == date)
        {
            returnArray[2] += it->second->value;    
        }
    }
    for(multimap<Sensor,Measurement>::iterator it = mesurePM10.begin(); it != mesurePM10.end(); ++it)
    {
        //On cherche si le sensor se trouve dans la liste "sensors" donnée en paramètre
        itList = find(sensors.begin(), sensors.end(), *it);
        //Si itList!=sensors.end() : *it se trouve dans la liste "sensors"
        //On vérifie que la date est valide : date égale à celle donnée en paramètre
        if(itList!=sensors.end() && it->second->timestamp == date)
        {
            returnArray[3] += it->second->value;    
        }
    }
    //On calcule la moyenne pour chaque type de mesures en divisant par la taille de "sensors" donc le nombre de mesures prises en compte
    for(int i = 0; i < sizeof(returnArray)/sizeof(returnArray[0]); ++i)
    {
        returnArray[i] /= sensors.size();
    }
    return returnArray;
}



//------------------------------------------------- Surcharge d'opérateurs
Service & Service::operator = ( const Service & unService )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Service::Service ( const Service & unService )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Service>" << endl;
#endif
} //----- Fin de Service (constructeur de copie)


Service::Service ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Service>" << endl;
#endif
} //----- Fin de Service


Service::~Service ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Service>" << endl;
#endif
} //----- Fin de ~Service


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

