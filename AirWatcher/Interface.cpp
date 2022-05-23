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
    cout << "6 : L'utilisateur peut taper 1 pour se déconnecter et aller au menu au lancement de l'application, ou taper 0 pour quitter l'application." << endl;
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
    string cleanerInputID;
    Sensor sensorToAnalyze;
    double rayonInput;
    int dateInput;
    int monthInput;
    int yearInput;
    double latInput;
    double logInput;
    double rayonZone;
    int nbrJours; 
    bool capteurFonctionnel;
    list<Sensor> listeCapteursDefectueux;
    
    while (userInput != 0) {
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
        cout << "4 - Vérifier l'efficacité d'un air cleaner / Consulter nombre des points" << endl;
        cout << "5* - Ajouter un capteur" << endl;
        cout << "6 - Se déconnecter/Quitter l'application" << endl;
        cout << "* fonctions non dévéloppées" << endl;
        cin >> userInput;

        //Verification d'entree
        if (userInput < 0 || userInput > 5)
        {
            while (userInput < 0 || userInput > 5)
            {
                cout << "Commande inconnue. Réessayez." << endl;
                cin >> userInput;
            }
        }
        
        //Traitement d'entree
        switch(userInput)
        {
            case 0:
                afficheMan();
                break;
            
            case 1:
            {
                cout << "----------------------------------" << endl;
                cout << "Statistiques sur un rayon et une durée ou moment" << endl;
                cout << "----------------------------------" << endl;
                cout << "Veuillez entrez un latitude";
                cin >> latInput;
                cout << "Veuillez entrez un longitude";
                cin >> logInput;
                cout << "Veuillez entrez un rayon : ";
                cin >> rayonInput;
                cout << "Veuillez entrez une date : ";
                cin >> dateInput;
                cout << "Veuillez entrez un mois: ";
                cin >> monthInput;
                cout << "Veuillez entrez un annee: ";
                cin >> yearInput;
                struct tm userDate = {0};
                userDate.tm_year = yearInput - 1900; // Nombres d'annees depuis 1900
                userDate.tm_mon = monthInput - 1; // 0-based month
                userDate.tm_mday = dateInput; // 1-based date
                time_t convertedDate = mktime(&userDate);
                
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
                        cout << "Fonctionnalité non développée" << endl;
                        cout << "---------------------------------------" << endl;
                        break;
                    }
                    case 2:
                    {
                        cout << "----- Vérifier l'efficacité d'un air cleaner -----" << endl;
                        cout << "Veuillez entrez l'identifiant d'un air cleaner (seulement le numero X dans 'CleanerX') : "<< endl;
                        cin >> cleanerInputID; 
                        cout << "Veuillez entrez le rayon de la zone sur laquelle on veut analyser l'impact du capteur (en mètres):"<< endl;
                        cin >> rayonZone;
                        cout <<"Veuillez entrez la durée de la période sur laquelle on veut analyser l'impact du capteur (à partir de la date actuelle, en jours):" << endl;
                        cin >> nbrJours;
                        time_t now = time(0);
                        
                        //Trouver le capteur dont l'identifiant correspond à celui entré par l'utilisateur  
                        for(map<string,Sensor>::iterator it = listeCapteurs.begin(); it != listeCapteurs.end(); ++it)
                        {
                            if((it->first).compare(cleanerInputID) == 0)
                            {
                            //    sensorToAnalyze = new Sensor(it->second.getSensorID(),it->second.getLatitude(),it->second.getLongitude());    
                            }
                        }
                        //Analyse du capteur   
                        capteurFonctionnel = util.analyseSensor(listeCapteurs, sensorToAnalyze, rayonZone, now, mesuresO3, mesuresSO2, mesuresNO2, mesuresPM10); 
                        if(capteurFonctionnel == true)
                        {
                            cout << "Le capteur analysé est fonctionnel" << endl;
                        }
                        else
                        {
                            cout << "Le capteur analysé est défectueux" << endl;
                            //On enlève le capteur de la liste des capteurs et on l'ajoute à la liste des capteurs défectueux
                            listeCapteurs.erase(sensorToAnalyze.getSensorID());
                            listeCapteursDefectueux.push_back(sensorToAnalyze);
                        }                
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
                cout << "Quitting..." << endl;
                break;
            }
        }
    }
    return 0;
}