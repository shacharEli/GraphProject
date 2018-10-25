#include "AutoVertex.h"
#include <iostream>
#include<string>

using namespace std;

//Default constructor
AutoVertex::AutoVertex():Vertex()
{
    m_state = "";
}

//Constructor that rcieve state as parameter
AutoVertex::AutoVertex(string state):Vertex(), m_state(state){}

//Default destructor
AutoVertex::~AutoVertex(){}

//Return the vertex state
const string AutoVertex::getState()
{
    return m_state;
}

//set the vertex m_state value
bool AutoVertex::setState(string state)
{
    m_state = state;
}

//
const int AutoVertex::getOrder()
{
    return m_order;
}

//
bool AutoVertex::setOrder(int order)
{
    m_order = order;
    return true;
}
