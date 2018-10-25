#include "Edge.h"
#include "Edgec.h"
#include <iostream>
#include<string>
#include <stdlib.h>
using namespace std;


        // defult constractor
		Edgec::Edgec():Edge()
		{
			RoadLength=0;
			RoadType=0;
			AverageIncline=0;

		}
		//consractor with parameters
		Edgec::Edgec(double length,double type,double average,Rvertex *eSource, Rvertex *eDest):Edge(0,eSource,eDest)
		{
		    //cout << "Start Edgec()" << endl;
			RoadLength=length;
		    RoadType=type;
		    AverageIncline=average;
            UpdateWeight();
		   // cout << "Weight = " << m_wight << endl;
		  //  cout << "End Edgec()" << endl;
		}
		//defualt constractor;
		Edgec::~Edgec()
		{
		   
        }


		//retuarn the road length
		double Edgec::GetLength()
		{
			return RoadLength;
		}


		// return the road type
		double Edgec::GetType()
		{
			return RoadType;
		}

		// return the average
		double Edgec::GetAverage()
		{
			return AverageIncline;
		}

		// update the length of the road
		void Edgec::SetLength(double length)
		{
			RoadLength=length;
		}

		// update the road type
		void Edgec::SetType(double type)
		{
			RoadType=type;
		}

		// update the average
		void Edgec::SetAverage(double average)
		{
			AverageIncline=average;

		}

		ostream& Edgec::printEdge(ostream& out)const
		{
			out << RoadLength << "-" << RoadType << "," ;
			return out;

		}

		 void Edgec::UpdateWeight()
		 {
		      m_wight=RoadLength+(RoadLength/RoadType)+(AverageIncline*RoadLength);
		 }

