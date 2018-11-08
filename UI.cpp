#include "Graph.h"
#include "UI.h"
#include <iostream>
#include <fstream>


void run(Graph &G, void f(), string algorithm){
	int cmd;
	string menu = "1.edit 2.import 3.save 4.display 5."+algorithm+" 0.quit";
	cout << menu << endl;
	cin >> cmd; 
	while (cmd != 0) { 
		if (cmd == 1) {
			user_input_graph(G);
		} else if (cmd == 2) {
			file_input_graph(G);
		} else if (cmd == 3) {
			save_graph(G);
		} else if (cmd == 4) {
			G.print_vertices();
			G.print_edges();
		} else if (cmd == 5) {
			f();
		}
		cout << menu << endl;
		cin >> cmd;
	}
}

void user_input_graph(Graph &G){

	string cmd;
	string info = "1.insert vertex 2.insert_edge 3.remove vertex 4.remove edge 5.print vertices 6.print edge 7.clear 0.done";
	cout << info << endl;
	cin >> cmd;

	while (cmd != "0") {
		if (cmd == "1") {
			cout << "insert vertex..." << endl;
			int v;
			cin >> v;
			while (v >= 0){
				G.insert_vertex(v);
				cin >> v;
			}
			cout << "insert vertex done." << endl;
		} else if (cmd == "2") {
			cout << "1.normal 2.weighted" << endl;
			cin >> cmd;
			if (cmd == "1"){
				cout << "insert normal edge..." << endl;
				int u, v;
				cin >> u >> v;
				while (u>=0 && v>=0){
					G.insert_normal_edge(u, v);
					cin >> u >> v;
				}
			} else if (cmd == "2"){
				cout << "insert weighted edge..." << endl;
				int u, v, w;
				cin >> u >> v >> w;
				while (u>=0 && v>=0){
					G.insert_weighted_edge(u, v, w);
					cin >> u >> v >> w;
				}
			}
			cout << "insert edges done" << endl;
		} else if (cmd == "3") {
			cout << "remove vertex..." << endl;
			int v;
			cin >> v;
			while (v >= 0){
				G.remove_vertex(v);
				cin >> v;
			}
			cout << "remove vertex done." << endl;
		} else if (cmd == "4") {
			cout << "remove normal edge..." << endl;
			int u, v;
			cin >> u >> v;
			while (u>=0 && v>=0){
				G.remove_edge(u, v);
				cin >> u >> v;
			}
			cout << "remove edges done" << endl;
		} else if (cmd == "5") {
			cout << "vertices:" << endl;
			G.print_vertices();
		} else if (cmd == "6") {
			cout << "edge:" << endl;
			G.print_edges();
		} else if (cmd == "7") {
			G.clear();
		}
		cout << info << endl;
		cin >> cmd;
	}
}

void file_input_graph(Graph &G){
	string filename;
	cout << "file name: ";
	cin >> filename;
	ifstream fin;
	fin.open(filename);
	if (fin.fail()) {
		cout << "Error Open File!" << endl;
		return;
	}
	string input;
	int u, v, w;
	while (fin.good()) {
		fin >> v;
		if (v < 0){
			break;
		}
		G.insert_vertex(v);
	}
	while (fin.good()) {
		fin >> u >> v >> w;
		G.insert_edge(u, v, w);
	}
	fin.close();
}

void save_graph(Graph &G){
	string filename;
	cout << "file name: " << endl;
	cin >> filename;
	ofstream fout;
	fout.open(filename);

	for (vector<int>::iterator itr = G.vertices.begin(); itr != G.vertices.end(); itr++) {
		fout << *itr << " ";
	}
	fout << -1 << endl;

	for (map<int, map<int, int> >::iterator itr1 = G.edges.begin(); itr1 != G.edges.end(); itr1++) {
		for (map<int, int>::iterator itr2 = itr1->second.begin(); itr2 != itr1->second.end(); itr2++) {
			fout << itr1->first << " " << itr2->first << " " << itr2->second << endl;
		}
	}

	fout.close();
}




