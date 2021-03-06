/*************************************************************************
                           Interface  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//--- Réalisation de la classe <Interface> (fichier Interface.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <list>
#include <map> 
#include <string>
#include <ctime>
#include <iomanip>
//------------------------------------------------------ Include personnel
#include "Attribute.h"
#include "Cleaner.h"
#include "Lecture.h"
#include "Measurement.h"
#include "PrivateUser.h"
#include "Provider.h"
#include "Sensor.h"
#include "Service.h"
#include "UtilityService.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void afficheMan(){
    cout << "----- MANUEL D'INSTRUCTION -----" << endl;
    cout << "0 : L'application affiche la description des différentes fonctionnalités ainsi que les formats attendus pour les saisies de données. L'utilisateur peut taper 0 pour revenir au menu principal. " << endl;
    cout << "----------------------------------" << endl;
    cout << "1 : L'utilisateur rentre dans l'ordre la latitude, la longitude, le rayon, la date de début, l'heure de début, la date de fin,";
    cout << "l'heure de fin, puis l'application lui demande à la suite pour les 4 types de données s'il veut les prendre en compte ou non en tapant 0 ou 1";
    cout << "(respectivement non pris en compte et pris en compte). Le résultat est affiché et l'utilisateur peut taper 0 pour revenir au menu principal."<<endl;
    cout << "----------------------------------" << endl;
    cout << "2 : L'utilisateur rentre l'ID du capteur. Le résultat est affiché et l'utilisateur peut taper 0 pour revenir au menu principal." << endl;
    cout << "----------------------------------" << endl;
    cout << "3 : L'utilisateur entre la latitude, la longitude et le rayon. Le résultat est affiché et l'utilisateur peut taper 0 pour revenir au menu principal."<< endl;
    cout << "----------------------------------" << endl;
    cout << "4 : (Agence et fournisseur) : L'utilisateur rentre l'ID de l'air cleaner. Le résultat est affiché et l'utilisateur peut taper 0 pour revenir au menu principal."<< endl;
    cout << "4 : (Client avec capteur) : Le résultat est directement affiché et l'utilisateur peut taper 0 pour revenir au menu principal."<< endl;
    cout << "----------------------------------" << endl;
    cout << "5 : L'utilisateur rentre la latitude et la longitude du capteur. Si le capteur avec de telles coordonnées n'existe pas encore, un message";
    cout << "de succès va être affiché. S'il existe déjà, soit fiable soit pas fiable, ou si les coordonnées ne sont pas valides, un message d'erreur va être affiché. Dans les 2 cas, l'utilisateur peut taper 0 pour revenir au menu principal." << endl;
    cout << "----------------------------------" << endl;
    cout << "6 : (Uniquement pour la démonstration) L'utilisateur rentre l'ID du capteur qu'il souhaite analyser ainsi que le rayon de la zone et la période d'analyse.";
    cout << "Après l'analyse effectuée, un message s'affiche et indique l'état du capteur (défectueux ou fonctionnel). L'utilisateur peut taper 0 pour revenir au menu principal."<< endl;
    cout << "----------------------------------" << endl;
    cout << "7 : (Uniquement pour la démonstration) Affiche les IDs des capteurs exclus."<< endl;
    cout << "----------------------------------" << endl;
    cout << "8 : L'utilisateur peut taper 1 pour se déconnecter et aller au menu au lancement de l'application, ou taper 0 pour quitter l'application." << endl;
    cout << "----- FIN MANUEL D'INSTRUCTION -----" << endl;
}


int main()
{
    //Initialise des services et charge des donnees
    Service service;
    UtilityService util;
    map<string, Sensor> listeCapteurs;
    list<Attribute> listeAttributs;
    list<PrivateUser> listePrivateUsers;
    list<Cleaner> listeCleaners;
    list<Provider> listeProviders;
    multimap<Sensor, Measurement> mesuresO3;
    multimap<Sensor, Measurement> mesuresSO2;
    multimap<Sensor, Measurement> mesuresNO2;
    multimap<Sensor, Measurement> mesuresPM10;
    Lecture::LireDonnees(listeCapteurs, listeAttributs, listePrivateUsers, listeCleaners, listeProviders, mesuresO3, mesuresSO2, mesuresNO2, mesuresPM10);

    int userInput = 1;
    int userTypeInput = 1;
    string sensorInputID;
    double rayonInput;
    int dateInput;
    int monthInput;
    int yearInput;
    double latInput;
    double logInput;
    double rayonZone;
    int dataInputTab[4] = {0};
    int dataInput; 
    bool capteurFonctionnel;
    list<string> listeCapteursDefectueux;
    multimap<Sensor, Measurement> mesuresInput;
    string sensorIDRef;
    double latitudeRef;
    double longitudeRef;
    string userID;
    
    while (userInput != 8) {
        //Menu
        cout << "-----------------------------------------------------------------------------------" << endl;
        cout << "-----------------------------------------------------------------------------------" << endl;
        cout << "Veuillez choisir une commande :" << endl;
        cout << "0 - Manuel d'utilisation" << endl;
        cout << "1 - Statistiques sur un rayon et une durée ou moment" << endl;
        cout << "2* - Comparaison de zones similaires par rapport à un capteur" << endl;
        cout << "3* - Déterminer qualité de l'air à un endroit précis" << endl;
        //Si utilisateur = agence gouvernementale ou fournisseur : 4 = Vérifier l'efficacité d'un air cleaner 
        //Si utilisateur = client privé avec un capteur : 4 = Consulter nombre des points
        cout << "4* - Vérifier l'efficacité d'un air cleaner / Consulter nombre des points" << endl;
        cout << "5* - Ajouter un capteur" << endl;
        cout << "6 - Tester fonctionnement capteur et l'exclure si besoin" << endl;
        cout << "7 - Consulter les capteurs exclus" << endl;
        cout << "8 - Se déconnecter/Quitter l'application" << endl;
        cout << "* fonctions non dévéloppées" << endl;
        cin >> userInput;

        //Verification d'entree
        if (userInput < 0 || userInput > 7)
        {
            while (userInput < 0 || userInput > 8)
            {
                cout << "Commande inconnue. Réessayez." << endl;
                cin >> userInput;
            }
        }
        
        //Traitement d'entree
        switch(userInput)
        {
            case 0:
            {
                afficheMan();
                break;
            }
            case 1:
            {
                cout << "----------------------------------" << endl;
                cout << "Statistiques sur un rayon et une durée ou moment" << endl;
                cout << "----------------------------------" << endl;
                cout << "Veuillez entrez un latitude" << endl;
                cin >> latInput;
                cout << "Veuillez entrez un longitude" << endl;
                cin >> logInput;
                cout << "Veuillez entrez un rayon : " << endl;
                cin >> rayonInput;

                cout << "Choix des types de données\nVoulez-vous avoir des statistiques sur O3 (oui : 1, non : 0) : " << endl;
                cin >> dataInput;
                if(dataInput == 1)
                {
                    for(multimap<Sensor, Measurement>::iterator it=mesuresO3.begin(); it != mesuresO3.end(); ++it)
                    {
                        mesuresInput.insert(*it);
                    }
                }
                dataInputTab[0] = dataInput;
                cout << "Voulez-vous avoir des statistiques sur SO2 (oui : 1, non : 0) : " << endl;
                cin >> dataInput;
                if(dataInput == 1)
                {
                    for(multimap<Sensor, Measurement>::iterator it=mesuresSO2.begin(); it != mesuresSO2.end(); ++it)
                    {
                        mesuresInput.insert(*it);
                    }
                }
                dataInputTab[1] = dataInput;
                cout << "Voulez-vous avoir des statistiques sur NO2 (oui : 1, non : 0) : " << endl;
                cin >> dataInput;
                if(dataInput == 1)
                {
                    for(multimap<Sensor, Measurement>::iterator it=mesuresNO2.begin(); it != mesuresNO2.end(); ++it)
                    {
                        mesuresInput.insert(*it);
                    }
                }
                dataInputTab[2] = dataInput;
                cout << "Voulez-vous avoir des statistiques sur PM10 (oui : 1, non : 0) : " << endl;
                cin >> dataInput;
                if(dataInput == 1)
                {
                    for(multimap<Sensor, Measurement>::iterator it=mesuresPM10.begin(); it != mesuresPM10.end(); ++it)
                    {
                        mesuresInput.insert(*it);
                    }
                }
                dataInputTab[3] = dataInput;
                list<Attribute>::iterator it = listeAttributs.begin();
                map<string, int> listeTypesDonnees;
                int cpt = 0;
                for(int i=0; i<4; ++i)
                {
                    if(dataInputTab[i] == 1)
                    {
                        advance(it,i);
                        listeTypesDonnees.insert(make_pair(it->getAttributeId(), cpt++));
                        it=listeAttributs.begin();
                    }
                }

                cout << "Veuillez entrez une annee pour la date de début: " << endl;
                cin >> yearInput;
                cout << "Veuillez entrez un mois pour la date de début: " << endl;
                cin >> monthInput;
                cout << "Veuillez entrez un jour pour la date de début: " << endl;
                cin >> dateInput;
                struct tm userDate = {0};
                userDate.tm_hour = 12;
                userDate.tm_min = 0;
                userDate.tm_sec = 0;
                userDate.tm_year = yearInput - 1900; // Nombres d'annees depuis 1900
                userDate.tm_mon = monthInput - 1; // 0-based month
                userDate.tm_mday = dateInput; // 1-based date
                time_t convertedDebDate = mktime(&userDate);

                cout << "Veuillez entrez une annee pour la date de fin: " << endl;
                cin >> yearInput;
                cout << "Veuillez entrez un mois pour la date de fin: " << endl;
                cin >> monthInput;
                cout << "Veuillez entrez un jour pour la date de fin: " << endl;
                cin >> dateInput;
                userDate.tm_year = yearInput - 1900; // Nombres d'annees depuis 1900
                userDate.tm_mon = monthInput - 1; // 0-based month
                userDate.tm_mday = dateInput; // 1-based date
                time_t convertedFinDate = mktime(&userDate);
                
                clock_t tpsDebut = clock();
                double** statistiques = service.calculerStatistiques(listeCapteurs, mesuresInput, listeTypesDonnees, latInput, logInput, rayonInput, convertedDebDate, convertedFinDate, listePrivateUsers);
                float duree = ((double) (clock() - tpsDebut)) / CLOCKS_PER_SEC;
                cout << "Temps d'exécution de l'algorithme : " << duree << "s" << endl;

                cout << "\nVoici les statistiques demandées : " << endl << endl;
                for(map<string, int>::iterator itListTypeData = listeTypesDonnees.begin(); itListTypeData != listeTypesDonnees.end(); ++itListTypeData)
                {
                    cout << itListTypeData->first << " : " << endl;
                    cout << "Moyenne : " << statistiques[itListTypeData->second][0] << endl;
                    cout << "Max : " << statistiques[itListTypeData->second][1] << endl;
                    cout << "Min : " << statistiques[itListTypeData->second][2] << endl;
                    cout << endl;
                }
                for(int i=0; i<(int)listeTypesDonnees.size(); ++i)
                {
                    delete(statistiques[i]);
                }
                delete(statistiques);
                break;
            }
            case 2:
            {
                cout << "----------------------------------" << endl;
                cout << "Comparaison de zones similaires par rapport à un capteur - Fonctionnalité non développée" << endl;
                cout << "----------------------------------" << endl;
                break;
            }
            case 3:
            {
                cout << "----------------------------------" << endl;
                cout << "Déterminer qualité de l'air à un endroit précis - Fonctionnalité non développée" << endl;
                cout << "----------------------------------" << endl;
                break;
            }
            case 4:
            {
                cout << "----------------------------------" << endl;
                cout << "Quel type d'utilisateur êtes-vous?" << endl;
                cout << "1 - Client privé"<< endl;
                cout << "2 - Employé de l'agence gouvernementale ou fournisseur de purificateur d'air"<< endl;
                cout << "3 - Client lambda";
                cout << "----------------------------------" << endl;
                cin >> userTypeInput;
                switch(userTypeInput)
                {
                    case 1:
                    {
                        cout << "----- Consulter nombre des points -----" << endl;
                        cout << "Entrez votre UserID : " << endl;
                        cin >> userID;
                        for(list<PrivateUser>::iterator itPU = listePrivateUsers.begin(); itPU != listePrivateUsers.end(); ++itPU)
                        {
                            if(itPU->getUserId().compare(userID) == 0)
                            {
                                cout << "Nombre de points : " << itPU->getScore() << endl;
                                break;
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        cout << "----- Vérifier l'efficacité d'un air cleaner -----" << endl;
                        cout << "Fonctionnalité non développée" << endl;
                        cout << "---------------------------------------" << endl;
                        break;
                    }
                }
                break;
            }
            
            case 5:
            {
                cout << "----------------------------------" << endl;
                cout << "Ajouter un capteur - Fonctionnalité non développée" << endl;
                cout << "----------------------------------" << endl;
                break;
            }

            case 6: 
            {
                cout << "----- Vérifier l'état d'un capteur (défectueux ou fonctionnel) -----" << endl;
                cout << "Veuillez entrez l'identifiant d'un capteur (selon le modèle 'SensorX') : "<< endl;
                cin >> sensorInputID; 
                cout << "Veuillez entrez le rayon de la zone sur laquelle on veut analyser l'impact du capteur :"<< endl;
                cin >> rayonZone;
                        
               //Trouver le capteur dont l'identifiant correspond à celui entré par l'utilisateur  
                for(map<string,Sensor>::iterator it = listeCapteurs.begin(); it != listeCapteurs.end(); ++it)
                {
                    if((it->first).compare(sensorInputID) == 0)
                    {
                        //sensorToAnalyze = new Sensor(it->second.getSensorID(),it->second.getLatitude(),it->second.getLongitude());   
                        cout<< "Sensor a analyser dont l'ID est : " << it->second.getSensorID() << endl;
                        sensorIDRef = it->second.getSensorID();
                        latitudeRef = it->second.getLatitude();
                        longitudeRef = it->second.getLongitude();
                    }
                }
                //Analyse du capteur
                clock_t tpsDebut = clock(); 
                capteurFonctionnel = util.analyseSensor(listeCapteurs, listeCapteursDefectueux, sensorIDRef, latitudeRef, longitudeRef, rayonZone, mesuresO3, mesuresSO2, mesuresNO2, mesuresPM10, listePrivateUsers);
                float duree = ((double) (clock() - tpsDebut)) / CLOCKS_PER_SEC;
                cout << "Temps d'exécution de l'algorithme : " << duree << "s" << endl;
                if(capteurFonctionnel == true)
                {
                    cout << "Le capteur analysé est fonctionnel" << endl;
                }
                else
                {
                    cout << "Le capteur analysé est défectueux" << endl;
                }               
                break;
            }

            case 7:
            {
                for(list<string>::iterator it = listeCapteursDefectueux.begin(); it != listeCapteursDefectueux.end(); ++it)
                {
                    cout << *it << endl;
                }
                break;
            }

            case 8:
            {
                cout << "Quitting..." << endl;
                break;
            }
        }
    }
    return 0;
}