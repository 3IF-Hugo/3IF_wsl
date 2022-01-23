#if ! defined ( revision_H )
#define revision_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include <iostream>

template <typename T>
T Minimum(const T & x, const T & y)
{
    return x < y ? x:y;
}

template<>
double Minimum<double> (const double & x, const double & y)
{
    cout << "je fais nimp" << endl;
    return x+y;
}




#endif