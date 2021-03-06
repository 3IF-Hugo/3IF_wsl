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
#include <unistd.h>
//------------------------------------------------------ Include personnel
#include "UtilityService.h"
#include "Measurement.h"
#include "Sensor.h"


//------------------------------------------------------------- Constantes
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

double * UtilityService::calculateMean(map<string, Sensor> sensors, time_t date, multimap<Sensor,Measurement> mesureO3, multimap<Sensor,Measurement> mesureSO2, multimap<Sensor,Measurement> mesureNO2, multimap<Sensor,Measurement> mesurePM10, list<PrivateUser> & listePrivateUsers)
{
    //On crée un tableau qui contiendra la moyenne des mesures pour chaque attribut
    //returnArray[0] : O3, returnArray[1] : SO2, returnArray[2] : NO2, returnArray[3] : PM10
    double* returnArray = new double[4];
    for(int i=0; i<4; i++){
        returnArray[i] = 0;
    }
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
        if(itList!=sensors.end() && ecartSeconds == 0)
        {
            returnArray[0] += it->second.getValue(); 
            for(list<PrivateUser>::iterator itPU = listePrivateUsers.begin(); itPU != listePrivateUsers.end(); ++itPU)
            {
                if(itPU->getSensorId().compare(it->first.getSensorID()) == 0 && itPU->getStatut() == 0)
                {
                    itPU->setScorePlus1();
                    break;
                }
            }  
        }
    }
    for(multimap<Sensor,Measurement>::iterator it = mesureSO2.begin(); it != mesureSO2.end(); ++it)
    {
        //On cherche si le sensor se trouve dans la liste "sensors" donnée en paramètre
        itList = sensors.find(it->first.getSensorID());
        //Si itList!=sensors.end() : *it se trouve dans la liste "sensors"
        //On vérifie que la date est valide : date égale à celle donnée en paramètre
        ecartSeconds = abs(difftime( it->second.getTimestamp(), date ));
        if(itList!=sensors.end() && ecartSeconds == 0)
        {
            returnArray[1] += it->second.getValue();
            for(list<PrivateUser>::iterator itPU = listePrivateUsers.begin(); itPU != listePrivateUsers.end(); ++itPU)
            {
                if(itPU->getSensorId().compare(it->first.getSensorID()) == 0 && itPU->getStatut() == 0)
                {
                    itPU->setScorePlus1();
                    break;
                }
            }  
        }
    }
    for(multimap<Sensor,Measurement>::iterator it = mesureNO2.begin(); it != mesureNO2.end(); ++it)
    {
        //On cherche si le sensor se trouve dans la liste "sensors" donnée en paramètre
        itList = sensors.find(it->first.getSensorID());
        //Si itList!=sensors.end() : *it se trouve dans la liste "sensors"
        //On vérifie que la date est valide : date égale à celle donnée en paramètre
        ecartSeconds = abs(difftime( it->second.getTimestamp(), date ));
        if(itList!=sensors.end() && ecartSeconds == 0)
        {
            returnArray[2] += it->second.getValue();
            for(list<PrivateUser>::iterator itPU = listePrivateUsers.begin(); itPU != listePrivateUsers.end(); ++itPU)
            {
                if(itPU->getSensorId().compare(it->first.getSensorID()) == 0 && itPU->getStatut() == 0)
                {
                    itPU->setScorePlus1();
                    break;
                }
            }     
        }
    }
    for(multimap<Sensor,Measurement>::iterator it = mesurePM10.begin(); it != mesurePM10.end(); ++it)
    {
        //On cherche si le sensor se trouve dans la liste "sensors" donnée en paramètre
        itList = sensors.find(it->first.getSensorID());
        //Si itList!=sensors.end() : *it se trouve dans la liste "sensors"
        //On vérifie que la date est valide : date égale à celle donnée en paramètre
        ecartSeconds = abs(difftime( it->second.getTimestamp(), date ));
        if(itList!=sensors.end() && ecartSeconds == 0)
        {
            returnArray[3] += it->second.getValue();
            for(list<PrivateUser>::iterator itPU = listePrivateUsers.begin(); itPU != listePrivateUsers.end(); ++itPU)
            {
                if(itPU->getSensorId().compare(it->first.getSensorID()) == 0 && itPU->getStatut() == 0)
                {
                    itPU->setScorePlus1();
                    break;
                }
            }  
        }
    }
    //On calcule la moyenne pour chaque type de mesures en divisant par la taille de "sensors" donc le nombre de mesures prises en compte
    for(int i = 0; i < 4; ++i)
    {
        returnArray[i] /= sensors.size();
        cout << "valeur de retour [" <<i<< "] = " <<returnArray[i] << endl;
    }
    return returnArray;
}

