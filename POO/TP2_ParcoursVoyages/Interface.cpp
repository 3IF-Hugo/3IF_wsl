using namespace std;
#include <iostream>

#include "Trajet.h"
#include "TrajetSimple.h"

int main()
{
    const char* lyon = "Lyon";
    const char* Marseille = "Marseille";
    const char* train = "train";
    Trajet *traj1 = new Trajet(lyon, Marseille);
    traj1->Afficher();
    
    TrajetSimple *traj2 = new TrajetSimple(lyon, Marseille, train);
    traj2->Afficher();
     
    //delete [] traj1;
    //delete[] traj2;
    
    return 0;
}