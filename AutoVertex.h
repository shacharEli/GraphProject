#ifndef AUTOVERTEX_H
#define AUTOVERTEX_H

#include "Vertex.h"
#include<string>
#include<vector>
#include <iostream>

class AutoVertex:public Vertex
{
private:
    string m_state;
    int m_order;
public:
//Methods:
    AutoVertex();
    AutoVertex(string state);
    virtual ~AutoVertex();
    const string getState();
    bool setState(string state);
    const int getOrder();
    bool setOrder(int order);
};

#endif // AUTOVERTEX_H
