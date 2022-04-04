#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <functional>

using namespace std;

struct node 
{
  int val;           // value
  vector<node*> suc; // successors
  node() {};
  node(int i) : val(i) {}
};

typedef function<void(node*)> Visitor;

void 
bfs( node* src, Visitor visit ) 
{
  set<node*> x;                   // x is the set of visited nodes
  queue<node*> y;                 // y is the queue of grey nodes
  y.push(src); x.insert(src);     // at the beginning, the source is the only 
                                  // grey node
  while( !y.empty() )
  {
    node* u = y.front();
    visit(u);
    for( node* n : u->suc )       
    {
      if( x.end() == x.find(n) )  // n is a white successor of u
      {                                 
        y.push(n); x.insert(n);   // n becomes grey
      }
    }
    y.pop();                      // u becomes black
  }
}

void 
visit( node* v ) 
{
  cout << v->val << " ; ";
}

int 
main() 
{
  node n0(0); node n1(1); node n2(2); node n3(3); 
  node n4(4); node n5(5); node n6(6);
  n0.suc.push_back( &n1 ); n1.suc.push_back( &n2 ); n1.suc.push_back( &n3 );
  n2.suc.push_back( &n0 ); n3.suc.push_back( &n2 ); n4.suc.push_back( &n5 );
  n4.suc.push_back( &n6 ); n5.suc.push_back( &n1 ); n5.suc.push_back( &n6 );
  bfs(&n5, visit); 
  cout << endl;
  return 0;
}
