#include "Edge.h"
#include <iostream>
#include<string>
#include <stdlib.h>
using namespace std;

//Default constructor
Edge::Edge()
{
	m_wight = 0;
	m_source = NULL;
	m_destenation = NULL;
}

//Default destructor
Edge::~Edge()
{
    //cout << "I am in ~Edge" << endl;
}


//Constructor that recive pointers to source and destenation and wight
Edge::Edge(double wight, Rvertex *eSource, Rvertex *eDest)
{
	m_wight = wight;
	m_source = eSource;
	m_destenation = eDest;
}

//Copy constractor
Edge::Edge(const Edge &tEdge)
{
	m_wight = tEdge.m_wight;
	m_source = tEdge.m_source;
	m_destenation = tEdge.m_destenation;
}

//Return the edge wight
const double Edge::getWight()const
{
	return m_wight;
}

//Return the edge source
Rvertex* Edge::getSource()const
{
	return m_source;
}

//Return the edge destenation
Rvertex*  Edge::getDest() const
{

	return m_destenation;
}

//Set the vertex wight
bool Edge::setWight(double tWight)
{
	m_wight = tWight;
	return true;
}

//Set the vertex source
bool Edge::setSource(Rvertex* tSource)
{
	m_source = tSource;
	return true;
}

//Set the vertex detstenation
bool Edge::setDest(Rvertex* tDest)
{
	m_destenation = tDest;
	return true;
}

//Operator that prints the edge
ostream& Edge::printEdge(ostream& out)const
{
	out<<""<<flush;
	return out;
}

//Operator that prints the edge
ostream& operator<<(ostream& out, const Edge &edge)
{
    return edge.printEdge(out);
	//out << "wight = " << edge.m_wight << " , ";
	//out << "source = " << (*(edge.m_source)).getSymbol() << " , ";
	//out << "destenation = " << (*(edge.m_destenation)).getSymbol();
}



