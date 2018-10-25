#ifndef FILEDOESNOTEXIST_H
#define FILEDOESNOTEXIST_H

#include<iostream>
#include<string>
#include<exception>

using namespace std;

class FileDoesNotExist: public exception
{
private:
    string m_missingFile;
public:
    //FileDoesNotExist() throw();
    virtual ~FileDoesNotExist() throw(){};
    FileDoesNotExist(string fileName);
    virtual const char* what() const throw();
};

#endif // FILEDOESNOTEXIST_H
