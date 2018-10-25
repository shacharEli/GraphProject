#ifndef SEARCH_H
#define SEARCH_H

#include "Search.h"
#include "Graph.h"
#include<queue>
#include<map>
#include"Vertex.h"
#include"Edge.h"
#include<vector>
#include<iostream>
#include <stdlib.h>
#include<iterator>
#include <fstream>
#include <stack>

using namespace std;


class Search
{
private:
	map<string,Vertex *> mapVertex;
public:
//Methods
	Search(){};
	Search(Graph* tGraph);
	virtual ~Search();
	 map<string,double> saveEdgesParmaters(Graph *tGraph);
    void initializeGraphParams(Graph *pGraph, map<string,double> edgeInfo);
    map<string,Vertex *> getMapVertex();
    void PrintPath(stack<Vertex*>path);
};

#endif // SEARCH_H
