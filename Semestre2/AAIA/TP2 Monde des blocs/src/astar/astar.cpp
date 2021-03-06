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

using namespace std;

typedef vector<int> State;

//  .---.
//  |2|0|
//  .---. -> State b = {2,0,1,3}
//  |1|3|
//  .---.

typedef function<int( const State& pos )> Heuristic;

int
side( const State& b ) 
{
  double y = sqrt( b.size() );
  int x = y;
  return x;
}

// the most uninformed heuristic
int 
breadth( const State& b )
{
  return 0;
}

// this heuristic counts the number of misplaced tiles
int 
nbmis( const State& b ) 
{
  int d = 0;
  for( int i = 0 ; i < b.size() ; i++ ) 
  {
    if( b[i] != 0 ) // '0' is not a tile
    {
      if( b[i] != i ) d++;
    }
  }
  return d;
}

bool 
final_state( const State& b ) 
{
  return (nbmis(b) == 0); 
}

int 
dist( const map<State,int>& d, const State& state ) 
{
  map< State , int >::const_iterator it = d.find(state);
  if( d.end() == it ) {
    return numeric_limits<int>::max();
  }
  return it->second;
}

void 
update_neighborhood( const State& current_state, 
                     vector<State>& neighbors, int s) 
{
  // parameter s is the length of the side of the grid
  neighbors.clear();

  int pos0 = find( current_state.begin(), current_state.end(), 0 ) -
             current_state.begin();
  
  // empty space not on the last column
  if( (pos0 + 1) < current_state.size() &&
     ((pos0 + 1) % s) != 0 )
  {
    State neighbor = current_state;
    swap( neighbor[pos0] , neighbor[pos0 + 1] );
    neighbors.push_back(neighbor);
  }
  
  // empty space not on the first column
  if( (pos0 - 1) >= 0 &&
     ((pos0 - 1) % s) != (s-1) )
  {
    State neighbor = current_state;
    swap( neighbor[pos0] , neighbor[pos0 - 1] );
    neighbors.push_back(neighbor);
  }
  
  // empty space not on the last row
  if( (pos0 + s) < current_state.size() )
  {
    State neighbor = current_state;
    swap( neighbor[pos0] , neighbor[pos0 + s] );
    neighbors.push_back(neighbor);
  }
  
  // empty space not on the first row
  if( (pos0 - s) >= 0 )
  {
    State neighbor = current_state;
    swap( neighbor[pos0] , neighbor[pos0 - s] );
    neighbors.push_back(neighbor);
  }
}

void
astar( const State& initial_state, 
       Heuristic     h,
       list<State>&  best_path,
       int&          nbiter )
{
  int grid_length = side(initial_state);

  map< State , State > parent;            // the structure parent is used to
  parent[initial_state] = initial_state;  // trace back the path to the target
  
  map< State , int > d;                   // d[p] is an estimate of the distance
  d[initial_state] = h(initial_state);    // between position p and the target.
  
  set< State > black;
  
  priority_queue< pair< int , State >,
                  vector< pair< int, State > >,
                  greater< pair< int, State > > > grey;
  grey.push( { d[initial_state], initial_state } ); // the source starts grey
  
  vector<State> neighbors;
  
  nbiter = 0; // count how many positions had to be explored before finding the
              // shortest path from the source to the target

  while( !grey.empty() )
  {
    State current_state = grey.top().second;

    nbiter++;

    if( final_state(current_state) )
    {
      best_path.clear();
      while( current_state != initial_state )
      {
        best_path.push_front(current_state);
        current_state = parent[current_state];
      }
      best_path.push_front(initial_state);
      return;
    }

    black.insert(current_state);
    grey.pop();

    update_neighborhood(current_state, neighbors, grid_length);

    for( State neighbor : neighbors )
    {
      // when neighbor n of u is black, there's nothing to do
      if( black.end() != black.find(neighbor) ) continue;
      // when white or grey, we may update the shortest known distance to it
      int new_cost = d[current_state] + 1 - h(current_state) + h(neighbor);
      if( dist(d,neighbor) > new_cost )
      {
        d[neighbor] = new_cost;
        parent[neighbor] = current_state;
        grey.push( { d[neighbor] , neighbor } );
      }
    }

  }
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

int
main()
{
  State b = {4,8,3,2,0,7,6,5,1};
  //State b = {14,10,9,4,13,6,5,8,2,12,7,0,1,3,11,15};
  list<State> best_path;
  int nbiter = 0;
  
  astar(b, breadth, best_path, nbiter);
  cout << "Heuristic breadth:" << endl;
  cout << "nb moves: " << best_path.size()-1 << endl;
  cout << "nb nodes explored: " << nbiter << endl;
  
  best_path.clear();
  astar(b, nbmis, best_path, nbiter);
  cout << "Heuristic nbmis:" << endl;
  cout << "nb moves: " << best_path.size()-1 << endl;
  cout << "nb nodes explored: " << nbiter << endl;
  
  for( const State& s : best_path ) print(s);

  return 0;
}
