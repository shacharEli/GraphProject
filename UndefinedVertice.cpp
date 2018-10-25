#include "UndefinedVertice.h"
#include<string>

using namespace std;

UndefinedVertice::UndefinedVertice(string symbol):exception(), m_symbol("Exception: Vertice " + symbol +" undefined" ){}

//Over writing the 'what' method of exception
const char* UndefinedVertice::what() const throw()
{
    return m_symbol.c_str();;
}
