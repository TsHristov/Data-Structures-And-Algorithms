#pragma once
#include <iostream>
#include <limits>
#include <algorithm>
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
  void bfs(unsigned);                 // O(n^2)
  void dfs(unsigned);                 // O(n^2)
  bool has_cycle();                   // O(n^2)
  void all_paths(unsigned, unsigned); // O(2^n)
  void dijkstra(unsigned);            // O(n^2) (O(nlog2n) if min-heap is used)

private:
  void check_cycle_exists(unsigned , int, bool&, char*);
  void find_all_paths(unsigned, unsigned, char*, unsigned*, int&);
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

void Graph :: bfs(unsigned start) {
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

void Graph :: dfs(unsigned start) {
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
      // A cycle exists if there is already visited vertex,
      // which is diferent than the parent of the current one:
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


void Graph :: all_paths(unsigned start, unsigned end) {
  char *visited  = new (nothrow) char[vertices];
  if(!visited) return;

  // Start off with unvisited array of vertices:
  for(unsigned vertex; vertex < vertices; vertex++) visited[vertex] = 0;

  // An array where the different paths from start to end vertex will reside:
  unsigned *path = new (nothrow) unsigned[vertices];
  if(!path) return;

  int vertices_count = 0; // Count of vertices that make up the path
  // Find all paths between start vertex and end vertex, using DFS (or BFS):
  find_all_paths(start, end, visited, path, vertices_count);

  delete[] visited;
  delete[] path;
}


void Graph :: find_all_paths(unsigned start, unsigned end, char *visited, unsigned *path, int &vertices_count) {
  // If the end vertex is reached, print the current path:
  if(start == end) {
    path[vertices_count] = end;
    for(int vertex=0; vertex < vertices_count; vertex++) {
      cout << path[vertex] + 1 << " ";
    }
    cout << "\n";
    return;
  }

  visited[start] = 1;   // Mark the current vertex as visited
  path[vertices_count++]  = start; // Add the current vertex to the path
  for(unsigned vertex=0; vertex < vertices; vertex++) {
    if(edge_exists(start, vertex) && !visited[vertex]) {
      // Find all paths from `vertex` to `end`:
      find_all_paths(vertex, end, visited, path, vertices_count);
    }
  }

  // Mark the current vertex as unvisited, so it can be visited in next traversal:
  visited[start] = 0;
  vertices_count--;
}


void Graph :: dijkstra(unsigned start) {
  const int MAX_VALUE = numeric_limits<int>::max();
  
  unsigned *distance = new (nothrow) unsigned[vertices];
  if(!distance) return;

  // Initialize all adjacent vertices with the distance to start,
  // else those not adjacent to start with MAX_VALUE:
  for(int vertex=0; vertex < vertices; vertex++) {
    if(edge_exists(start,vertex)) {
      distance[vertex] = graph[start][vertex];
    } else {
      distance[vertex] = MAX_VALUE;
    }
  }

  // Create an array of unvisited vertices:
  unsigned *unvisited = new (nothrow) unsigned[vertices];
  if(!unvisited) return;

  // Start with all vertices as unvisited, except for the start vertex:
  for(int vertex=0; vertex < vertices; vertex++){
    if(vertex == start){
      unvisited[vertex] = 0;
    } else {
      unvisited[vertex] = 1;   
    }
  }

  while(true) {
    int min_distance_vertex = -1;
    int min_distance        = MAX_VALUE;
    
    // Find the unvisited vertex with min distance:
    for(unsigned vertex=0; vertex < vertices; vertex++) {
      if(unvisited[vertex] && distance[vertex] < min_distance) {
	min_distance        = distance[vertex];
	min_distance_vertex = vertex;
      }
    }

    // If all vertices have MAX_VALUE:
    if (min_distance_vertex == -1) break;

    // Remove the vertex with min distance from the unvisited set:
    unvisited[min_distance_vertex] = 0;

    for (unsigned vertex=0; vertex < vertices; vertex++) {
      if (unvisited[vertex] && edge_exists(min_distance_vertex, vertex)) {
	if (distance[vertex] > distance[min_distance_vertex] + graph[min_distance_vertex][vertex]) {
	  distance[vertex] = distance[min_distance_vertex] + graph[min_distance_vertex][vertex];
	}
      }
    }
  }

  // Print the min distances to all vertices from `start` vertex:  
  for (unsigned vertex=0; vertex < vertices; vertex++) {
    if (vertex != start) {
      if(distance[vertex] == MAX_VALUE) {
	cout << "Distance from vertex " << start + 1 << " to vertex " << vertex + 1 \
	     << " : " << "unspecified" << "\n";
      } else {
	cout << "Distance from vertex " << start + 1 << " to vertex " << vertex + 1 \
	     << " : " << distance[vertex] << "\n";
      }
    }
  }

  delete[] distance;
  delete[] unvisited;
}

