#include "Graph.h"
#include "UI.h"
#include <iostream>

void Prims();
void initialize();
void update();
void print_MST();

Graph G;
Graph MST;
int s;

int main(){
	run(G, Prims, "Prim's Algorithm");
	return 0;
}

void Prims(){
	MST.insert_vertex(G.vertices.front());
	G.undirected();
		while (MST.vertices.size() != G.vertices.size()){
			update();
		}
	G.directed();
	print_MST();
}

void update(){
	int u, v;	// mark the shortest outgoing edge
	int w = 10000;
	for (vector<int>::iterator itr1 = MST.vertices.begin(); itr1 != MST.vertices.end(); itr1++){
		for (map<int, int>::iterator itr2 = G.edges[*itr1].begin(); itr2 != G.edges[*itr1].end(); itr2++){
			if (!MST.vertex_exist(itr2->first)){
				if (itr2->second < w){
					 u = *itr1;
					 v = itr2->first;
					 w = itr2->second;
				}
			} 
		}
	}
	MST.insert_vertex(v);
	MST.insert_edge(u, v, w);
}

void print_MST(){
	cout << "MST:" << endl;
	MST.print_vertices();
	MST.print_edges();
}

