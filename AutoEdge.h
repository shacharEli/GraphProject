#ifndef AUTOEDGE_H
#define AUTOEDGE_H
#pragma once
#include "Edge.h"

class AutoEdge: public Edge
{
private:
    char m_edgeChar;
public:
//Methods:
    AutoEdge();
    AutoEdge(char inChar);
    virtual ~AutoEdge();
    const char getChar() const;
    bool setChar(char c_other);
};

#endif // AUTOEDGE_H
