#include "graph.h"
#include <vector>
#include <assert.h>
#include <iostream>
using namespace std;

graph::graph(){
	numVertices = 0;
	edges = new int*[MAX];
	labels = new char*[MAX];
	for (size_t i = 0; i < MAX; i++){
		edges[i] = new int[MAX];
		labels[i] = nullptr;
	}
	for (size_t i = 0; i < MAX; i++){
		for (size_t j = 0; j < MAX; j++){
			edges[i][j] = -1;
		}
	}
}
graph::~graph(){
	delete[] labels;
	delete[] edges;
}

void graph::add_edge(int source, int target, int weight){
	assert(source >= 0 && source < numVertices);
	assert(target >= 0 && target < numVertices);

	edges[source][target] = weight;
}

void graph::add_vertex(char * vertexLabel){
	assert(numVertices < MAX);
	for (int i = 0; i < numVertices + 1; i++){
		edges[i][numVertices] = -1;
		edges[numVertices][i] = -1;
	}
	labels[numVertices] = new char[strlen(vertexLabel) + 1];
	strcpy_s(labels[numVertices], strlen(vertexLabel) + 1, vertexLabel);
	//strcpy(labels[numVertices], vertexLabel);
	numVertices++;
}

void graph::shortestPath(int start){
	int *distance = new int[numVertices];
	bool *marked = new bool[numVertices];
	for (int i = 0; i < numVertices; i++){
		marked[i] = false;
	}
	vector<int> path;
	reset(distance);
	distance[start] = 0;

	cout << "Starting Dijkstra's Shortest-Distance Algorithm with vertex " << labels[start] << endl;

	int min = start;
	while (path.size() < numVertices){
		for (int v = 0; v < numVertices; v++){
			if (!marked[v]){
				if (distance[v] < distance[min]){
					min = v;
				}
			}
		}
		if (path.size()>0){
			int src = min;
			int src_index = path.size() - 1;
			while (edges[path[src_index]][min] != (distance[min] - distance[path[src_index]])){
				src_index--;
			}
			src = path[src_index];
			cout << "Vertex Pair " << labels[src] << "," << labels[min] << " ";
			cout << "    Pair Cost: " << (distance[min] - distance[src]);
			cout << "    Cost From Start: " << distance[min] << endl;
		}

		path.push_back(min);
		marked[min] = true;

		for (int i = 0; i < numVertices; i++){
			if (is_edge(min, i) && (distance[i]>(distance[min] + edges[min][i]))){
				distance[i] = edges[min][i] + distance[min];
			}
		}
		for (int x = 0; x < numVertices; x++){
			if (!marked[x]){
				min = x;
				break;
			}
		}
	}

	cout << "Ending Dijkstra's Shortest-Distance Algorithm with vertex " << labels[min] << endl;
	delete[] marked;
	delete[] distance;
}

void graph::reset(int *&dist){
	for (int i = 0; i < numVertices; i++){
		dist[i] = 999999999;
	}
}

void graph::DFS(int start){
	assert(start >= 0 && start < numVertices);

	bool* marked = new bool[numVertices];
	for (int i = 0; i < numVertices; i++){
		marked[i] = false;
	}
	cout << "Starting DFS with vertex " << labels[start] << endl;

	DFS(start, marked);
	cout << endl;
	delete[] marked;
}

void graph::DFS(int start, bool marked[]){
	assert(start >= 0 && start < numVertices);

	marked[start] = true;

	cout << labels[start] << " ";

	for (int i = 0; i < numVertices; i++){
		if (edges[start][i] > -1 && !marked[i]){
			DFS(i, marked);
		}
	}
}
bool graph::is_edge(int source, int target){
	assert(source >= 0 && source < numVertices);
	assert(target >= 0 && target < numVertices);

	return edges[source][target]> -1;
}
