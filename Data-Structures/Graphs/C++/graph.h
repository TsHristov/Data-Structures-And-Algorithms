#pragma once
#include <iostream>
#include "../../Queue/Queue-Linked-List/C++/queue.h"
#include "../../Stack/Stack-Linked-List/C++/stack.h"
using namespace std;

// Adjacency matrix graph representation properties:
// - Add edge: O(1)
// - Remove edge: O(1)
// - Check edge exists: O(1)
// - Find all descendants of a given vertex: O(n)
// - Check if path between two vertices exists: O(n^2)
// - Memory: O(n^2)
// - BFS/DFS traversals: O(n^2)

class Graph
{
  int **graph;       // adjacency matrix
  unsigned vertices; // vertices count

public:
  Graph(unsigned);
  ~Graph();

public:
  void add_edge(int i, int j, int weight=1){
    graph[i][j] = weight;
    graph[j][i] = weight;
  }

  bool edge_exists(int i, int j){
    return graph[i][j];
  }

  void print(){
    for(unsigned i=0; i < vertices; i++){
      for(unsigned j=0; j < vertices; j++){
	cout << graph[i][j] << "|";
      }
      cout << "\n";
    }
  }

  unsigned vertices_count() {
    return vertices;
  }
  
public:
  // Graph algorithms:
  void BFS(unsigned); // O(n^2)
  void DFS(unsigned); // O(n^2)
  bool has_cycle();   // O(n^2)

private:
  void check_cycle_exists(unsigned , int, bool&, char*);
};

Graph :: Graph(unsigned vertices) {
    this->vertices = vertices;
    graph = new (nothrow) int*[vertices];
    for(unsigned i=0; i < vertices; i++){
      graph[i] = new (nothrow) int[vertices];
      for(unsigned j=0; j < vertices; j++){
	graph[i][j] = 0;
      }
    }
}

Graph :: ~Graph(){
  for(unsigned i=0; i < vertices; i++){
    delete[] graph[i];
  }
  delete[] graph;
}

void Graph :: BFS(unsigned start) {
  Queue<int> queue = Queue<int>();
  queue.Enqueue(start);

  char *visited = new (nothrow) char[vertices];
  if(!visited) return;
    
  for(unsigned i=0; i < vertices; i++) visited[i] = 0;

  visited[start] = 1;

  int current;
  while(!queue.Empty()) {
    current = queue.Dequeue();
    cout << "|" << current + 1 << "| ";
    
    for(unsigned j=0; j < vertices; j++) {
      // For each descendant of the current vertex:
      if(graph[current][j] == 1 && !visited[j]) {
	queue.Enqueue(j);
	visited[j] = 1;
      }
    }
  }
  delete[] visited;
}

void Graph :: DFS(unsigned start) {
  Stack<int> stack = Stack<int>();
  stack.Push(start);

  char *visited = new (nothrow) char[vertices];
  if(!visited) return;
    
  for(unsigned i=0; i < vertices; i++) visited[i] = 0;

  visited[start] = 1;

  int current;
  while(!stack.Empty()) {
    current = stack.Pop();
    cout << "Current:" << current + 1 << "\n";

    for(unsigned j=0; j < vertices; j++) {
      if(graph[current][j] && !visited[j]) {
	stack.Push(j);
	visited[j] = 1;
      }
    }
  }
  delete[] visited;
}

void Graph :: check_cycle_exists(unsigned start, int parent, bool &cycle, char *visited) {

  visited[start] = 1;
  
  for(unsigned vertex=0; vertex < vertices; vertex++) {
    if(cycle) return;
    if(edge_exists(start,vertex)) {
      if(visited[vertex] && vertex != parent) {
	cycle = true;
	return;
      }
      else if(vertex != parent) {
	check_cycle_exists(vertex, start, cycle, visited);
      }
    }
  }
}

bool Graph :: has_cycle() {
  bool cycle = false;

  char *visited = new (nothrow) char[vertices];

  for(unsigned i = 0; i < vertices; i++) visited[i] = 0;
  
  for(unsigned vertex = 0; vertex < vertices; vertex++) {
    if(!visited[vertex]) check_cycle_exists(vertex, -1, cycle, visited);
    if(cycle) break;
  }

  delete[] visited;
  
  return cycle;
}

