#include <iostream>
using namespace std;

#include "Trajet.h"
#include "TrajetSimple.h"
#include "Element.h"
#include "LinkedList.h"
#include "TrajetCompose.h"
#include "Catalogue.h"


int main ()
{
    const char* Paris = "Paris";
    const char* Lyon = "Lyon";
    const char* Valence = "Valence";
    const char* Bordeaux = "Bordeaux";
    const char* Montpellier = "Montpellier";
    const char* Marseille = "Marseille";
    const char* train = "train";
    const char* avion = "avion";

    LinkedList *test = new LinkedList();

    Trajet *traj1 = new Trajet(Paris, Lyon);
    TrajetSimple *traj2 = new TrajetSimple(Lyon, Valence, train);
    TrajetSimple *traj4 = new TrajetSimple(Montpellier, Marseille, avion);

    //test->ajouter(traj1);
    // test->afficher();
    // cout<<endl;

    TrajetCompose *traj3 = new TrajetCompose(Valence, Montpellier);
    TrajetSimple * traj3_1 = new TrajetSimple(Valence, Bordeaux, avion);
    TrajetSimple * traj3_2 = new TrajetSimple(Bordeaux, Montpellier, train);
    traj3->ajouter(traj3_1);
    traj3->ajouter(traj3_2);

    test->ajouter(traj3);
    test->afficher();
    //traj3->Afficher();
}