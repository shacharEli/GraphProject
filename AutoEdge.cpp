#include "AutoEdge.h"
#include <iostream>
#include<string>

using namespace std;

//Default constructor
AutoEdge::AutoEdge():Edge(),m_edgeChar(' '){}

//Constructor that recieve a char as the path name
AutoEdge::AutoEdge(char inChar):Edge(),m_edgeChar(inChar){}

//Default destructor
AutoEdge::~AutoEdge(){}

//Returning the edge char
const char AutoEdge::getChar() const
{
    return m_edgeChar;
}

//Set the edge char
bool AutoEdge::setChar(char c_other)
{
    m_edgeChar = c_other;
    return true;
}
