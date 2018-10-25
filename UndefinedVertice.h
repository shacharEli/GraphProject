#ifndef UNDEFINENDVERTICE_H
#define UNDEFINENDVERTICE_H
#include<iostream>
#include<string>
#include<exception>

using namespace std;

class UndefinedVertice: public exception
{
private:
    string m_symbol;
public:
    //FileDoesNotExist() throw();
    virtual ~UndefinedVertice() throw(){};
    UndefinedVertice(string symbol);
    virtual const char* what() const throw();
};

#endif // UNDEFINENDVERTICE_H
