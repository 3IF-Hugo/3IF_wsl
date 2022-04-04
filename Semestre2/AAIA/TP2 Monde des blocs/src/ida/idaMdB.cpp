#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <utility>
#include <list>
#include <functional>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <limits>
#include <chrono>

using namespace std;
#include "State.cpp"

typedef pair<int,int> Move;

typedef function<int(  State& pos )> Heuristic;

void
addNeighbor( State &currentState, Move &move, 
             vector< pair< Move,int > > &neighbors,
             list<State>& path, Heuristic h )
{
  currentState.doMove(move);
  if( find( path.begin(), path.end(), currentState ) == path.end() )
  {
    neighbors.push_back( make_pair( move, h(currentState) ) );
  }
    currentState.doMove(make_pair(move.second,move.first)); // undo move
}

void
search( State& currentState,
        int          ub, // upper bound over which exploration must stop
        int&         nub,
        list<State>& path,
        list<State>& bestPath,
        Heuristic    h,
        int&         nbVisitedState )

{
  nbVisitedState++;

  int f; // under-estimation of optimal length
  int g = path.size() - 1; // size of the current path to currentState

  if( currentState.isFinal())
  {
    bestPath = path;
    return;
  }

  // generate the neighbors
  vector< pair< Move,int > > neighbors;
  neighbors.clear();

  for (int s1=0; s1<currentState.getNbStacks(); s1++){
        if (!currentState.emptyStack(s1)){
            for (int s2=0; s2<currentState.getNbStacks(); s2++){
                if (s1!=s2){
                    Move move = make_pair(s1,s2);
                    addNeighbor( currentState, move, neighbors, path, h );
                }
            }
        }
    }

  for( const pair<Move,int> &p : neighbors )
  {
    f = g + 1 + p.second;
    if( f > ub )
    {
      if( f < nub )
      {
        nub = f; // update the next upper bound
      }
    }
    else
    {
      currentState.doMove(p.first);
      path.push_back( currentState );
      search( currentState, ub, nub, path, bestPath, h, nbVisitedState );
      path.pop_back();
      currentState.doMove(make_pair(p.first.second,p.first.first)); // undo move
      if( !bestPath.empty() ) return;
    }
  }
}

int h0( State& pos )
{
  return 0;
}

int h1( State& pos )
{
    int h;
    for (int i = 0; i < pos.getNbBlocs(); i++)
        if (pos.getStack()[i] != pos.getNbStacks()-1) h++;
    return h;
}

/*int h2( State& pos )
{
    int h;
    for (int i = 0; i < pos.getNbBlocs(); i++)
    {
        if (pos.getStack()[i] != pos.getNbStacks()-1) h++;
        else{
            int j = i+1;
            while (j < pos.getNbBlocs())
            {
                if (pos.getStack()[j] == pos.getNbStacks()-1) j++;
                else{
                    h+=2;
                    break;
                }
            }
        }
    }
    return h;
}*/

int h2(State& pos)
{
    return pos.h2();
}

int h3(State& pos)
{
    return pos.h3();
}

void
ida( State&        initialState, 
     Heuristic     h,
     list<State>&  bestPath, // path from source to destination
     int&          nbVisitedState )
{
  int ub;                      // current upper bound
  int nub = h( initialState ); // next upper bound
  list<State> path;
  path.push_back( initialState ); // the path to the target starts with the source

  while( bestPath.empty() && nub != numeric_limits<int>::max() )
  {
    ub = nub;
    nub = numeric_limits<int>::max();

    cout << "upper bound: " << ub;
    search( initialState, ub, nub, path, bestPath, h, nbVisitedState );
    cout << " ; nbVisitedState: " << nbVisitedState << endl;
  }
}

int
main()
{
    int nbStacks = 3;
    int nbBlocs = 8;
    State state = State(nbBlocs,nbStacks);
    state.setInitial();

  list<State> bestPath;
  int nbVisitedState = 0;
  
  auto start = std::chrono::high_resolution_clock::now();
  ida( state, h2, bestPath, nbVisitedState );
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  cout << "Elapsed time: " << elapsed.count() << " s\n";
  cout << "nb moves: " << bestPath.size()-1 << endl;
  cout << "nb visited states: " << nbVisitedState << endl;
  prev(bestPath.end()) -> display();
  return 0;
}