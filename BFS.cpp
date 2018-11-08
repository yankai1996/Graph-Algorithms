#include "Graph.h"
#include "UI.h"
#include <queue>
#include <iostream>

void BFS(int s);
void shortest_path(int u, int v);
void find_shortest_path();
void find_undirected_shortest_path();

Graph G;
map<int, int> previous;
map<int, bool> visited;
int destination;
bool found;

int main(){
	run(G, find_undirected_shortest_path, "shortest path");
	return 0;
}

void BFS(int s){
	visited.clear();
	for (vector<int>::iterator itr = G.vertices.begin(); itr != G.vertices.end(); itr++){
		visited[*itr] = false;
	}
	found = false;
	visited[s] = true;
	previous[s] = -1;
	queue<int> q;
	q.push(s);
	int current;
	while (!q.empty() || !found) {
		current = q.front();
		q.pop();
		for (map<int, int>::iterator itr = G.edges[current].begin(); !found && itr != G.edges[current].end(); itr++){
			if (!visited[itr->first]){
				visited[itr->first] = true;
				previous[itr->first] = current;
				q.push(itr->first);
				if (itr->first == destination) {
					found = true;
				}
			}
		}
	}


}

void shortest_path(int s, int t){
	if (!G.vertex_exist(s) || !G.vertex_exist(t)){
		cout << "Vertex Does Not Exist!" << endl;
		return;
	}
	destination = t;
	BFS(s);
	if (!found) {
		cout << "no shortest path!" << endl;
		return;
	}
	vector<int> path;
	path.push_back(destination);
	int current = destination;
	while (previous[current] != -1) {
		path.insert(path.begin(), previous[current]);
		current = previous[current];
	}
	cout << "shortest path: ";
	for (vector<int>::iterator itr = path.begin(); itr != path.end(); itr++){
		cout << *itr << " ";
	}
	cout << endl;
}

void find_shortest_path(){
	cout << "find shortest path..." << endl;
	int u, v;
	cin >> u >> v;
	shortest_path(u, v);
}

void find_undirected_shortest_path(){
	G.undirected();
	cout << "find undirected shortest path..." << endl;
	int u, v;
	cin >> u >> v;
	shortest_path(u, v);
	G.directed();
}


