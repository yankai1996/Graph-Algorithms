#include "Graph.h"
#include "UI.h"
#include <iostream>

void BellmanFord();
void initialize();
void print_dist();

Graph G;
int s;
map<int, int> dist;

int main(){
	run(G, BellmanFord, "Bellman-Ford");
	return 0;
}

void BellmanFord(){
	initialize();
	for (int i=0; i<G.vertices.size(); i++){
		for (vector<int>::iterator itr1 = G.vertices.begin(); itr1 != G.vertices.end(); itr1++){
			for (map<int, int>::iterator itr2 = G.edges[*itr1].begin(); itr2 != G.edges[*itr1].end(); itr2++){
				dist[itr2->first] = min(dist[itr2->first], dist[*itr1]+itr2->second);
			}
		}
	}
	print_dist();
}

void initialize(){
	cout << "Bellman-Ford starting with: " << endl;
	cin >> s;
	for (vector<int>::iterator itr = G.vertices.begin(); itr != G.vertices.end(); itr++){
		dist[*itr] = 10000;
	}
	dist[s] = 0;
}

void print_dist(){
	for (vector<int>::iterator itr = G.vertices.begin(); itr != G.vertices.end(); itr++){
		printf("dist(%d)=%d ", *itr, dist[*itr]);
	}
	cout << endl;
}