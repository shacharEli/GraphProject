#include "InvalidInput.h"

//Over writing the 'what' method of exception
const char* InvalidInput::what() const throw()
{
    return "Exception: Invalid Input";
}
