#include "DFS.cpp"
#include "UI.h"
#include <iostream>

void find_SCCs();
void create_SCC(Graph &SCC);
void reverse_graph();

vector<Graph> SCCs;
vector<int> postorder;

int main(){
	run(G, find_SCCs, "find SCCs");
	return 0;
}

void find_SCCs(){
	SCCs.clear();
	postorder.clear();
	reverse_graph();
	calculate_post();
	for (int i=1; i<=G.vertices.size(); i++) {
		postorder.push_back(post[i]);
	}
	reverse_graph();
	initialize();
	while (!postorder.empty()) {
		int current = postorder.back();
		postorder.pop_back();
		if (!visited[current]){
			visited[current] = true;
			explore(current);
			Graph SCC;
			create_SCC(SCC);
			SCCs.push_back(SCC);
		}
	}
	cout << SCCs.size() << " SCCs:" << endl;
	for (vector<Graph>::iterator itr = SCCs.begin(); itr != SCCs.end(); itr++){
		(*itr).print_vertices();
	}
}

void create_SCC(Graph &SCC){
	for (vector<int>::iterator itr1 = G.vertices.begin(); itr1 != G.vertices.end(); itr1++){
		if (visited[*itr1]){
			SCC.insert_vertex(*itr1);
			for (map<int, int>::iterator itr2 = G.edges[*itr1].begin(); itr2 != G.edges[*itr1].end(); itr2++){
				if (visited[itr2->first]){
					SCC.insert_edge(*itr1, itr2->first, itr2->second);
				}
			}
		}
	}
	for (vector<int>::iterator itr = SCC.vertices.begin(); itr != SCC.vertices.end(); itr++){
		G.remove_vertex(*itr);
	}
}

void reverse_graph(){
	map<int, map<int, int> > temp;
	for (map<int, map<int, int> >::iterator itr1 = G.edges.begin(); itr1 != G.edges.end(); itr1++){
		for (map<int, int>::iterator itr2 = itr1->second.begin(); itr2 != itr1->second.end(); itr2++){
			temp[itr2->first][itr1->first] = itr2->second;
		}
	}
	G.edges.clear();
	G.edges.insert(temp.begin(), temp.end());
}