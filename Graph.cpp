#include "Graph.h"
#include <iostream>
#include <string>
#include <algorithm>

Graph::Graph(){
	cout << "Graph Created." << endl;
}

Graph::Graph(const Graph &G){
	vector<int> _vertices(G.vertices);
	map<int, map<int, int> > _edges(G.edges);
	vertices = _vertices;
	edges = _edges;
}

bool Graph::vertex_exist(int v){
	return binary_search(vertices.begin(), vertices.end(), v);
}

void Graph::insert_vertex(int v){
	if (!vertex_exist(v)){
		vertices.push_back(v);
		sort(vertices.begin(), vertices.end());
	} else {
		printf("Vertex %d Exists!\n", v);
	}
}

bool Graph::edge_exist(int u, int v){
	if (edges.count(u) > 0){
		if (edges[u].count(v) > 0){
			return true;
		}
	}
	return false;
}

void Graph::insert_edge(int u, int v, int w){
	if (u == v) {
		cout << "Self Loop!" << endl;
		return;
	}
	if (!vertex_exist(u) || !vertex_exist(v)){
		cout << "Vertex Does Not Exist!" << endl;
		return;
	}
	if (!edge_exist(u, v)){
		printf("insert egde (%d,%d) = %d\n", u, v, w);
	} else {
		printf("update egde (%d,%d) = %d\n", u, v, w);
	}
	edges[u][v] = w;
}

void Graph::insert_normal_edge(int u, int v){
	insert_edge(u, v, 1);
}

void Graph::insert_weighted_edge(int u, int v, int w){
	insert_edge(u, v, w);
}

void Graph::remove_vertex(int v) {
	if (!vertex_exist(v)){
		cout << "Vertex Does Not Exist!" << endl;
		return;
	}
	for (map<int, map<int, int> >::iterator itr = edges.begin(); itr != edges.end(); itr++){
		itr->second.erase(v);
	}
	edges.erase(v);
	vector<int>::iterator itr = find(vertices.begin(), vertices.end(), v);
	vertices.erase(itr);
	// cout << "remove vertex " << v << endl;
}

void Graph::remove_edge(int u, int v){
	if (vertex_exist(u) && vertex_exist(v) && edge_exist(u, v)){
		edges[u].erase(v);
		// printf("remove edge (%d,%d)\n", u, v);
	} else {
		cout << "Edge Does Not Exist!" << endl;
	}
}

void Graph::print_vertices(){
	for (vector<int>::iterator itr = vertices.begin(); itr != vertices.end(); itr++){
		cout << *itr << " ";
	}
	cout << endl;
}

void Graph::print_edges(){
	for (map<int, map<int, int> >::iterator itr1 = edges.begin(); itr1 != edges.end(); itr1++){
		for (map<int, int>::iterator itr2 = itr1->second.begin(); itr2 != itr1->second.end(); itr2++){
			printf("(%d,%d) = %d  ", itr1->first, itr2->first, itr2->second);
		}
		cout << endl;
	}
}

void Graph::clear(){
	vertices.clear();
	edges.clear();
}

void Graph::undirected(){
	map<int, map<int, int> > temp(edges);
	edgesBackup = temp;
	for (map<int, map<int, int> >::iterator itr1 = edges.begin(); itr1 != edges.end(); itr1++){
		for (map<int, int>::iterator itr2 = itr1->second.begin(); itr2 != itr1->second.end(); itr2++){
			edges[itr2->first][itr1->first] = itr2->second;
		}
	}
}

void Graph::directed(){
	edges = edgesBackup;
}




