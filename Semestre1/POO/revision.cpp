#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "revision.h"


int main()
{
    double prix(14.99);
    cout << Minimum<double>(prix, 7.83) << endl;
    char c1('m'), c2 ('a');
    cout << Minimum<char>(c1, c2) << endl;

    return 0;
}