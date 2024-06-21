% Student exercise profile
:- set_prolog_flag(occurs_check, error).        % disallow cyclic terms
:- set_prolog_stack(global, limit(8 000 000)).  % limit term space (8Mb)
:- set_prolog_stack(local,  limit(2 000 000)).  % limit environment space

% Your program goes here
%Genre
masculin(jean).
masculin(max).
masculin(bob).
masculin(tom).
masculin(john).
masculin(jacques).
masculin(nathan).
feminin(anne).
feminin(eva).
feminin(lucie).
feminin(jeanne).

%Lien de parenté
parent(jean,bob).
parent(anne, bob).
parent(tom,lucie).
parent(eva,lucie).
parent(bob,max).
parent(lucie,max).
parent(bob,john).
parent(lucie,john).
parent(eva,jacques).
parent(tom,jacques).
parent(jacques,nathan).

%Règles
pere(X,Y):- parent(X,Y),masculin(X).
mere(X,Y):- parent(X,Y),feminin(X).
grand_parent(X,Y) :- parent(X,Z), parent(Z,Y).
ancetre(X,Y) :- parent(X,Z),ancetre(Z,Y);parent(X,Y).
frere(X,Y) :- parent(Z,X), parent(Z,Y), masculin(X), X\==Y.
soeur(X,Y) :- parent(Z,X), parent(Z,Y), feminin(X), X\==Y.
frere_ou_soeur(X,Y) :- frere(X,Y);soeur(X,Y).
cousin(X,Y) :- parent(W,X),parent(Z,Y),(frere(W,Z);soeur(W,Z)),masculin(X).
%cousin(X,Y) :- grand_parent(Z,X),grand_parent(Z,Y),not(frere(X,Y)),not(soeur(X,Y)),X\==Y.
liste_des_ancetres(L,X) :- bagof(Y,ancetre(Y,X),L).
%liste_des_ancetres(L,X) :- setof(Y,ancetre(Y,X),L).


/** <examples> Your example queries go here, e.g.
?- member(X, [cat, mouse]).
pere(X,bob).
mere(X,bob).
grand_parent(X,max).
trace, (ancetre(X,max))
liste_des_ancetres(L,max).
frere(X,max).
cousin(X,nathan).
*/
