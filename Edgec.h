#ifndef _EDGEC_
#define _EDGEC_

#include "Edge.h"
#include<iostream>
#include <stdlib.h>

using namespace std;




class Edgec:public Edge
{

private:

	double RoadLength;
	double RoadType;
	double AverageIncline;


public:

	    Edgec();
		Edgec(double length,double type,double average,Rvertex *eSource, Rvertex *eDest);
		virtual ~Edgec();
		double GetLength();
		double GetType();
		double GetAverage();
		void SetLength(double length);
		void SetType(double type);
		void SetAverage(double average);
        void UpdateWeight();
        virtual ostream& printEdge(ostream& out)const;


};

#endif



