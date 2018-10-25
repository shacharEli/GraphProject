#ifndef _IO_
#define _IO_

#include"Vertex.h"
#include"Edge.h"
#include<string>
#include<vector>
#include<map>
#include <fstream>
#include<iostream>
#include "Graph.h"
#include "Search.h"
#include "DFS.h"
#include"AutoVertex.h"
#include"AutoEdge.h"
#include "UndefinedVertice.h"

using namespace std;

class IO
{
private:
	map< string,Vertex * > m_mapVertex;

public:
    IO();
    virtual ~IO();
	void Begin(int arguNum,char* arguArray[]);
	void GraphIO(char* filename, double memoryLimitation);
	void CityGraphIO(char *filename, double memoryLimitation);
	void GraphAutoIO(char* filename,double memoryLimitation);
	void DeleteSoFar();
};

#endif
