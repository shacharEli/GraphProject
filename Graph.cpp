#include"Graph.h"
#include<string>
#include<vector>
#include<map>
#include <fstream>
#include<iostream>
#include <stdlib.h>

using namespace std;

//Default constractor
Graph::Graph(){};


//Constructor that recieve file path and create the vertexs/edges from the file
Graph::Graph(map<string,Vertex *> *graph)
{
	 m_mapVertex = graph;
}

//Default destructor
Graph::~Graph()
{
   
	//map<string,Vertex>::iterator it;

	//Going over the map of vertex
	//for(it = m_mapVertex.begin(); it != m_mapVertex.end();it++)
	//{

	//}
}




//Print the graph
void Graph::printGraph()
{
	map<string,Vertex*>::iterator it;
    cout << "I am in: printGraph()" << endl;
    cout << (*m_mapVertex).size() << endl;
	for(it = (*(m_mapVertex)).begin(); it != (*(m_mapVertex)).end(); it++)
	{
		cout << *(it->second) << endl;
	}
}

const map<string,Vertex *>* Graph::GetMap()
{
	return m_mapVertex;
}
map<string,Vertex *>* Graph::getMap()
{
	return m_mapVertex;
}





