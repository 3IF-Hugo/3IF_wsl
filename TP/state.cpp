#include "Etat.h"
#include "state.h"

bool E0::transition(Automate & automate, Symbole * s){
    switch (*s){
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.decalage(s, new E1);
    }
    return false;
};

bool E1::transition(Automate & automate, Symbole * s){
    switch (*s){
    case PLUS:
        automate.decalage(s, new E4);
        break;
    case MULT:
        automate.decalage(s, new E5);
        break;
    default:
    //accepter
    }
    return false;
}

bool E2::transition(Automate & automate, Symbole * s){
    switch (*s){
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.decalage(s, new E6);
    }
    return false;
}
bool E3::transition(Automate & automate, Symbole * s){
    switch (*s){
    case INT:
    case OPENPAR:
    default:
        //r5 : E -> val
        //Dépiler val puis réduire par la règle 5 (E -> val)
        automate.popAndDestroySymbol();
        automate.reduction(1,new Expr((int) *s));
        break;
    }
    return false;
}
bool E4::transition(Automate & automate, Symbole * s){
    switch (*s){
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.decalage(s, new E7);
    }
    return false;
}
bool E5::transition(Automate & automate, Symbole * s){
    switch (*s){
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.decalage(s, new E8);
    }
    return false;
}
bool E6::transition(Automate & automate, Symbole * s){
    switch (*s){
    case PLUS:
        automate.decalage(s, new E4);
        break;
    case MULT:
        automate.decalage(s, new E5);
        break;
    case CLOSEPAR:
        automate.decalage(s, new E9);
        break;
    }
    return false;
}
bool E7::transition(Automate & automate, Symbole * s){
    switch (*s){
    case PLUS:
    case MULT:
    default:
        //r2
    }
    return false;
}
bool E8::transition(Automate & automate, Symbole * s){
    switch (*s){
    case INT:
        automate.decalage(s, new State3);
        break;
    case OPENPAR:
        automate.decalage(s, new State2);
        break;
    default:
        Expr * s1 = (Expr*) automate.popSymbol();
        automate.popAndDestroySymbol();
        Expr * s2 = (Expr*) automate.popSymbol();
        automate.reduction(1,new ExprPlus(s2,s1));
        break;
    }
    return false;
}
bool E9::transition(Automate & automate, Symbole * s){
    switch (*s){
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
        automate.popAndDestroySymbol();
        Expr * s1 = (Expr*) automate.popSymbol();
        automate.popAndDestroySymbol();
        automate.reduction(1,s1);
        break;
    }
    return false;
}

