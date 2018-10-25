#ifndef _BFS_
#define _BFS_

#include"Vertex.h"
#include"Edge.h"
#include"Graph.h"
#include <vector>
#include <map>
#include <stack>
#include "Search.h"
#include "UndefinedVertice.h"



class BFS:public Search
{


public:
		BFS();
	    virtual~BFS();
	    void bfsAlgo(Graph tGraph,string start, string vend, string algoType);
	    void bfsInitializeWight(Graph *pGraph);
	    stack<Vertex* > dijkstraNextMin(stack<Vertex* > vertexStack);
};

#endif
