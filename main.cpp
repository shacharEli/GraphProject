#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
#include "IO.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <exception>

using namespace std;

int main(int argc, char* argv[])
{
	IO start;

    try
    {
        start.Begin(argc,argv);
    }
    catch(exception& errorMessage)
    {
        cout << errorMessage.what() << endl;
    }

    
	return 0;
}

