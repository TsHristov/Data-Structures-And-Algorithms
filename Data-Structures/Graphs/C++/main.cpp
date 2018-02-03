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

  cout << "Does the graph has a cycle?: ";
  (graph.has_cycle()) ? cout << "Yes\n" : cout << "No\n";
  
  return 0;  
}
