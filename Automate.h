#ifndef AUTOMATE_H
#define AUTOMATE_H

#include"Graph.h"
#include"Search.h"
#include <vector>
#include <map>
#include <stack>
#include<iostream>
#include <stdlib.h>


class Automate:public Search
{

public:
    Automate();
    virtual ~Automate();
    void automateAlgo(Graph tGraph, char* stringFile);
};

#endif // AUTOMATE_H
