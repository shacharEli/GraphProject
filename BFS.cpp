#include"Vertex.h"
#include"Edge.h"
#include"Graph.h"
#include <vector>
#include <map>
#include <stack>
#include "Search.h"
#include "BFS.h"
#include "UndefinedVertice.h"
using namespace std;


//Default constructor
BFS::BFS(){}

//Default destructor
BFS::~BFS()
{
   ///  << "I am in ~BFS" << endl;
}

//BFS algorithm
void BFS::bfsAlgo(Graph tGraph,string start, string vend, string algoType)
{
    //cout << "I am in: bfsAlgo(Graph tGraph,string start, string end)" << endl;
    map<string,Vertex *>::const_iterator itMap;
     //map<string,Vertex *>::const_iterator itmap;
    map<string,double> edgeMapBackup;
    map<string,double>::iterator itMap2;
    vector<Edge *>::const_iterator itVec;
    vector<Edge *> tEdgeVec;
    stack<Vertex* > vStack;
    Vertex *v;
    bool isFirst = true;
   // cout << "Starting BFS::bfsAlgo" << endl;
    edgeMapBackup = saveEdgesParmaters(&tGraph);
    /*for(itMap2 = edgeMapBackup.begin(); itMap2 != edgeMapBackup.end(); itMap2++)
    {
        cout << itMap2->first << ";" << itMap2->second << endl;
    }*/
    if(algoType == "-bfs")
    {
        //cout << "Running BFS algorithem:" << endl;
        bfsInitializeWight(&tGraph);
    }
    // checking if the end and start vertice is exist
    itMap = tGraph.GetMap()->find(vend);
    if(itMap == tGraph.GetMap()->end())
    {
        throw UndefinedVertice(vend);
    }
    itMap = tGraph.GetMap()->find(start);
    if(itMap == tGraph.GetMap()->end())
    {
        throw UndefinedVertice(start);
    }
    //Initializing the start vertex and pushing it to the stack
    itMap->second->SetDistance(0);
    vStack.push(itMap->second);
    while (!vStack.empty())
    {
        if(algoType == "-dijkstra" && !isFirst)
        {
            vStack = dijkstraNextMin(vStack);
        }
        isFirst = true;
        v = vStack.top();
        vStack.pop();
        tEdgeVec = v->getEdges();
        //cout << "Before start for" << endl;
        //going over the neighbors of v and check if need to be update or not
        for(itVec = (tEdgeVec).begin(); itVec != (tEdgeVec).end(); itVec++)
        {
            // in case start=vend and we are running bfs
            if(algoType == "-bfs" && (*itVec)->getSource()->getSymbol()==(*itVec)->getDest()->getSymbol())
            {
                (dynamic_cast<Vertex*>((*itVec)->getDest()))->SetPrevious(v->getSymbol());
            }
            //Check if the neighbor was never visited or its current distance is higer the distance from v to start +1
            if(((Vertex*)(*itVec)->getDest())->GetDistance() == -1 || ((Vertex*)(*itVec)->getDest())->GetDistance() > (v->GetDistance() + (*itVec)->getWight()))
            {
                //seting the neighbor distance to be the distance from v to start + 1
                (dynamic_cast<Vertex*>((*itVec)->getDest()))->SetPrevious(v->getSymbol());
                ((Vertex*)(*itVec)->getDest())->SetDistance(v->GetDistance() + (*itVec)->getWight());
                vStack.push(dynamic_cast<Vertex*>((*itVec)->getDest()));
            }
        }
    }
    //Printing the shortest road to the destenation vertex
    itMap = tGraph.GetMap()->find(vend);
    if((itMap->second)->GetPrevious() != "")
    {
        vStack.push(itMap->second);
        //cout << "I am in: bfsAlgo starting to push" << endl;
        while(itMap->second->GetPrevious() != start)
        {
            //cout << itMap->second->getAncVertex() << endl;
            itMap = tGraph.GetMap()->find(itMap->second->GetPrevious());
            vStack.push(itMap->second);
            //cout << "push: " << itMap->second->getSymbol() << endl;
        }
        //cout << "I am in: bfsAlgo complete pushing" << endl;
        if(itMap->second->GetPrevious() == start)
        {
            // cout<< "i am empty"<< endl;
            itMap = tGraph.GetMap()->find(start);
            vStack.push(itMap->second);
            this->PrintPath(vStack);
        }
    }
    //Initializing the graph parameters
    initializeGraphParams(&tGraph, edgeMapBackup);
}

//Initalizing the weight for all edges to be 1 for bfs algorithem
void BFS::bfsInitializeWight(Graph *pGraph)
{
    map<string,Vertex *>::const_iterator itMap;
    vector<Edge *>::const_iterator itVec;
    Vertex *v;
    vector<Edge *> tEdgeVec;

   //Initializing the vertexes parameters
    for(itMap = (*pGraph).GetMap()->begin(); itMap != (*pGraph).GetMap()->end(); itMap++)
    {
        //Initializing the edges parameters
        v = itMap->second;
        tEdgeVec = v->getEdges();
        //going over the vertex edges
        for(itVec = (tEdgeVec).begin(); itVec != (tEdgeVec).end(); itVec++)
        {
            (*itVec)->setWight(1);
        }
    }
    //cout << "End of bfsInitializeWight" << endl;
}

//Return stack with the minimum value on top
stack<Vertex* > BFS::dijkstraNextMin(stack<Vertex* > vertexStack)
{
    stack<Vertex* > tempStack;
    Vertex *tempVertex, *minVertex;

    tempVertex = NULL;
    minVertex = NULL;
    //Going over the stack and finding the minimum
    while(!vertexStack.empty())
    {
        tempVertex = vertexStack.top();
        vertexStack.pop();
        if(minVertex == NULL || tempVertex->GetDistance() < minVertex->GetDistance())
        {
            tempStack.push(minVertex);
            minVertex = tempVertex;
        }
        else
        {
            tempStack.push(tempVertex);
        }
    }
    //Return all values to original stack and put on the top the minimum
    while(!tempStack.empty())
    {
        tempVertex = tempStack.top();
        tempStack.pop();
        vertexStack.push(tempVertex);
    }
    vertexStack.push(minVertex);

    return vertexStack;
}






