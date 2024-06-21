#include <stack>
#include <symbole.h>
#include <lexer.h>
using namespace std;

class Etat;

class Automate {

    protected:
        Lexer * lex;
        deque <Etat *> pileEtat;
        deque <Symbole *> pileSymbole;

    public:
        void decalage(Symbole * s, Etat * e);

        void reduction(int n,Symbole * s);

        void popAndDestroySymbol();

        Symbole * popSymbol();

};