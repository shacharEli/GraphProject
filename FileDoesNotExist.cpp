#include "FileDoesNotExist.h"
#include<string>

using namespace std;

FileDoesNotExist::FileDoesNotExist(string fileName):exception(), m_missingFile("File " + fileName + " Does Not Exist"){}

//Over writing the 'what' method of exception
const char* FileDoesNotExist::what() const throw()
{
    return m_missingFile.c_str();;
}



