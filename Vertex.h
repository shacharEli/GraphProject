#ifndef _VERTEX_
#define _VERTEX_

#pragma once
#include"Edge.h"
#include "Edgec.h"
#include"Rvertex.h"
#include<string>
#include<vector>
#include <iostream>

using namespace std;

class Vertex: public Rvertex
{
private:
	vector<Edge *> m_vecEdge;
	bool m_visited;
	double m_distance;
	string previous;
public:
//Methods:
	Vertex();
	Vertex(const string symbol, const vector<Edge *> &vecEdge);
	//copy constructor
	Vertex(const Vertex &tVertex);
	virtual ~Vertex();
	bool SetSymbol(string symbol);
	const vector<Edge *> getEdges() const;
	bool setEdges(vector<Edge *> edgeVec);
	bool addEdge(Edge* tEdge);
	void SetVisited(bool visit);
	void SetDistance(double distance);
	bool GetVisited();
	double GetDistance();
	void SetPrevious(string symbol);
	string GetPrevious();
	void printVertex();

//Friend functions:
	//friend operator to that recive ostrem object and vertex object and print the vertex info
	friend ostream& operator<<(ostream& out, Vertex &vertex);
};

#endif
