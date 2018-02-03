#include <iostream>
#include "graph.h"
using namespace std;

int main(){
  Graph graph = Graph(14);

  int i,j;

  while(true){
    cout << "i:";
    cin >> i;
    if(i == -1) break;
    cout << "j:";
    cin >> j;
    graph.add_edge(i-1,j-1);
  }
  graph.print();

  int start;
  // cout << "Start vertex for BFS:";
  // cin >> start;
  // cout << "Bread-First Search from vertex:" << start << "\n";
  // graph.BFS(start-1);

  cout << "Start vertex for BFS:";
  cin >> start;
  cout << "Bread-First Search from vertex:" << start << "\n";
  graph.DFS(start - 1);
  
  return 0;  
}
