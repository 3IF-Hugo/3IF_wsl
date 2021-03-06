#include <iostream>
#include <utility>
using namespace std;

class State
{
  public:
    
  State(int b, int s);
  // Constructor that creates a state with b blocs and s stacks

  State(const State& s);
  // Constructor that creates a copy of s
  
  void setInitial();
  // Initialise this with the initial state (blocs uniformly distributed)
  
  bool isFinal();
  // Return true if this is a final state (all blocs on the last stack, from 
  // largest to smallest)
  
  typedef pair<int,int> Move;
  // A move is a pair of stacks: the bloc on top of the first stack is moved to
  // the top of the second stack

  void doMove(Move m);
  // Precondition: 0 <= m.first < getNbStacks(), 0 <= m.second < getNbStacks(), 
  //               and !emptyStack(m.first)
  // Apply the doMove (m.first->m.second) to this
  
  void display() const;
  // Display this

  bool operator==(const State&) const;
  
  int getNbStacks();
  // Return the number of stacks
  
  bool emptyStack(int s);
  // Precondition: 0 <= s < getNbStacks()
  // Return true if stack s has no block
  
  ~State();
  // Destructor
  
  private:

  int nbBlocs, nbStacks;
  int* stack; // For each bloc b: stack[b] = stack that contains b
  int* next;  // For each bloc b: if b is the lowest block of its stack,
              // then next[b]=-1, else next[b]=bloc immediately below b
  int* top;   // For each stack s: if s is empty, then top[s]=-1
              // else top[s]=bloc on top of s
  bool equal(const int*, const int*, const int*) const; // compare states
};

State::State(int b, int s)
{
  // Constructor that creates a state with b blocs and s stacks
  nbBlocs = b;
  nbStacks = s;
  stack = new int[nbBlocs];
  next = new int[nbBlocs];
  top = new int[nbStacks];
}

State::State(const State& state){
    // Constructor that creates a copy of state
    nbBlocs = state.nbBlocs;
    nbStacks = state.nbStacks;
    stack = new int[nbBlocs];
    next = new int[nbBlocs];
    top = new int[nbStacks];
    for (int s=0; s<nbStacks; s++){
        top[s] = state.top[s];
    }
    for (int b=0; b<nbBlocs; b++){
        next[b] = state.next[b];
        stack[b] = state.stack[b];
    }
}

State::~State()
{
  delete[] next;
  delete[] stack;
  delete[] top;
}

void State::setInitial()
{
  // Initialise this with the initial state (blocs uniformly distributed)
  for (int s=0; s<nbStacks; s++) top[s] = -1;
  for (int b=0; b<nbBlocs; b++)
  {
    int s = b % nbStacks; // Put bloc b on top of stack s
    stack[b] = s;
    next[b] = top[s];
    top[s] = b;
  }
}

bool State::isFinal()
{
  // Return true if this is a final state (all blocs on the last stack, from 
  // largest to smallest)
  for (int s=0; s<nbStacks-1; s++)
  {
    if (top[s] != -1) return false;
  }
  if (top[nbStacks-1] != 0) return false;
  for (int b=0; b<nbBlocs-1; b++)
  {
    if (stack[b] != nbStacks-1) return false;
    if (next[b] != b+1) return false;
  }
  if (next[nbBlocs-1] != -1) return false;
  return true;
}

void State::doMove(Move m)
{
  // Precondition: 0 <= m.first < getNbStacks(), 0 <= m.second < getNbStacks(),
  //               and !emptyStack(m.first)
  // Apply the doMove (s1->s2) to this
  int b1 = top[m.first];
  int bb1 = next[b1];
  int b2 = top[m.second];
  next[b1] = b2;
  top[m.second] = b1;
  top[m.first] = bb1;
  stack[b1] = m.second;
}

void displayStack(int s, int* next)
{
  // Display all blocs below s (including s), from bottom to top
  if (s >= 0)
  {
      displayStack(next[s], next);
      cout << s << " ";
  }
}

void State::display() const
{
  // Display this
  for (int s=0; s<nbStacks; s++)
  {
    cout << "stack "<< s << ": ";
    displayStack(top[s], next);
    cout << endl;
  }
}

int State::getNbStacks()
{
  return nbStacks;
}

bool State::emptyStack(int s)
{
  // Precondition: 0 <= s < getNbStacks()
  // Return true if stack s has no block
  return top[s] == -1;
}

bool State::operator==(const State& state) const{
    // Return true if this == state
    return state.equal(stack,top,next);
}

bool State::equal(const int* stack2, const int* top2, const int* next2) const{
    for (int b=0; b<nbBlocs; b++){
        if (stack[b]!=stack2[b]) return false;
        if (next[b]!=next2[b]) return false;
    }
    for (int s=0; s<nbStacks; s++){
        if (top[s]!=top2[s]) return false;
    }
    return true;
}
