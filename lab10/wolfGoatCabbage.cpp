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
#include <bitset>
using namespace std;

// Reflects what each node represents...
// int with each bit == 0 left of river, bit == 1 right of river
typedef int state;

// Bit position representation for wolf/goat/cabbage/me
bool bit(int x, int i) { return (x>>i) & 1; }
const int wolf=0, goat=1, cabbage=2, me=3;

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label;

// GENERIC (breadth-first search, outward from curnode)
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

string state_string(state s)
{
  string items[4] = { "wolf", "goat", "cabbage", "you" }, result = "";
  for (int i=0; i<4; i++)
    if (!bit(s, i)) result += items[i] + " ";
  result += " |river| ";
  for (int i=0; i<4; i++)
    if (bit(s, i)) result += items[i] + " ";
  return result;
}

// GENERIC
void print_path(state s, state t)
{
  if (s != t) {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": " << state_string(t) << "\n";
  } else {
    cout << "Initial state: " << state_string(s) << "\n";
  }
}

string neighbor_label(int s, int t)
{
  string items[3] = { "wolf", "goat", "cabbage" }, which_cross;
  if (bit(s,me) == bit(t,me)) return "";  // must cross river
  int cross_with = 0;
  for (int i=0; i<3; i++) {
    if (bit(s,i) != bit(t,i) && bit(s,i)==bit(s,me)) { cross_with++; which_cross = items[i]; }
    if (bit(s,i) != bit(t,i) && bit(s,i)!=bit(s,me)) return "";
  }
  if (cross_with > 1) return "";
  if (cross_with == 0) return "Cross alone";
  else return "Cross with " + which_cross;
}


//Implement this function
void build_graph(void)
{
  bitset<4> currState, nextState;
  
  for (int i = 0; i < 16; i++) 
  {
    
    currState = i;
    
    for(int n = 0; n < 4; n++) 
    {

      if(currState[me] == currState[n]) // if item and me are on the same side
      {
        nextState = currState;
        nextState[me].flip(); // i will cross sides no matter what in the next state
        if (n != me) nextState[n].flip(); // i will bring the current item n

        bool valid = true;
        if(nextState[goat] == nextState[wolf] && (nextState[me] != nextState[goat])) // invalid if goat and wolf are together without me
        {          
          valid = false;          
        }    
        else if(nextState[goat] == nextState[cabbage] && (nextState[me] != nextState[goat])) // invalid if goat and cabb are together without me
        {
          valid = false; 
        }

        if (valid == true){
            nbrs[currState.to_ulong()].push_back(nextState.to_ulong()); // push neighbor state to map, with key being currState
            edge_label[make_pair(currState.to_ulong(), nextState.to_ulong())] = neighbor_label(currState.to_ulong(), nextState.to_ulong()); // long line
        }
        
      }

    }  
  }
}

int main(void)
{
  build_graph();

  state start = 0, end = 15;
  
  search(start);
  if (visited[end])
    print_path (start, end);
  else
    cout << "No path!\n";
  
  return 0;
}
