#include "Automate.h"
#include "AutoEdge.h"
#include "AutoVertex.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

//Default constructor
Automate::Automate(){}

//Default destructor
Automate::~Automate(){}

//Automate algorithm
void Automate::automateAlgo(Graph tGraph, char* stringFile)
{
    ifstream myfile;
    string errorMessage, line;
    char nextChar;
    map<string,Vertex *>::const_iterator itMap;
    vector<Edge *>::const_iterator itVec;
    vector<Edge *> tEdgeVec;
    Vertex *v, *start;
    bool Flag;
    int index, pos, pos2;

    //Check if string file exist
    myfile.open(stringFile);
    if(myfile.fail())
	{
        myfile.close();
        errorMessage = "File " + (string)stringFile + " Does Not Exist";
        throw errorMessage;
        return;
    }
    start = NULL;
    Flag = false;
    //Searching for the start vertex
    for(itMap = tGraph.GetMap()->begin(); itMap != tGraph.GetMap()->end(); itMap++)
    {
        start = itMap->second;
        if(dynamic_cast<AutoVertex *>(start)->getOrder() == 1)
        {
           Flag = true;
           break;
        }
    }
    //The start vertex was found
    if(Flag)
    {
        //cout << stringFile << endl;
        //Main loop that is going over the strings file
        if (myfile.is_open())
        {
            //Main loop that go over the file lines
            while(getline(myfile,line))
            {
                v = start;
                //Going over the line
                for (index = 0; index < line.size() && line[index] != '\r' && line[index] != '\n'; index++)
                {
                    nextChar = line[index];
                    //Searching for the right edge in the vertex vector
                    tEdgeVec = v->getEdges();
                    for(itVec = (tEdgeVec).begin(); itVec != (tEdgeVec).end(); itVec++)
                    {
                        if((dynamic_cast<AutoEdge *>(*itVec))->getChar() == nextChar)
                        {
                            //cout << nextChar;
                            break;
                        }
                    }
                    //Check if relevant edge exist
                    if(itVec != (tEdgeVec).end())
                    {
                        v = dynamic_cast<Vertex *>((*itVec)->getDest());
                    }
                    else
                    {
                        break;
                    }
                    //cout << line[index] << endl;
                }
                //cout << "index = " << index << " line size = " << line.size() << "vertex state = " << (dynamic_cast<AutoVertex *>(v))->getState() << endl;
                //cout << "line: " << line << endl;
                //cout << "final vertex: " << v->getSymbol() << " , state: "<< (dynamic_cast<AutoVertex *>(v))->getState() << " , number of iteration left: " << (line.size() - index) << " , resualt: ";
				for(pos = 0;pos < line.size(); pos++)
                {
                    if(line[pos] == '\n')
                    {
                        break;
                    }
                }
                for(pos2 = 0;pos2 < line.size(); pos2++)
                {
                    if(line[pos2] == '\r')
                    {
                        break;
                    }
                }
                if(pos == pos2)
                {
                    if(index == (line.size()) && (dynamic_cast<AutoVertex *>(v))->getState() == "$")
                    {
                        cout << "TRUE" << endl;
                    }
                    else
                    {
                        cout << "FALSE" << endl;
                    }
                }
                else
                {
                    if(index == (line.size()-1) && (dynamic_cast<AutoVertex *>(v))->getState() == "$")
                    {
                        cout << "TRUE" << endl;
                    }
                    else
                    {
                        cout << "FALSE" << endl;
                    }
                }
            }
        }
    }
    else
    {
        myfile.close();
        errorMessage = "Start vertex was not found";
        throw errorMessage;
    }
    myfile.close();
}