bool UtilityService::analyseSensor(map<string, Sensor> & allSensors, list<string> & sensorsDefecteux, string sensorAnalyseID, double sensorAnalyseLatitude, double sensorAnalyseLongitude, double rayon, multimap<Sensor,Measurement> mesureO3, multimap<Sensor,Measurement> mesureSO2, multimap<Sensor,Measurement> mesureNO2, multimap<Sensor,Measurement> mesurePM10, list<PrivateUser> & listePrivateUsers)
{
    map<string, Sensor> listeSensorCompare;
    double *moyenneMesure;
    double mesureSensor[4];
    double distanceSensors;
    double pourcentageEcart;
    unsigned long ecartSeconds;
    time_t dateMeasurement;

    for ( map<string, Sensor>::iterator it = allSensors.begin ( ) ; it != allSensors.end ( ) ; ++it )
    {
        distanceSensors = sqrt(pow(it->second.getLatitude()-sensorAnalyseLatitude,2)+pow(it->second.getLongitude()-sensorAnalyseLongitude,2));
        if(distanceSensors <= rayon && (it->first).compare(sensorAnalyseID) != 0)
        {
            listeSensorCompare.insert(make_pair(it->first, it->second));
        }
    }

    if(listeSensorCompare.size() > 0)
    {
        //Stockage des 4 dernières mesures faites par le capteur à analyser dans le tableau mesureSensor
        for(multimap<Sensor,Measurement>::iterator it = mesureO3.begin(); it != mesureO3.end(); ++it)
        {
            if((it->first).getSensorID().compare(sensorAnalyseID) == 0)
            {
                mesureSensor[0] = (it->second).getValue();
                dateMeasurement = it->second.getTimestamp(); 
                break;
            }
        }
        
        for(multimap<Sensor,Measurement>::iterator it = mesureSO2.begin(); it != mesureSO2.end(); ++it)
        {
            ecartSeconds = abs(difftime( it->second.getTimestamp(), dateMeasurement ));
            if((it->first).getSensorID().compare(sensorAnalyseID) == 0 && ecartSeconds == 0)
            {   
                mesureSensor[1] = (it->second).getValue();
                break;
            }
        }

        for(multimap<Sensor,Measurement>::iterator it = mesureNO2.begin(); it != mesureNO2.end(); ++it)
        {
            ecartSeconds = abs(difftime( it->second.getTimestamp(), dateMeasurement ));
            if((it->first).getSensorID().compare(sensorAnalyseID) == 0 && ecartSeconds == 0)
            {
                mesureSensor[2] = (it->second).getValue();   
                break;
            }
        }

        for(multimap<Sensor,Measurement>::iterator it = mesurePM10.begin(); it != mesurePM10.end(); ++it)
        {
            ecartSeconds = abs(difftime( it->second.getTimestamp(), dateMeasurement ));
            if((it->first).getSensorID().compare(sensorAnalyseID) == 0 && ecartSeconds == 0)
            {  
                mesureSensor[3] = (it->second).getValue(); 
                break; 
            }
        }
        //Stockage de la moyenne des mesures des capteurs proches dans le tableau moyenneMesure
        moyenneMesure = calculateMean(listeSensorCompare,dateMeasurement,mesureO3,mesureSO2,mesureNO2,mesurePM10, listePrivateUsers);
        double moyennePourcentageEcart = 0;
        //On vérifie si l'écart entre la moyenne des mesures et la mesure du capteur est inférieur à +/-25%
        for(int i=0; i<4 ;++i)
        {
            pourcentageEcart = abs(moyenneMesure[i]-mesureSensor[i]) / mesureSensor[i] *100.0;
            moyennePourcentageEcart += pourcentageEcart;
            switch(i)
            {
                case 0:
                {
                    cout << "O3 : " << endl;
                    break;
                }
                case 1:
                {
                    cout << "SO2 : " << endl;
                    break;
                }
                case 2:
                {
                    cout << "NO2 : " << endl;
                    break;
                }
                case 3:
                {
                    cout << "PM10 : " << endl;
                    break;
                }
            }
            cout << "Moyenne mesure : " << moyenneMesure[i] << endl;
            cout << "Mesure ref : " << mesureSensor[i] << endl;
            cout << "Pourcentage ecart : " << pourcentageEcart << endl << endl; 
        }
        delete(moyenneMesure);
        moyennePourcentageEcart /= 4;
        cout << "Moyenne pourcetage écart : " << moyennePourcentageEcart << endl;

        if(moyennePourcentageEcart > 20)
        {
            allSensors.erase(sensorAnalyseID);
            sensorsDefecteux.push_back(sensorAnalyseID);
            for(list<PrivateUser>::iterator itPU = listePrivateUsers.begin(); itPU != listePrivateUsers.end(); ++itPU)
            {
                if(itPU->getSensorId().compare(sensorAnalyseID) == 0 && itPU->getStatut() == 0)
                {
                    itPU->setUnreliable();
                    break;
                }
            }
            return false;
        }else
        {
            return true;
        }
        
    }
    else
    {
        cerr << "Aucun capteur trouvé pour comparer le capteur" << endl;
        return false;
    }
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

