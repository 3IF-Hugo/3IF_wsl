#include "Automate.h"
#include "Etat.h"
using namespace std;

void Automate::decalage(Symbole * s, Etat * e) {
    pileSymbole.push_back(s);
    pileEtat.push_back(e);
    if (s->isTerminal()) {
        lex->Avancer();
    }
}

void Automate::reduction(int n,Symbole * s) {
    for (int i=0;i<n;i++){
        delete(pileEtat.back());
        pileEtat.pop_back();
    }
    pileEtat.back()->transition(*this,s);
}

void Automate::popAndDestroySymbol(){
    delete(pileSymbole.back());
    pileSymbole.pop_back();
}

Symbole * Automate::popSymbol(){
    Symbole * ret = pileSymbole.back();
    pileSymbole.pop_back();
    return ret;
}
