#include <iostream>
#include "graph.h"
using namespace std;

int main(){
  Graph graph = Graph(10);

  int i,j;

  while(true){
    cout << "i:";
    cin >> i;
    if(i == -1) break;
    cout << "j:";
    cin >> j;
    cout << "weight:";
    graph.add_edge(i-1,j-1);
  }

    
  return 0;  
}
