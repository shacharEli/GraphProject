#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

#include <iostream>
#include <exception>

using namespace std;

class InvalidInput: public exception
{

public:
    virtual const char* what() const throw();
};

#endif // INVALIDINPUT_H
