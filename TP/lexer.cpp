#include "lexer.h"

Symbole * Lexer::Consulter() {
   if (!tampon) {

      if (tete==flux.length())
         tampon = new Symbole(FIN, true);
      else
      {

         switch (flux[tete]) {
            case '(':
               tampon = new Symbole(OPENPAR, true);
               tete++;
               break;
            case ')':
               tampon = new Symbole(CLOSEPAR, true);
               tete++;
               break;
            case '*':
               tampon = new Symbole(MULT, true);
               tete++;
               break;
            case '+':
               tampon = new Symbole(PLUS, true);
               tete++;
               break;
            default:
               if (flux[tete]<='9' && flux[tete]>='0') {
                  int resultat = flux[tete]-'0';
                  int i=1;
                  while (flux[tete+i]<='9' && flux[tete+i]>='0') {
                     resultat = resultat*10+(flux[tete+i]-'0');
                     i++;
                  }
                  tete = tete+i;
                  tampon = new Entier(resultat);
               }
               else {
                  tampon = new Symbole(ERREUR, true);
               }
         }
      }
   }
   return tampon;
}

void Lexer::Avancer() {
   tampon = nullptr;
}

