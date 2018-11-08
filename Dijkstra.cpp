#include "Graph.h"
#include "UI.h"
#include <cmath>
#include <iostream>

void Dijkstra();
void initialize();
void update();
void print_SPT();

Graph G;
Graph SPT;
int s;
map<int, int> dist;
map<int, map<int, int> > outEdges;

int main(){
	run(G, Dijkstra, "Dijkstra");
	return 0;
}

void Dijkstra(){
	initialize();
	while (SPT.vertices.size() != G.vertices.size()){
		update();
	}
	print_SPT();
}

void update(){
	int u, v;	// mark the shortest outgoing edge
	int w = 10000;
	for (vector<int>::iterator itr1 = SPT.vertices.begin(); itr1 != SPT.vertices.end(); itr1++){
		for (map<int, int>::iterator itr2 = G.edges[*itr1].begin(); itr2 != G.edges[*itr1].end(); itr2++){
			if (!SPT.vertex_exist(itr2->first)){
				outEdges[*itr1][itr2->first] = itr2->second;
				dist[itr2->first] = min(dist[itr2->first], dist[*itr1]+itr2->second);
				if (itr2->second < w){
					 u = *itr1;
					 v = itr2->first;
					 w = itr2->second;
				}
			} else {
				outEdges[*itr1].erase(itr2->first);
			}
		}
	}
	SPT.insert_vertex(v);
	for (map<int, map<int, int> >::iterator itr = outEdges.begin(); itr != outEdges.end(); itr++){
		if (itr->second.count(v) > 0){
			if (dist[itr->first] + (itr->second)[v] == dist[v]){
				u = itr->first;
				w = (itr->second)[v];
			}
		}
	}
	SPT.insert_edge(u, v, w);
}

void initialize(){
	cout << "find SPT starting with: " << endl;
	cin >> s;
	SPT.insert_vertex(s);
	for (vector<int>::iterator itr = G.vertices.begin(); itr != G.vertices.end(); itr++){
		dist[*itr] = 10000;
	}
	dist[s] = 0;
	outEdges.clear();
}

void print_SPT(){
	for (map<int, int>::iterator itr = dist.begin(); itr != dist.end(); itr++){
		printf("dist(%d)=%d ", itr->first, itr->second);
	}
	cout << endl << "SPT:" << endl;
	SPT.print_edges();
}

