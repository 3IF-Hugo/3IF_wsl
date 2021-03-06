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

typedef vector<int> State;

//  .---.
//  |2|0|
//  .---. -> State b = {2,0,1,3}
//  |1|3|
//  .---.

typedef pair<int,int> Move;

typedef function<int( const State& pos )> Heuristic;

int 
side( const State& b )
{
  double y = sqrt( b.size() );
  int x = y;
  return x;
}

int 
manh( const State& b )
{
  int d = 0;
  int s = side(b);
  for( int i = 0 ; i < b.size() ; i++ )
  {
    if( b[i] != 0 )  // not a tile, '0' doesn't count
    {
      d += abs( i / s - b[i] / s ) +
           abs( i % s - b[i] % s );
    }
  }
  return d;
}

int
nbmis( const State& b )
{
  int d = 0;
  for( int i = 0 ; i < b.size() ; i++ )
  {
    if( b[i] != 0 ) // not a tile, '0' doesn't count
    {
      if( b[i] != i ) d++;
    }
  }
  return d;
}

bool
finalState( const State& b )
{
  return (nbmis(b) == 0); // we use nbmis for it is quick to compute
}

void
print( const State& state )
{
  int s = side(state);
  for( int i = 0 ; i < state.size() ; i++ )
  {
    if( i % s == 0 ) cout << endl;
    cout << setw(2) << setfill('0') << state[i] << " , ";
  }
  cout << endl;
}

void
doMove( State &state, const Move &move )
{
  swap( state[move.first] , state[move.second] );
}

void
addNeighbor( State &currentState, Move &move, 
             vector< pair< Move,int > > &neighbors,
             list<State>& path, Heuristic h )
{
  doMove( currentState, move );
  if( find( path.begin(), path.end(), currentState ) == path.end() )
  {
    neighbors.push_back( make_pair( move, h(currentState) ) );
  }
  doMove( currentState, move ); // undo move
}

void
search( State& currentState,
        int          ub, // upper bound over which exploration must stop
        int&         nub,
        list<State>& path,
        list<State>& bestPath,
        Heuristic    h,
        int&         nbVisitedState,
        double weight)

{
  nbVisitedState++;

  int f; // under-estimation of optimal length
  int g = path.size() - 1; // size of the current path to currentState

  if( finalState( currentState ) )
  {
    bestPath = path;
    return;
  }

  // generate the neighbors
  int s = side( currentState );
  vector< pair< Move,int > > neighbors;
  neighbors.clear();
  
  int pos0 = find( currentState.begin(), currentState.end(), 0 ) - currentState.begin();
  
  if( (pos0 + 1) < currentState.size() &&
      ((pos0 + 1) % s) != 0 )
  {
    Move move = make_pair( pos0, pos0 + 1 );
    addNeighbor( currentState, move, neighbors, path, h );
  }
  
  if( (pos0 - 1) >= 0 &&
      ((pos0 - 1) % s) != (s-1) )
  {
    Move move = make_pair( pos0, pos0 - 1 );
    addNeighbor( currentState, move, neighbors, path, h );
  }
  
  if( (pos0 + s) < currentState.size() )
  {
    Move move = make_pair( pos0, pos0 + s );
    addNeighbor( currentState, move, neighbors, path, h );
  }
  
  if( (pos0 - s) >= 0 )
  {
    Move move = make_pair( pos0, pos0 - s );
    addNeighbor( currentState, move, neighbors, path, h );
  }

  for( const pair<Move,int> &p : neighbors )
  {
    f = floor( g + 1 + weight * p.second );
    if( f > ub )
    {
      if( f < nub )
      {
        nub = f; // update the next upper bound
      }
    }
    else
    {
      doMove( currentState, p.first );
      path.push_back( currentState );
      search( currentState, ub, nub, path, bestPath, h, nbVisitedState, weight );
      path.pop_back();
      doMove( currentState, p.first ); // undo move
      if( !bestPath.empty() ) return;
    }
  }
}

void
ida( State&        initialState, 
     Heuristic     h,
     list<State>&  bestPath, // path from source to destination
     int&          nbVisitedState,
     double weight)
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
    search( initialState, ub, nub, path, bestPath, h, nbVisitedState, weight );
    cout << " ; nbVisitedState: " << nbVisitedState << endl;
  }
}

int
main()
{
  //State b = {11,5,12,14,15,2,0,9,13,7,6,1,3,10,4,8};
  State b = {7,11,8,3,14,0,6,15,1,4,13,9,5,12,2,10};
  //State b = {4,8,3,2,0,7,6,5,1};
  list<State> bestPath;
  int nbVisitedState = 0;
  float weight = 1.5;
  
  cout << endl << "----------" << endl;
  cout << "Weighted-IDA* with a weight of " << weight << endl;
  auto start = std::chrono::high_resolution_clock::now();
  ida( b, manh, bestPath, nbVisitedState, weight );
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  cout << "Elapsed time: " << elapsed.count() << " s" << endl;
  cout << "nb moves: " << bestPath.size()-1 << endl;
  cout << "nb visited states: " << nbVisitedState << endl;

  weight = 1.0;
  bestPath.clear();
  nbVisitedState = 0;

  cout << endl << "----------" << endl;
  cout << "Weighted-IDA* with a weight of " << weight << endl;
  start = std::chrono::high_resolution_clock::now();
  ida( b, manh, bestPath, nbVisitedState, weight );
  finish = std::chrono::high_resolution_clock::now();
  elapsed = finish - start;
  cout << "Elapsed time: " << elapsed.count() << " s" << endl;
  cout << "nb moves: " << bestPath.size()-1 << endl;
  cout << "nb visited states: " << nbVisitedState << endl;

  return 0;
}

