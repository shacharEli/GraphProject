ProgramGraph: Rvertex.o Vertex.o Edge.o Graph.o IO.o main.o Search.o DFS.o Edgec.o AutoEdge.o AutoVertex.o BFS.o Automate.o OutOfMemory.o FileDoesNotExist.o UndefinedVertice.o InvalidInput.o
	g++ Rvertex.o Vertex.o Edge.o main.o Graph.o IO.o Search.o DFS.o Edgec.o AutoEdge.o AutoVertex.o BFS.o Automate.o OutOfMemory.o FileDoesNotExist.o UndefinedVertice.o InvalidInput.o -o ProgramGraph

Rvertex.o: Rvertex.h
	g++ -c -g Rvertex.cpp

Vertex.o: Vertex.h Vertex.cpp Rvertex.h Edge.h Edgec.h
	g++ -c -g Vertex.cpp

AutoVertex.o: AutoVertex.h AutoVertex.cpp Vertex.h
	g++ -c -g AutoVertex.cpp

Edge.o: Edge.h Edge.cpp Rvertex.h
	g++ -c -g Edge.cpp

AutoEdge.o: AutoEdge.h AutoEdge.cpp Edge.h
	g++ -c -g AutoEdge.cpp

Graph.o: Graph.h Graph.cpp Vertex.h Edge.h
	g++ -c -g Graph.cpp

IO.o: IO.h IO.cpp Graph.h Vertex.h Edge.h Search.h DFS.h OutOfMemory.h FileDoesNotExist.h UndefinedVertice.h InvalidInput.cpp
	g++ -c -g IO.cpp

DFS.O: DFS.h DFS.cpp Graph.h Vertex.h Edge.h Search.h
	g++ -c -g DFS.cpp

BFS.o: BFS.h BFS.cpp Search.h Vertex.h Graph.h Edge.h UndefinedVertice.h
	g++ -c -g BFS.cpp

Automate.o: Automate.h Automate.cpp Graph.h AutoEdge.h AutoVertex.h
	g++ -c -g Automate.cpp

Search.o: Search.h Search.cpp Graph.h Vertex.h Edge.h
	g++ -c -g Search.cpp

Edgec.o: Edgec.h Edgec.cpp Rvertex.h Edge.h
	g++ -c -g Edgec.cpp

OutOfMemory.o: OutOfMemory.h OutOfMemory.cpp
	g++ -c -g OutOfMemory.cpp

FileDoesNotExist.o: FileDoesNotExist.h FileDoesNotExist.cpp
	g++ -c -g FileDoesNotExist.cpp

UndefinedVertice.o: UndefinedVertice.cpp UndefinedVertice.h
	g++ -c -g UndefinedVertice.cpp

InvalidInput.o: InvalidInput.h InvalidInput.cpp
	g++ -c -g InvalidInput.cpp

main.o: main.cpp Rvertex.h Vertex.h Edge.h Graph.h IO.h
	g++ -c -g main.cpp

clean:
	 rm -f *.o
