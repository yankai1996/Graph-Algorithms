#include "DFS.cpp"
#include <iostream>
#include "UI.h"

void find_CCs();
void create_CC(Graph &SCC);

vector<Graph> CCs;

int main(){
	run(G, find_CCs, "find CCs");
	return 0;
}

void find_CCs(){
	G.undirected();
	CCs.clear();
	vector<int> vertices(G.vertices);
	initialize();
	while (!vertices.empty()) {
		int current = vertices.back();
		vertices.pop_back();
		if (!visited[current]){
			visited[current] = true;
			explore(current);
			Graph CC;
			create_CC(CC);
			CCs.push_back(CC);
		}
	}
	cout << CCs.size() << " CCs:" << endl;
	for (vector<Graph>::iterator itr = CCs.begin(); itr != CCs.end(); itr++){
		(*itr).print_vertices();
	}

}

void create_CC(Graph &CC){
	for (vector<int>::iterator itr1 = G.vertices.begin(); itr1 != G.vertices.end(); itr1++){
		if (visited[*itr1]){
			CC.insert_vertex(*itr1);
			for (map<int, int>::iterator itr2 = G.edges[*itr1].begin(); itr2 != G.edges[*itr1].end(); itr2++){
				if (visited[itr2->first]){
					CC.insert_edge(*itr1, itr2->first, itr2->second);
				}
			}
		}
	}
	for (vector<int>::iterator itr = CC.vertices.begin(); itr != CC.vertices.end(); itr++){
		G.remove_vertex(*itr);
	}
}