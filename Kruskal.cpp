#include "Graph.h"
#include "UI.h"
#include <algorithm>

void Kruskal();
void initialize();
bool edgeCompare(const pair<pair<int, int>, int> &e1, const pair<pair<int, int>, int> &e2);
void print_MST();

Graph G;
Graph MST;
int s;
vector<pair<pair<int, int>, int> > edges;

int main(){
	run(G, Kruskal, "Kruskal");
	return 0;
}

void Kruskal(){
	initialize();
	while (MST.vertices.size() != G.vertices.size()){
		pair<pair<int, int>, int> edge = edges.front();
		edges.erase(edges.begin())
		int u = edge.first.first;
		int v = edge.first.second;
		int w = edge.second;
		// if (!MST.vertex_exist(u) || !MST.vertex_exist(v)){
		// 	MST.insert_vertex(u);
		// 	MST.insert_vertex(v);
		// 	MST.insert_edge(u, v, w);
		// }
	}
}

void initialize(){
	edges.clear();
	for (map<int, map<int, int> >::iterator itr1 = G.edges.begin(); itr1 != G.edges.end(); itr1++){
		for (map<int, int>::iterator itr2 = (itr1->second).begin(); itr2 != (itr1->second).end(); itr2++){
			pair<int, int> vertices (itr1->first, itr2->first);
			pair<pair<int, int>, int> edge (vertices, itr2->second);
			edges.push_back(edge);
		}
	}
	sort(edges.begin(), edges.end(), edgeCompare); 
}

bool edgeCompare(const pair<pair<int, int>, int> &e1, const pair<pair<int, int>, int> &e2){
	return e1.second < e2.second;
}
