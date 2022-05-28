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
#include "Measurement.h"
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


double** Service::calculerStatistiques(map<string, Sensor> sensors, multimap <Sensor, Measurement> tousMeasurements, map <string, int> listeTypesDonnees, double latitude, double longitude, double rayonZone, time_t dateDeb, time_t dateFin, list<PrivateUser> & listeUsers){
    double** returnArray;
    returnArray = (double**) malloc(sizeof(double*)*((int)listeTypesDonnees.size()));
    for(int i=0; i<(int)(listeTypesDonnees.size()); ++i)
    {
        returnArray[i] = (double*) calloc(3, sizeof(double));
        returnArray[i][2] = __INT_MAX__;
    }
    map<string, Sensor> listSensorsArea;
    int * nbMeasurements = new int(listeTypesDonnees.size());
    double distance;
    
    // Recuperer les capteurs dans la zone choisie
    for(map <string, Sensor>::iterator it = sensors.begin(); it != sensors.end(); it++){
        // Calcul de la distance simple en 2D, amelioration possible avec la formule de haversine
        distance = sqrt(pow(it->second.getLatitude() - latitude, 2) + pow(it->second.getLongitude() - longitude, 2)); 
        if (distance <= rayonZone){
            listSensorsArea.insert(*it);
        }
    }

    // long long borneSup = static_cast<long long>(dateFin); //date de fin, en secondes
    // long long borneInf = static_cast<long long>(dateDeb); //date de debut, en secondes
    // int iterateur = 0; // Variable pour remplacer l'index de l'element pointe par 'itl' - a la place de la fonction distance(listTypesDonnees, itl)

    // Calculer la moyenne, le min et max pour chaque type de donnees
    for(map<Sensor, Measurement>::iterator itm = tousMeasurements.begin(); itm != tousMeasurements.end(); ++itm){
        if(listSensorsArea.find(itm->first.getSensorID()) != listSensorsArea.end() && itm->second.getTimestamp() <= dateFin && itm->second.getTimestamp() >= dateDeb){
            for(list<PrivateUser>::iterator itPU = listeUsers.begin(); itPU != listeUsers.end(); ++itPU)
            {
                if(itPU->getSensorId().compare(itm->first.getSensorID()) == 0 && itPU->getStatut() == 0)
                {
                    itPU->setScorePlus1();
                    break;
                }
            }
            map <string, int>::iterator itl;
            for(itl = listeTypesDonnees.begin(); itl != listeTypesDonnees.end(); itl++){
                if(itl->first.compare(itm->second.getAttribute()) == 0){
                    break;
                }
            }
            if(itl != listeTypesDonnees.end())
            {
                returnArray[itl->second][0] += itm->second.getValue();

                if(itm->second.getValue() > returnArray[itl->second][1]){
                    returnArray[itl->second][1] = itm->second.getValue();
                }
                if(itm->second.getValue() < returnArray[itl->second][2]){
                    returnArray[itl->second][2] = itm->second.getValue();
                }
                nbMeasurements[itl->second] += 1;
            }
        }
    }
    for(map<string, int>::iterator itl = listeTypesDonnees.begin(); itl != listeTypesDonnees.end(); itl++){
        returnArray[itl->second][0] /= nbMeasurements[itl->second];
    }
    delete(nbMeasurements);


    // for(list <string>::iterator itl = listeTypesDonnees.begin(); itl != listeTypesDonnees.end(); itl++){
    //     for(map<Sensor, Measurement>::iterator itm = tousMeasurements.begin(); itm != tousMeasurements.end(); itm++){
            
    //         // Moyenne (Calculer la somme et diviser a la fin de cette boucle)
    //         if (listSensorsArea.find(itm->first.getSensorID()) != listSensorsArea.end() && itl->compare(itm->second.getAttribute()) == 0 && itm->second.getTimestamp() <= dateFin && itm->second.getTimestamp() >= dateDeb){
                
    //             //returnArray[distance(listTypesDonnees, itl)][0] += itm->second.value;
    //             returnArray[iterateur][0] += itm->second.getValue();
                
    //             // Max
    //             if (itm->second.getValue() > returnArray[iterateur][1])
    //             {
    //                 //returnArray[distance(listTypesDonnees, itl)][1] = itm->second.value;
    //                 returnArray[iterateur][1] = itm->second.getValue();
    //             }

    //             // Min
    //             if (itm->second.getValue() < returnArray[iterateur][2])
    //             {
    //                 //returnArray[distance(listTypesDonnees, itl)][2] = itm->second.value;
    //                 returnArray[iterateur][2] = itm->second.getValue();
    //             }
    //             nbMeasurements++;
    //         }
    //     }
    //     returnArray[iterateur][0] /= nbMeasurements;
    //     nbMeasurements = 0;
    //     iterateur++;
    // }
    return returnArray;
}



//------------------------------------------------- Surcharge d'opérateurs
// & Service::operator = ( const Service & unService )
// Algorithme :
//
//{
//} //----- Fin de operator =


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
