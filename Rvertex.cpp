#include "Rvertex.h"

//Default constructor
Rvertex::Rvertex()
{
	m_symbol = "";
};

//Default destructor
Rvertex::~Rvertex()
{
    
}

//Returning the symbol name
const string Rvertex::getSymbol()const
{
	return m_symbol;
}
