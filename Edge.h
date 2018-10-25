#ifndef _EDGE_
#define _EDGE_

#include"Rvertex.h"
#include<iostream>
#include <stdlib.h>

using namespace std;

class Edge
{
private:

	Rvertex *m_source;
	Rvertex *m_destenation;
protected:

	double m_wight;

public:
//Methods:
	Edge();
	Edge(double wight, Rvertex *eSource, Rvertex *eDest);
	//copy constructor
	Edge(const Edge &tEdge);
	virtual ~Edge();
	const double getWight()const;
	Rvertex* getSource()const;
	Rvertex* getDest()const;
	bool setWight(double tWight);
	bool setSource(Rvertex* tSource);
	bool setDest(Rvertex* tDest);
	virtual ostream& printEdge(ostream& out)const;
//Friend functions:
	//friend operator to that recive ostrem object and Edge object and print te edge info
	friend ostream& operator<<(ostream& out, const Edge &edge);
};

#endif
