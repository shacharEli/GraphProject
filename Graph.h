#ifndef _GRAPH_
#define _GRAPH_

#include"Vertex.h"
#include"Edge.h"
#include<string>
#include<vector>
#include<map>
#include <fstream>
#include<iostream>

using namespace std;

class Graph
{
private:
	map<string,Vertex *> *m_mapVertex;

public:
//Methods:
	Graph();
	Graph(map<string,Vertex *> *graph);
	virtual~Graph();
	void printGraph();
	const map<string,Vertex *>* GetMap();
	map<string,Vertex *>* getMap();
	//void PrintPath(stack<Vertex *> path);

};


#endif
