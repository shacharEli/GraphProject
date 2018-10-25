#ifndef _RVERTEX_
#define _RVERTEX_

#pragma once
#include<string>


using namespace std;

class Rvertex
{
protected:
	string m_symbol;
public:
//Methods:
	Rvertex();
	Rvertex(string symbole):m_symbol(symbole){};
	virtual ~Rvertex()=0;
	const string getSymbol()const;

};

#endif
