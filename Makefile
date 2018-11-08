# all: Graph.o UI.o BellmanFord BFS CC DFS Dijkstra Kruskal Prims SCC
# 
Graph.o: Graph.cpp
	g++ -c $<
	mv $@ bin 

UI.o: UI.cpp
	g++ -c $<
	mv $@ bin

DFS.o: DFS.cpp
	g++ -c $<
	mv $@ bin
#

BellmanFord: BellmanFord.cpp ./bin/Graph.o ./bin/UI.o
	g++ $^ -o $@
	mv $@ bin

BFS: BFS.cpp ./bin/Graph.o ./bin/UI.o
	g++ $^ -o $@
	mv $@ bin

CC: CC.cpp ./bin/Graph.o ./bin/UI.o
	g++ $^ -o $@
	mv $@ bin

Dijkstra: Dijkstra.cpp ./bin/Graph.o ./bin/UI.o
	g++ $^ -o $@
	mv $@ bin

Kruskal: Kruskal.cpp ./bin/Graph.o ./bin/UI.o
	g++ $^ -o $@
	mv $@ bin

Prims: Prims.cpp ./bin/Graph.o ./bin/UI.o
	g++ $^ -o $@
	mv $@ bin

SCC: SCC.cpp ./bin/Graph.o ./bin/UI.o
	g++ $^ -o $@
	mv $@ bin


.PHONY: run1 run2 run3 run4 run5
