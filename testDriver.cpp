#include "graph.h"
#include <iostream>

using namespace std;
	//is_edge() is used in graph.cpp and is private, doesn't need to be used in .cpp
int main(){

	//DFS

	graph d;

	d.add_vertex((char*)"V0");
	d.add_vertex((char*)"V1");
	d.add_vertex((char*)"V2");
	d.add_vertex((char*)"V3");
	d.add_vertex((char*)"V4");
	d.add_vertex((char*)"V5");
	d.add_vertex((char*)"V6");

	d.add_edge(0, 1);
	d.add_edge(0, 4);
	d.add_edge(1, 3);
	d.add_edge(2, 1);
	d.add_edge(3, 6);
	d.add_edge(3, 1);
	d.add_edge(3, 5);
	d.add_edge(6, 1);

	d.DFS(0);

	cout << endl;

	//Shortest path
	graph g;
	g.add_vertex((char *)"V0");
	g.add_vertex((char *)"V1");
	g.add_vertex((char *)"V2");
	g.add_vertex((char *)"V3");
	g.add_vertex((char *)"V4");
	g.add_vertex((char *)"V5");

	g.add_edge(0, 1, 2);
	g.add_edge(0, 5, 9);
	g.add_edge(1, 2, 8);
	g.add_edge(1, 3, 15);
	g.add_edge(1, 5, 6);
	g.add_edge(2, 3, 1);
	g.add_edge(5, 4, 3);
	g.add_edge(4, 3, 3);
	g.add_edge(4, 2, 7);

	g.shortestPath(0);

	cout << "\nDONE" << endl;
	cout << "\nEnter any key to terminate." << endl;
	char x;
	cin >> x;
	if (x){ return 0; }
	return 0;

}
