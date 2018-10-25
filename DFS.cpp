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
#include "DFS.h"
#include <stack>
#include "Search.h"
#include "UndefinedVertice.h"


//DFS general algoritem
void DFS::dfsAlgo(Graph* tGraph,string start)
{
	map<string,Vertex *>::const_iterator it;
	Vertex* temp;

    this->setCount((tGraph->GetMap())->size());
	while(!path.empty())
	{
	    path.pop();
	}
	it = (tGraph->GetMap())->find(start);
	if (it != (tGraph->GetMap())->end())
	{

		temp=it->second;
		dfsVisited(temp);

		while(this->getCount() > 0)
		{
            for(it = tGraph->GetMap()->begin(); it != tGraph->GetMap()->end(); it++)
            {
                if(it->second->GetPrevious()!="black")
                {
                    temp=it->second;
                    dfsVisited(temp);
                }
            }
		}

		// call function the print the topological search
		while(!path.empty())
		{
		    cout<< path.top()->getSymbol()<<flush;
		    path.pop();
		    if(!path.empty())
		    {
		        cout<<","<<flush;
		    }
		}
		cout<<" "<<endl;

	}
	else
	{
	    throw UndefinedVertice(start);
	}
	while(!path.empty())
	{
	    path.pop();
	}
}

// Dfs recursive algoritem
void DFS::dfsVisited(Vertex* v)
{
	int count;
	Vertex *temp;
	map<string,Vertex *>::const_iterator it;
	vector<Edge *>::iterator vec;
	if(v->GetPrevious()!="black")
	{
	    v->SetPrevious("gray");
	}
	vector<Edge *> tEdgeVec;
	if (v->getEdges().size()>0)
    {
        //going through all thr vertex neighbors and check if we visit them
        tEdgeVec = v->getEdges();
        count=v->getEdges().size();
        for ( vec = tEdgeVec.begin(); vec != tEdgeVec.end() ; vec++)
        {
            if (v->getEdges().size()>0 && count>0)
            {
                //cout<< v->getSymbol()<<" "<<v->getEdges().size()<<endl;
                count--;
                temp = (Vertex*)((*vec)->getDest());
                if(temp!=NULL)
                {
                    if(temp->GetPrevious()!="black")
                    {
                        temp->SetPrevious("gray");
                        dfsVisited(temp);
                    }

                }
            }
        }
	}
	if (v->GetPrevious()=="gray")
	{
        v->SetPrevious("black");
        path.push(v);
        this->setCount(this->getCount()-1);
	}
}

//Return the number of iteration
const int DFS::getCount() const
{
    return m_count;
}

//Set the number of iteration
void DFS::setCount(int count)
{
    m_count = count;
}
