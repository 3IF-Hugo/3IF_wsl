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
    //Initialisation du tableau contenant les statistiques
    double** returnArray = new double*[listeTypesDonnees.size()];
    for(int i=0; i<(int)(listeTypesDonnees.size()); ++i)
    {
        returnArray[i] = new double[3];
        //Moyenne
        returnArray[i][0] = 0;
        //Maximum
        returnArray[i][1] = 0;
        //Minimum
        returnArray[i][2] = __INT_MAX__;
    }
    //Liste des Sensors dans la zone demandée
    map<string, Sensor> listSensorsArea;
    //Nombre de mesures pour chaque type de données
    int * nbMeasurements = new int(listeTypesDonnees.size());
    //Distance par rapport au point passé en paramètre
    double distance;
    
    // Recuperer les capteurs dans la zone choisie
    for(map <string, Sensor>::iterator it = sensors.begin(); it != sensors.end(); it++){
        // Calcul de la distance simple en 2D, amelioration possible avec la formule de haversine
        distance = sqrt(pow(it->second.getLatitude() - latitude, 2) + pow(it->second.getLongitude() - longitude, 2)); 
        if (distance <= rayonZone){
            listSensorsArea.insert(*it);
        }
    }

    // Calculer la moyenne, le min et max pour chaque type de donnees
    //Pour chaque mesures
    for(map<Sensor, Measurement>::iterator itm = tousMeasurements.begin(); itm != tousMeasurements.end(); ++itm){
        //Si le capteur correspondant à la mesure est dans la liste des capteurs à prendre en compte et dans la bonne période de temps
        if(listSensorsArea.find(itm->first.getSensorID()) != listSensorsArea.end() && itm->second.getTimestamp() <= dateFin && itm->second.getTimestamp() >= dateDeb){
            //Ajout éventuel de points
            for(list<PrivateUser>::iterator itPU = listeUsers.begin(); itPU != listeUsers.end(); ++itPU)
            {
                if(itPU->getSensorId().compare(itm->first.getSensorID()) == 0 && itPU->getStatut() == 0)
                {
                    itPU->setScorePlus1();
                    break;
                }
            }
            //Recherche de l'attribut de la mesure pour la mise à jour des statistiques dans le tableau de retour
            map <string, int>::iterator itl;
            for(itl = listeTypesDonnees.begin(); itl != listeTypesDonnees.end(); itl++){
                if(itl->first.compare(itm->second.getAttribute()) == 0){
                    break;
                }
            }
            //Mise à jour des statistiques correspondantes au type de mesure trouvée
            if(itl != listeTypesDonnees.end())
            {
                //Moyenne
                returnArray[itl->second][0] += itm->second.getValue();
                
                //Maximum
                if(itm->second.getValue() > returnArray[itl->second][1]){
                    returnArray[itl->second][1] = itm->second.getValue();
                }

                //Minimum
                if(itm->second.getValue() < returnArray[itl->second][2]){
                    returnArray[itl->second][2] = itm->second.getValue();
                }
                //Nombre de mesures pour le calcul de la moyenne
                nbMeasurements[itl->second] += 1;
            }
        }
    }
    //Calcul de la moyenne
    for(map<string, int>::iterator itl = listeTypesDonnees.begin(); itl != listeTypesDonnees.end(); itl++){
        returnArray[itl->second][0] /= nbMeasurements[itl->second];
    }
    delete(nbMeasurements);
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
