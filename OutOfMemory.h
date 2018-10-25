#ifndef OUTOFMEMORY_H
#define OUTOFMEMORY_H

#include <iostream>
#include <exception>

using namespace std;

class OutOfMemory: public exception
{

public:
    virtual const char* what() const throw();
};

#endif // OUTOFMEMORY_H
