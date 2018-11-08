#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <map>
using namespace std;

class Graph
{
private:
	
public:
	vector<int> vertices;
	map<int, map<int, int> > edges;
	map<int, map<int, int> > edgesBackup;

	Graph();
	Graph(const Graph &G);
	bool vertex_exist(int v);
	bool edge_exist(int u, int v);
	void insert_vertex(int v);
	void insert_edge(int u, int v, int w);
	void insert_normal_edge(int u, int v);
	void insert_weighted_edge(int u, int v, int w);
	void remove_vertex(int v);
	void remove_edge(int u, int v);
	void print_vertices();
	void print_edges();
	void clear();

	void undirected();
	void directed();

};

#endif