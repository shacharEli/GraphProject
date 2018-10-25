#include"Rvertex.h"
#include "Vertex.h"
#include<string>
#include<vector>
#include <iostream>

using namespace std;

//Default constructor
Vertex::Vertex(): Rvertex()
{
    m_visited = false;
    m_distance = -1;
    m_vecEdge.clear();
};

//Constructor that recive Vertex name and vector of edges
Vertex::Vertex(const string symbol, const vector<Edge *> &vecEdge):Rvertex(symbol)
{
	copy(vecEdge.begin(),vecEdge.end(),back_inserter(m_vecEdge));
    m_visited = false;
    m_distance = -1;
    previous="";
}

//Default destructor
Vertex::~Vertex()
{
    //cout << "I am in ~Vertex start" << endl;
    vector<Edge *>::iterator it;
    if (m_vecEdge.size()>0)
    {
        for(it =m_vecEdge.begin(); it != m_vecEdge.end(); it++)
        {
            delete *it;
        }
    }
    //cout << "I am in ~Vertex end" << endl;
}

//copy constructor
Vertex::Vertex(const Vertex &tVertex):Rvertex(tVertex.m_symbol)
{
	copy(tVertex.m_vecEdge.begin(),tVertex.m_vecEdge.end(),back_inserter(m_vecEdge));
}

//Set the vetrex name
bool Vertex::SetSymbol(string symbol)
{
	m_symbol = symbol;
	return true;
}

//Return the egdes vector
const vector<Edge *> Vertex::getEdges() const
{
	return m_vecEdge;
}

//Set the vertx edge vector
bool Vertex::setEdges(vector<Edge *> edgeVec)
{
	m_vecEdge.erase(m_vecEdge.begin(),m_vecEdge.end());
	copy(edgeVec.begin(),edgeVec.end(),back_inserter(m_vecEdge));
	return true;
}


//Adding a new edge to the vector vertex
bool Vertex::addEdge(Edge *tEdge)
{
	m_vecEdge.push_back(tEdge);
	return true;
}

//print a vertex
void Vertex::printVertex()
{
	//Print the vertex symbole
		cout << m_symbol << flush;
}

//Operator that prints the vertex
ostream& operator<<(ostream& out, Vertex &vertex)
{
	int i = 1;

	//Print the vertex symbole
	//out << "Symbole: " << vertex.m_symbol << endl;
	out << vertex.m_symbol << endl;
	//Print the vertex edges
	vector<Edge *>::iterator it;
	for(it = vertex.m_vecEdge.begin(); it != vertex.m_vecEdge.end(); it++)
	{
		out << "Edge" << i << ": " << *(*it) << endl;
		i++;
	}
	return out;
}


// set the visited field

void Vertex::SetVisited(bool visit)
{
	m_visited=visit;
}

// ser the distance filed

void Vertex::SetDistance(double distance)
{
 	m_distance=distance;
}


// return the m_visited field
bool Vertex::GetVisited()
{
	return m_visited;
}

// return the distance field

double Vertex::GetDistance()
{
	return m_distance;
}

// set the symbol of previuos edge in the searches

void Vertex::SetPrevious(string symbol)
{
	previous=symbol;
}

// return the previous field
string Vertex::GetPrevious()
{
	return previous;
}






