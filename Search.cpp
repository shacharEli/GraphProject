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
#include<stack>
using namespace std;

//constructor
Search::Search(Graph* tGrap)
{
    /*
	map<string,Vertex *>::const_iterator it;
	int count=0;
	Vertex v;

	for (it = (*(tGrap->GetMap())).begin();it != (*(tGrap->GetMap())).end();++it)
	{
		mapVertex[it->first]=new Vertex (*(it->second));

	}
    */
}

//Default destructor
Search::~Search()
{
   
    /*
	map<string,Vertex *>::iterator it;
	for(it = mapVertex.begin(); it != mapVertex.end(); it++)
	    {
	        delete (it->second);
	    }
    */
}

//Method to create backup of the edges wight
map<string,double> Search::saveEdgesParmaters(Graph *tGraph)
{
    map<string,double> edgeMapBackup;
    map<string,Vertex *>::const_iterator itMap;
    vector<Edge *>::const_iterator itVec;
    Vertex *v;
    vector<Edge *> tEdgeVec;
    string key;

    //Main loop that goes on the Vertexes map
    for(itMap = tGraph->GetMap()->begin(); itMap != tGraph->GetMap()->end(); itMap++)
    {
        v = itMap->second;
        tEdgeVec = v->getEdges();
        //going over the vertex edges
        for(itVec = (tEdgeVec).begin(); itVec != (tEdgeVec).end(); itVec++)
        {
            //cout << ((*itVec)->getDest())->getSymbol() << endl;
            key = itMap->first + ";" + ((*itVec)->getDest())->getSymbol();
            edgeMapBackup[key] = (*itVec)->getWight();
            //cout << key << ";" << edgeMapBackup[key]<< endl;
        }
    }
    //cout << "End of saveEdgesParmaters" << endl;
    return edgeMapBackup;

}

//Initalizing the graph parameters
void Search::initializeGraphParams(Graph *pGraph, map<string,double> edgeInfo)
{
    map<string,Vertex *>::const_iterator itMap;
    map<string,double>::iterator itMap2;
    vector<Edge *>::const_iterator itVec;
    Vertex *v;
    vector<Edge *> tEdgeVec;
    string key;
    double eWeight;

   //Initializing the vertexes parameters
    for(itMap = (*pGraph).GetMap()->begin(); itMap != (*pGraph).GetMap()->end(); itMap++)
    {
        itMap->second->SetPrevious("");
        itMap->second->SetVisited(false);
        itMap->second->SetDistance(-1);
        //Initializing the edges parameters
        v = itMap->second;
        tEdgeVec = v->getEdges();
        //going over the vertex edges
        for(itVec = (tEdgeVec).begin(); itVec != (tEdgeVec).end(); itVec++)
        {
            key = itMap->first + ";" +(*itVec)->getDest()->getSymbol();
            eWeight = edgeInfo[key];
            (*itVec)->setWight(eWeight);
        }
    }
}

//Return the map vertex value
map<string,Vertex *> Search::getMapVertex()
{
    return mapVertex;
}

void Search::PrintPath(stack<Vertex*> path)
{
	Vertex* current;
	Vertex* next;
	vector<Edge *>::const_iterator itVec;
	vector<Edge *> tEdgeVec;

	while (!path.empty())
	{
		current=path.top();
		path.pop();
		current->printVertex();
		if (path.empty())
			break;
        cout << ",";
		next=path.top();
		tEdgeVec=current->getEdges();
		for(itVec=tEdgeVec.begin();itVec != tEdgeVec.end();itVec++)
		{
			if ((*itVec)->getDest()->getSymbol()==next->getSymbol())
			{
				//cout<<","<<flush;
				cout<<(*(*itVec));
				//cout<<","<<flush;
				break;
			}
		}

	}
	cout<<"\n";
}




