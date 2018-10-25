#include "OutOfMemory.h"

//Over writing the 'what' method of exception
const char* OutOfMemory::what() const throw()
{
    return "Exception: Out of Memory";
}
