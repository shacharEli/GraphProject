#ifndef _DFS_
#define _DFS_
#include "Search.h"
#include "Graph.h"
#include<map>
#include"Vertex.h"
#include"Edge.h"
#include<vector>
#include<iostream>
#include <stdlib.h>
#include<iterator>
#include <stack>
#include "UndefinedVertice.h"

using namespace std;


class DFS:public Search
{
private:
    stack<Vertex*> path;
    int m_count;
	void dfsVisited(Vertex* v);

public:

    DFS(){};
	virtual~DFS(){};
	void dfsAlgo(Graph* tGraph,string start);
	const int getCount() const;
	void setCount(int count);
	//void restorationDFS(map<string,Vertex *> mapV,string first);

};

#endif
