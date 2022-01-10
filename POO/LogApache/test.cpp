#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Graphe.h"
#include "InfoLog.h"

int main ()
{
    Renseignements info = Renseignements("test1", "ds", "sd", "sdg", "gq", "gqggg", "reeeeeeeey", "er", "zry");
    InfoLog test = InfoLog(info);
    return 0;
}