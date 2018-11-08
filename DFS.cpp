#include "Graph.h"

void initialize();
void DFS(int s);
void DFS(int s, int t);
void explore(int current);
void explore(int current, int destination);
void calculate_post();
void undirected_DFS(int s);
void undirected_DFS(int s, int t);

Graph G;
map<int, int> previous;
map<int, bool> visited;
bool found;
int counter;
map<int, int> post; // post[counter] = v;

void initialize(){
	visited.clear();
	for (vector<int>::iterator itr = G.vertices.begin(); itr != G.vertices.end(); itr++){
		visited[*itr] = false;
	}
	found = false;
	counter = 1;
}

void DFS(int s){
	initialize();
	visited[s] = true;
	previous[s] = -1;
	explore(s);

}

void DFS(int s, int t){
	initialize();
	visited[s] = true;
	previous[s] = -1;
	explore(s, t);
}

void explore(int current){
	for (map<int, int>::iterator itr = G.edges[current].begin(); itr != G.edges[current].end(); itr++){
		if (!visited[itr->first]){
			visited[itr->first] = true;
			previous[itr->first] = current;
			explore(itr->first);
		}
	}
	post[counter] = current;
	counter++;
}

void explore(int current, int destination){
	if (current == destination) {
		found = true;
		return;
	}
	for (map<int, int>::iterator itr = G.edges[current].begin(); !found && itr != G.edges[current].end(); itr++){
		if (!visited[itr->first]){
			visited[itr->first] = true;
			previous[itr->first] = current;
			explore(itr->first);
		}
	}
}

void calculate_post(){
	initialize();
	for (map<int, bool>::iterator itr = visited.begin(); itr != visited.end(); itr++){
		if (!itr->second){
			itr->second = true;
			explore(itr->first);
		}
	}
}

void undirected_DFS(int s){
	G.undirected();
	DFS(s);
	G.directed();
}

void undirected_DFS(int s, int t){
	G.undirected();
	DFS(s, t);
	G.directed();
}



