#include <iostream>
using namespace std;

#include "Trajet.h"
#include "TrajetSimple.h"
#include "Catalogue.h"

void Ajouter_trajet_simple(Catalogue *catalogueAcreer);

TrajetCompose* Ajouter_trajet_compose(Catalogue *catalogueAcreer);

void Ajouter_sous_trajet_simple(Catalogue *catalogueAcreer, TrajetCompose *unTrajet);

void Rechercher_trajet();

void Afficher(Catalogue *catalogueAcreer);

int main()
{
    Catalogue *notreCatalogue = new Catalogue();
    while(1)
	{
        cout << "menu:" << endl;
        cout << "\t1: Ajouter un trajet simple" << endl;
        cout << "\t2: Ajouter un trajet composé" << endl;
        cout << "\t3: Rechercher un trajet" << endl;
        cout << "\t4: Afficher" << endl;
        cout << "\t0: quitter" << endl;
		int choix;
        cin >> choix;
		switch(choix)
		{
			case 0:
				goto fin;
			case 1:
				Ajouter_trajet_simple(notreCatalogue);
				break;
			case 2: 
            {
                TrajetCompose *nouveauTrajet = Ajouter_trajet_compose(notreCatalogue);
                while(1)
                {
                    cout << "menu trajet composé:" << endl;
                    cout << "\t21: Ajouter une étape" << endl;
                    cout << "\t20: Finaliser le trajet composé" << endl;
                    int choixSousMenu;
                    cin >> choixSousMenu;
                    switch(choixSousMenu)
                    {
                        case 20:
                            goto finSousMenu;
                        case 21:
                            Ajouter_sous_trajet_simple(notreCatalogue, nouveauTrajet);
                            break;
                        default:
                            cout << "choix incorrect" << endl;
                    }
                }
                finSousMenu:
				break;
            }
			case 3:
				Rechercher_trajet();
				break;
            case 4: 
				Afficher(notreCatalogue);
				break;
			default:
                cout << "choix incorrect" << endl;
				continue ; // revenir au menu
		}
	}
	fin:
    cout << "Au revoir" << endl;
/*
    const char* lyon = "Lyon";
    const char* Marseille = "Marseille";
    const char* train = "train";
    Trajet *traj1 = new Trajet(lyon, Marseille);
    traj1->Afficher();
    
    TrajetSimple *traj2 = new TrajetSimple(lyon, Marseille, train);
    traj2->Afficher();
     
    //delete [] traj1;
    //delete[] traj2;
    */
    return 0;
}

void Ajouter_trajet_simple(Catalogue *catalogueAcreer)
{
    char *lecture = new char[100];
    cout << "Ville de départ : ";
    cin >> lecture;
    const char* villeDepart = lecture;
    cout << "Ville d'arrivée : ";
    cin >> lecture;
    const char* villeArr = lecture;
    cout << "Moyen de transport : ";
    cin >> lecture;
    const char* moyenTransport = lecture;

    catalogueAcreer->AjouterTrajetSimple(villeDepart, villeArr, moyenTransport);
    
    delete[] lecture;
}

TrajetCompose* Ajouter_trajet_compose(Catalogue *catalogueAcreer)
{
    char *lecture = new char[100];
    cout << "Ville de départ : ";
    cin >> lecture;
    const char* villeDepart = lecture;
    cout << "Arrivée finale : ";
    cin >> lecture;
    const char* villeArr = lecture;
    
    delete[] lecture;

    return catalogueAcreer->AjouterTrajetCompose(villeDepart, villeArr);
}

void Ajouter_sous_trajet_simple(Catalogue *catalogueAcreer, TrajetCompose* unTrajet)
{
    char *lecture = new char[100];
    cout << "Ville de départ : ";
    cin >> lecture;
    const char* villeDepart = lecture;
    cout << "Ville d'arrivée : ";
    cin >> lecture;
    const char* villeArr = lecture;
    cout << "Moyen de transport : ";
    cin >> lecture;
    const char* moyenTransport = lecture;

    catalogueAcreer->AjouterSousTrajetSimple(villeDepart, villeArr, moyenTransport, unTrajet);

    delete lecture;
}


void Rechercher_trajet()
{

}

void Afficher(Catalogue *catalogueAcreer)
{
    catalogueAcreer->Afficher();
}