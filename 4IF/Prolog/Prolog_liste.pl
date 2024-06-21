% Student exercise profile
:- set_prolog_flag(occurs_check, error).        % disallow cyclic terms
:- set_prolog_stack(global, limit(8 000 000)).  % limit term space (8Mb)
:- set_prolog_stack(local,  limit(2 000 000)).  % limit environment space

% Your program goes here

%Régles :
member(X,[X|_]).
member(X,[_|L]) :- member(X,L).

concat([ ], L1, L1).
concat([X|L1],L2,[X|L3]) :- concat(L1,L2,L3).

dernier(X,[X]).
dernier(X,[_|L]) :- dernier(X,L).

element(_,[],[]).
element(X,[X|L],R) :- element(X,L,R).
element(X,[Y|L],[Y|R]) :- X\==Y,element(X,L,R).

inv([],[]).
inv([T|Q],R) :- inv(Q,R1),append(R1,[T],R).

renverser(L,R) :- rev(L,[],R).
rev([],A,A).
rev([T|Q],A,R) :- rev(Q,[T|A],R).

composante(1,X,[X|_]).
composante(I,X,[_|L]) :- composante(J,X,L),I is J+1.

subsAll(_,_,[],[]).
subsAll(X,Y,[X|L1],[Y|L2]) :- subsAll(X,Y,L1,L2).
subsAll(X,Y,[Z|L1],[Z|L2]) :- Z\==X,subsAll(X,Y,L1,L2).

subsAll(_,_,[],[]).
subsAll(X,Y,[X|L1],[Y|L2]) :- subsAll(_,_,L1,L2).
subsAll(X,Y,[Z|L1],[Z|L2]) :- Z\==X,subsAll(X,Y,L1,L2).
/** <examples> Your example queries go here, e.g.
member(5,[1,2,3,4]).
member(2,[1,2,3,4]).
concat([a,b],[c,d],L). : crée une liste L
concat([a,b],[c,d],[a,b,c,d). :true
concat([a,b],[c,d],[a,c,d,b). :false
dernier(4,[1,2,3]).

element(b,[a,b,a,c],R).
element(X,[a,b,a,c],R).

inv([a,b],[b,a]).
inv([a,b,c,b],L).

renverser(L,[c,b,a]).
*/
