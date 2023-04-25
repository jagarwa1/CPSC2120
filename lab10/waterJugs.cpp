/*
 * Name:            Jai Agarwal
 * Date Submitted:  4/24/2023
 * Lab Section:     002
 * Assignment Name: lab 10: puzzles using breadth first search
 *                          (wolf goat cabbage and water jugs)
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Reflects what each node represents...
// First value units of water in A, second units of water in B
typedef pair<int,int> state;

// Each string in edge_label must be one of the following:
const string actions[] = {"Fill A",
                          "Fill B",
                          "Empty A",
                          "Empty B",
                          "Pour A->B",
                          "Pour B->A"};

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label;

// GENERIC (breadth-first search, outward from source_node)
void search(state source_node)
{
  queue<state> to_visit;
  to_visit.push(source_node);
  visited[source_node] = true;
  dist[source_node] = 0;
  
  while (!to_visit.empty()) {
    state curnode = to_visit.front();
    to_visit.pop();
    for (state n : nbrs[curnode])
      if (!visited[n]) {
	pred[n] = curnode;
	dist[n] = 1 + dist[curnode];
	visited[n] = true;
	to_visit.push(n);
      }
  }
}

// GENERIC
void print_path(state s, state t)
{
  if (s != t) {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": " << "[" << t.first << "," << t.second << "]\n";
  } else {
    cout << "Initial state: " << "[" << s.first << "," << s.second << "]\n";
  }
}


// helper function for readability, creating nbrs, and creating edge_label
// takes state Current, state Next, and int action which is the index for array Actions
void cmpStates(state currState, state nextState, int action){
  if (nextState != currState){ // if there is a change of states
    edge_label[make_pair(currState, nextState)] = actions[action];
    nbrs[currState].push_back(nextState);
  }
}

//Implement this function
void build_graph(void)
{
  state currState = make_pair(0,0), nextState;
  
  int maxA = 3, maxB = 4;
  int currA, currB;
  
  while(currState != make_pair(maxA,maxB))
  {

    currA = currState.first;
    currB = currState.second;

    // fill A
    nextState = make_pair(maxA, currB);
    cmpStates(currState, nextState, 0);

    // fill B
    nextState = make_pair(currA, maxB);
    cmpStates(currState, nextState, 1);

    // pour out A
    nextState = make_pair(0, currB);
    cmpStates(currState, nextState, 2);

    // pour out B
    nextState = make_pair(currA, 0);
    cmpStates(currState, nextState, 3);

    // pour A into B
    if (currB + currA < maxB) // no problems, pour away
      nextState = make_pair(0, currB + currA);
    else if (currB + currA > maxB) 
      nextState = make_pair(currA - (maxB - currB), maxB);
    else    // currB + currA == maxB
      nextState = make_pair(0, maxB);

    cmpStates(currState, nextState, 4);

    // pour B into A
    if (currB + currA < maxA) // no problems, pour away
      nextState = make_pair(currA + currB, 0);
    else if (currB + currA > maxA) 
      nextState = make_pair(maxA, currB - (maxA - currA));
    else    // currA + currB == maxA
      nextState = make_pair(maxA, 0);
      
    cmpStates(currState, nextState, 5);

    if(currState.second == maxB)
      currState = make_pair(currState.first + 1,0);
    else
        currState = make_pair(currState.first, currState.second + 1);
  }
}

int main(void)
{
  build_graph();

  state start = make_pair(0,0);
  
  for (int i=0; i<5; i++)
    nbrs[make_pair(i,5-i)].push_back(make_pair(-1,-1));
  search (start);
  if (visited[make_pair(-1,-1)]) 
    print_path (start, pred[make_pair(-1,-1)]);
  else
    cout << "No path!\n";
  
  return 0;
}
