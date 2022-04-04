#include <iostream>
#include <vector>
#include <set>
#include <functional>

using namespace std;

struct node 
{
  int val;
  vector< node* > suc;
  node() {};
  node(int i) : val(i) {}
};

typedef function<void(node*)> Visitor;

void 
visit( node* v ) 
{
  cout << v->val << " ; ";
}

void 
dfsrec0( node* n, Visitor visit, set<node*>& x ) 
{
  x.insert(n);
  for( node* s : n->suc )
  {
    if( x.end() == x.find(s) )
    {
      dfsrec0( s, visit, x );
    }
  }
  visit(n);
}

void 
dfsrec( node* src, Visitor visit )
{
  set<node*> x;
  dfsrec0(src, visit, x);
}

int 
main() 
{
  node n0(0); node n1(1); node n2(2); node n3(3); 
  node n4(4); node n5(5); node n6(6);
  n0.suc.push_back( &n1 ); n1.suc.push_back( &n2 ); n1.suc.push_back( &n3 );
  n2.suc.push_back( &n0 ); n3.suc.push_back( &n2 ); n4.suc.push_back( &n5 );
  n4.suc.push_back( &n6 ); n5.suc.push_back( &n1 ); n5.suc.push_back( &n6 );
  dfsrec(&n5, visit); 
  cout << endl;
  return 0;
}
