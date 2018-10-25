#include"Vertex.h"
#include"Edge.h"
#include"Edgec.h"
#include"Graph.h"
#include"IO.h"
#include <string.h>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "Search.h"
#include "DFS.h"
#include "BFS.h"
#include "Automate.h"
#include "AutoVertex.h"
#include "AutoEdge.h"
#include "OutOfMemory.h"
#include "FileDoesNotExist.h"
#include <limits>
#include "UndefinedVertice.h"
#include "InvalidInput.h"
#include <ctype.h>

using namespace std;

//Default constructor
IO::IO(){}


//distructor
IO::~IO()
{
   // cout << "I am in ~IO start" << endl;
    map<string,Vertex *>::iterator it;

    for(it = m_mapVertex.begin(); it != m_mapVertex.end(); it++)
    {
        delete (it->second);
    }
   // cout << "I am in ~IO end" << endl;
}

//this fuction get a kind and a path and then: reaf the file,build the graph and acrivate the right search
void IO::Begin(int arguNum,char* arguArray[])
{
    string graphType, algoType, startVertex, endVertex, errorMessage;
    char *filename, *stringFile;
    double memoryLimitation;
    ifstream myfile, myfile1;
    filename  = arguArray[1];
    graphType = (string)arguArray[2];
    algoType = (string)arguArray[3];
    bool memory=false;
    string temp;
    memoryLimitation=numeric_limits<double>::infinity();

    //Check if file exist
    myfile.open(arguArray[1]);
    if(myfile.fail())
    {
        myfile.close();
        throw FileDoesNotExist(filename);
    }

    // Check if the graphType is ligal
    if (graphType!="-r" && graphType!="-c" && graphType!="-a")
    {
       // cout<<"invalid graph type"<<endl;
        throw InvalidInput();

    }

   // cout<<arguNum<<" "<<arguArray[5]<< endl;
    // check a case of: -m in the input line and no parameters after that
    if ( algoType=="-bfs" || algoType=="-dijkstra")
	{
	     if ( arguNum>6)
                {
                    if(strcmp(arguArray[6],"-m")!=0)
			{
				throw InvalidInput();
			}
		    if(arguNum==7 && strcmp(arguArray[6],"-m")==0)
			{
				 throw InvalidInput();
			}
	             memory=true;
		     temp=arguArray[7];
		}
	}
      //check if there is a memory limitation and is not valid
     if ( algoType == "-dfs")
         {

	     if ( arguNum>5)
                {
			if (strcmp(arguArray[5],"-m")!=0)
			{

				throw InvalidInput();
			}
		     if(arguNum==6 && strcmp(arguArray[5],"-m")==0)
			{

				 throw InvalidInput();
			}
	             memory=true;
		      temp=arguArray[6];
		}
	}

	//check if there is a memory limitation and is not valid
	if ( graphType == "-a")
	{
		if ( arguNum>4)
                {

                    if(strcmp(arguArray[4],"-m")!=0)
			{
				throw InvalidInput();
			}
		     if(arguNum==5 && strcmp(arguArray[4],"-m")==0)
			{
				 throw InvalidInput();
			}
	             memory=true;
		     temp=arguArray[5];
		}
       }

	if (memory==true)
        {

		int count=0;

	     //checking that the memory limitation is number
	     while(count<temp.size())
		{
		   if(!isdigit(temp[count]))
		     {
			//cout<<"memory limitetio is not number"<<endl;
			throw InvalidInput();
		     }
		        count++;
		}
        }

    // checking that the search algoritems are valid
    if (graphType=="-r" || graphType=="-c")
	{
		if(algoType!="-bfs" && algoType!="-dijkstra" && algoType!="-dfs")
		{
			//cout<<"invalid search"<<endl;
			throw InvalidInput();
		}
	}
	// check the combination between auotomat and searches
    if (graphType=="-a")
	{
		if(algoType=="-bfs" || algoType=="-dijkstra" || algoType=="-dfs")
		{
			//cout<<"invalid algoType"<<endl;
			throw InvalidInput();
		}
	}
    //Initial bfs/dfs parameters
    if(graphType == "-r" || graphType == "-c")
    {
        if((algoType == "-bfs" || algoType == "-dijkstra") && arguNum >= 5)
        {
            startVertex = (string)arguArray[4];
	        endVertex = (string)arguArray[5];
        }
        else
        {
            // check if there are enough paramters for dfs/dijkstra
            if((algoType == "-bfs" || algoType == "-dijkstra") && (arguNum < 5||arguNum > 7))
            {
                //cout<<"not enoghu parameters for search"<<endl;
                throw InvalidInput();
            }
        }
        if((algoType == "-dfs") && arguNum >= 4)
        {
            startVertex = (string)arguArray[4];
        }
        // checking the amount of parameters in case of dfs is valid
        if((algoType == "-dfs")&& (arguNum < 4 || arguNum > 8))
        {

            throw InvalidInput();
        }

        if(arguNum >= 7 && (string)arguArray[6] == "-m")
        {
            memoryLimitation = atof(arguArray[7]);
        }
        else
        {// checking case of: 7 parameters in the function call but no "-m"
            if(arguNum >= 7 && (string)arguArray[6] != "-m")
            {
                          throw InvalidInput();
            }
        }
    }
    if(graphType == "-a" && arguNum >= 4)
	{
	    stringFile = arguArray[3];
	    if (arguNum >= 5)
	    {
	          if((string)arguArray[4] == "-m" && arguNum >= 4)
	                memoryLimitation=atof(arguArray[5]);
	    }
        else
	    {
              // checking if the amount of parameters is valid
              if(arguNum<3 || arguNum>6 )
              {
                throw InvalidInput();
              }
         }
        //Check if file exist
        myfile1.open(arguArray[3]);
        if(myfile1.fail())
        {
            myfile1.close();
            throw FileDoesNotExist(stringFile);
        }
    }
    //In case of regular graph or city graph
    if (graphType == "-r" || graphType == "-c")
    {
        if (graphType == "-r" )
        {
            this->GraphIO(filename,memoryLimitation);
        }
        if (graphType == "-c")
        {
            this->CityGraphIO(filename,memoryLimitation);
        }
        Graph graph(&m_mapVertex);
        //graph.printGraph();
        if(algoType == "-bfs" || algoType == "-dijkstra")
        {
            BFS algo;
            //cout << "Going to call bfs algo" << endl;
            algo.bfsAlgo(graph,startVertex,endVertex,algoType);//dijkstra
            //cout << "After calling bfs algo" << endl;
        }
        if(algoType == "-dfs")
        {
            DFS algo;
            algo.dfsAlgo(&graph,startVertex);
        }
        //graph.printGraph();
    }
    //In case of automation graph
    if(graphType == "-a")
    {
        this->GraphAutoIO(filename,memoryLimitation);
        Graph graph(&m_mapVertex);
        Automate algo;
        algo.automateAlgo(graph,stringFile);
        //graph.printGraph();
    }
}

//Read the file given and creating a graph based on it
void IO::GraphIO(char* filename, double memoryLimitation)
{
    //cout << "I am here: IO::GraphIO(char* filename)" << endl;
	string line, source, dest, swight;
	double wight, allocMemory;
	ifstream myfile;
	Vertex *v;
	Edge *e;
	size_t pos,pos2;
	string symbol, errorMessage;
	map<string,Vertex *>::iterator it;

	myfile.open(filename);

	if (myfile.is_open())
	{
	    allocMemory = 0;
		//Main loop that go over the file lines
		while(getline(myfile,line))
		{
			if(line.size() > 0)
			{
				// chacking case of the first letter is a neigher E or E
				if (line[0] != 'V' && line[0] != 'E' )
				{
					//cout<< "invaligd sign in the first "<<endl;
					throw InvalidInput();
				}
				// chacking case of there are no : after the first letter
				if (line[1] != ':')
				{
					//cout<< "no :"<<endl;
					throw InvalidInput();
				}
				//case of: there is nothing after :
				if (line[2]=='\r' || line[2]=='\n' || line.size()<3)
				{
						cout<<"not enough parameters in vertex/edge"<<endl;
						throw InvalidInput();
				}
				//Check if it is a vertex
				if(line[0] == 'V')
				{
				    //Check delimiter end of line value (unix - \n , windows - \r\n)
					for(pos = 0;pos < line.size(); pos++)
					{
					    if(line[pos] == '\n')
					    {
					        break;
					    }
					}
					for(pos2 = 0;pos2 < line.size(); pos2++)
					{
					    if(line[pos2] == '\r')
					    {
					        break;
					    }
					}
					//checking a case of: V:
					//Creating the verex and adding it to the map of vertex
					v = new Vertex();
					//if delimiterof end of line = \n
					if(pos == pos2)
					{
					    symbol = line.substr(2,line.size()-2);
					}
					else
					{
					    symbol = line.substr(2,line.size()-3);
					}
					v->SetSymbol(symbol);
					m_mapVertex[symbol] = v;
					allocMemory = allocMemory + 4 + (v->getSymbol()).size();
					if(allocMemory > memoryLimitation)
					{
					    throw OutOfMemory();
					}
					v = NULL;
				}
				else
				{
					//Check if it is an edge
					if(line[0] == 'E')
					{
						//cout<< line<<endl;
						// checking a case of nor enough parameters
						int count=0;
						string temp=line;
						//counting how many "," there are in line;
						while(0<temp.size())
						{
							pos= temp.find(",");
							if(pos != string::npos)
							{
								if(temp.size()>1)
								temp = temp.substr(pos+1);
								count++;
							}
							else
							{

								break;
							}
							if (temp=="")
								break;
						}
						if (count!=2)
						{
							throw InvalidInput();
						}
						//find the source
						pos  = line.find(",");
						if(pos != string::npos)
						{
							source = line.substr(2,pos - 2);
							//find the destination
							pos2  = line.find(",",pos + 1);
							if(pos2 != string::npos)
							{
								dest = line.substr(pos +1,pos2 - pos - 1);
								//find the wight
								swight = line.substr(pos2+1);
								//checking that swight is a number
                                int count=0;
                                while(count<swight.size()-1)
                                {
                                	if (!isdigit(swight[count])&& swight[count]!='.')
                                	{
                                		cout<<swight[count]<<endl;
                                		throw InvalidInput();
                                	}
                                	count++;
                                }
								wight = atof(swight.c_str());
								//Creating the edge and adding it to the
								//edges vector of the source vertex
								e = new Edge();
								//Check if source vertex exist in map
								it = m_mapVertex.find(source);//If not exist need to throw an exception
								if (it != m_mapVertex.end())
								{
									(*e).setSource(it->second);
									//Check if destination vertex exist in map
									it = m_mapVertex.find(dest); //If not exist need to throw an exception
									if (it != m_mapVertex.end())
									{
										(*e).setDest(it->second);
										//Updating the wait
										(*e).setWight(wight);
										(*(dynamic_cast<Vertex*>((*e).getSource()))).addEdge(e);
										allocMemory = allocMemory + 2;
										if(allocMemory > memoryLimitation)
                                        {
                                            //errorMessage = "Exception: Out of Memory";
                                            //throw errorMessage;
                                           // DeleteSoFar();
                                            throw OutOfMemory();
                                        }
										//cout << allocMemory << endl;
										e = NULL;
									}
									else
									{
                                        delete e;
                                        throw UndefinedVertice(dest);
									}
								}
                                else
                                {
                                    delete e;
                                    throw UndefinedVertice(source);
                                }
							}

						}
					}
				}
				//cout << "Map size: " << m_mapVertex.size() << endl;
			}
			else
			{
				throw InvalidInput();
			}
		}
		myfile.close();
  	}
			else
			{
            cout << "Unable to open file" << endl;
	        }
	//cout << m_mapVertex.size() << endl;
}


void IO::CityGraphIO(char *filename, double memoryLimitation)
{

    string line, source, dest, length,type,average;
	double wight,memory;
	ifstream myfile;
	Vertex *v;
    Edgec *e;
    size_t pos,pos2,pos3,pos4;
    string symbol;
    double nlength,ntype,naverage;
    map<string,Vertex *>::iterator it;
    memory=0;
    int count;
    myfile.open(filename);

    if (myfile.is_open())
    {
        //Main loop that go over the file lines
        while(getline(myfile,line))
        {
            if(line.size() > 0)
            {
            	// chacking case of the first letter is a neigher R or C
            	if (line[0] != 'C' && line[0] != 'R' )
            	{
            		//cout<< "invaligd sign in the first "<<endl;
            		throw InvalidInput();
            	}
            	// chacking case of there are no : after the first letter
            	if (line[1] != ':')
            	{
            		//cout<< "no :"<<endl;
            		throw InvalidInput();
            	}
				//case of: there is nothing after :
				if (line[2]=='\r' || line[2]=='\n' || line.size()<3)
				{
						cout<<"not enough parameters in vertex/Edge"<<endl;
						throw InvalidInput();
				}
                //Check if it is a vertex
                if(line[0] == 'C')
                {
				    //Check delimiter end of line value (unix - \n , windows - \r\n)
					for(pos = 0;pos < line.size(); pos++)
					{
					    if(line[pos] == '\n')
					    {
					        break;
					    }
					}
					for(pos2 = 0;pos2 < line.size(); pos2++)
					{
					    if(line[pos2] == '\r')
					    {
					        break;
					    }
					}
                    //Creating the verex and adding it to the map of vertex
                    v = new Vertex();
                    if(pos == pos2)
					{
					    symbol = line.substr(2,line.size()-2);
					}
					else
					{
					    symbol = line.substr(2,line.size()-3);
					}
                    v->SetSymbol(symbol);
                    m_mapVertex[symbol] = v;
                    memory=memory + 4 + (v->getSymbol()).size();
                   if (memory > memoryLimitation)
                   {
                       //DeleteSoFar();
                       throw OutOfMemory();
                   }
                    v = NULL;
                }
                else
                {
                    //Check if it is an edge
                    if(line[0] == 'R')
                    {
                    	// checking a case of nor enough parameters
                    	count=0;
                    	string temp=line;
                    	//counting how many "," there are in line;
                    	while(0<temp.size())
                    	{
                    	// cout<< temp<<endl;
                    	 pos= temp.find(",");
                    	 if(pos != string::npos)
                    	 {
                    		if(temp.size()>1)
                    		temp = temp.substr(pos+1);
                    		else
                    		temp = temp.substr(pos);
                    		count++;
                    	 }
                    	 else
                    	 {

                    		break;
                    	 }
                    	 if (temp=="")
                    		break;
                    	 }
                    	 if (count!=4)
                    	  {
                    	    // cout<<"not enough parameters   "<<count<<endl;
                    	     throw InvalidInput();
                    	  }

                        //find the source
                        pos  = line.find(",");
                        if(pos != string::npos)
                        {

                            source = line.substr(2,pos - 2);
                            //find the destination
                            pos2  = line.find(",",pos + 1);
                            if(pos2 != string::npos)
                            {
                                dest = line.substr(pos +1,pos2 - pos - 1);
                            }
                            pos3 = line.find(",",pos2+1);
                            pos4 = line.find(",",pos3+1);
                            if ( pos4 != string::npos)
                            {
                                //find the road length
                                length=line.substr(pos2+1,pos3-pos2-1);
                                //check if the length is a number
                                count=0;
                                while(count<length.size()-1)
									{
										if (!isdigit(length[count]) && length[count]!='.')
											{

												//cout<<length[count]<<endl;
												throw InvalidInput();
											}
										count++;
									}
                                nlength= atof(length.c_str());
                                //find the road type
                                type= line.substr(pos3+1, pos4-pos3-1);
                                //check if the type is a number
                                if (type.size()>1 || !isdigit(type[0]))
                                {
                                	//cout<<"invalid road type"<<endl;
                                	throw InvalidInput();
                                }
                                ntype=atof(type.c_str());
                                // check if the type is a valid number
                                if (ntype!=1.0 && ntype!=2.0 && ntype!=3.0)
                                {
                                	cout<<type<<endl;
                                   	throw InvalidInput();
                                }
                                //find the average type
                                average= line.substr(pos4+1);
                                //check if the average is a number
                                count=0;
                                //cout<<"finish city"<<endl;
                                while(count<average.size()-1)
                                	{
                                		if (!isdigit(average[count])&& average[count]!= '.' )
                                			{
                                                //cout<<"finish city"<<endl;
                                				//cout<<average[count]<<endl;
                                				throw InvalidInput();
                                			}
                                		count++;
                                	}
                                naverage= atof(average.c_str());
                            }
                            //Creating the edge and adding it to the
                            //edges vector of the source vertex
                            e = new Edgec();
                            //Check if source vertex exist in map
                            it = m_mapVertex.find(source);//If not exist need to throw an exception
                            if (it != m_mapVertex.end())
                            {
                                (*e).setSource(it->second);
                                //Check if destination vertex exist in map
                                it = m_mapVertex.find(dest); //If not exist need to throw an exception
                                if (it != m_mapVertex.end())
                                {
                                    (*e).setDest(it->second);
                                    //Updating the wait
                                    (*e).SetLength(nlength);
                                    (*e).SetType(ntype);
                                    (*e).SetAverage(naverage);
                                    (*e).UpdateWeight();
                                    (*(dynamic_cast<Vertex*>((*e).getSource()))).addEdge(e);
                                    memory=memory+6;
                                    if (memory> memoryLimitation)
										{
                                            throw OutOfMemory();
										}
                                    if (memory > memoryLimitation)
                                    {
                                        // DeleteSoFar();
                                         throw OutOfMemory();
                                    }
                                    e = NULL;
                                }//if
                                else
                                {
                                    delete e;
                                    throw UndefinedVertice(dest);
                                }//else
                            }//if
                            else
                            {
                                delete e;
                                throw UndefinedVertice(source);
                            }//else
                        }//if
                    }//if
                }//else
            }//if
			//cout << "Map size: " << m_mapVertex.size() << endl;
        }//while
    }//if
    else
    {
        cout << "Unable to open file" << endl;
    }
    myfile.close();

}//CityGraphIO


////Read the file given and creating an automat graph based on it
void IO::GraphAutoIO(char* filename,double memoryLimitation)
{
    string line, source, dest, symbol, state;
    double autoMemory;
    char edgeChar;
    int count = 1;
    ifstream myfile;
    AutoVertex *v;
    AutoEdge *e;
	size_t pos,pos2;
	map<string,Vertex *>::iterator it;
    autoMemory=0;
	myfile.open(filename);
	if (myfile.is_open())
	{
		//Main loop that go over the file lines
		while(getline(myfile,line))
		{
			if(line.size() > 0)
			{
				// chacking case of the first letter is a neigher R or C
				if (line[0] != 'S' && line[0] != 'T' )
				{
				     cout<< "invaligd sign in the first "<<endl;
				     throw InvalidInput();
				}
				// chacking case of there are no : after the first letter
				if (line[1] != ':')
				{
				   cout<< "no :"<<endl;
				   throw InvalidInput();
                }
				if (line[2]=='\r' || line[2]=='\n' || line.size()<3)
				{
						cout<<"not enough parameters in vertex/edge"<<endl;
						throw InvalidInput();
				}
				//Check if it is a vertex
				if(line[0] == 'S')
				{
				    //Find the vertex name
					pos  = line.find(",");
					if(pos != string::npos)
					{
					    symbol = line.substr(2,pos - 2);
					    //cout << "symbol = " << symbol << ", symbol size = " << symbol.size() << endl;
                        //Find the vertex state
                        if(line[pos+1] != '\r' && line[pos+1] != '\n')
                        {
                            state = line.substr(pos +1,1);
                            v = new AutoVertex();
                            v->SetSymbol(symbol);
                            v->setState(state);
                            v->setOrder(count);
                            count++;
                            m_mapVertex[symbol] = v;
                            autoMemory=autoMemory+4+(v->getSymbol()).size();
                            if (autoMemory > memoryLimitation)
                            {
                                throw OutOfMemory();
                            }
                            v = NULL;
                        }
					}
				}
				if(line[0] == 'T')
				{
					// checking a case of nor enough parameters
					count=0;
					string temp=line;
					//counting how many "," there are in line;
					while(0<temp.size())
					{
					   //cout<< temp<<endl;
					   pos= temp.find(",");
					   if(pos != string::npos)
					   {
					       if(temp.size()>1)
					       temp = temp.substr(pos+1);
					       else
					       temp = temp.substr(pos);
					       count++;
					     }
					       else
					     {

					        break;
					     }
					      if (temp=="")
					         break;
					    }
					 if (count!=2)
					  {
					    cout<<"not enough parameters   "<<count<<endl;
                        throw InvalidInput();
					  }
						//find the source
						pos  = line.find(",");
						if(pos != string::npos)
						{
						    source = line.substr(2,pos - 2);
						    //cout << "source = " << source << ", source size = " << source.size() << endl;
							pos2  = line.find(",",pos + 1);
							if(pos2 != string::npos)
							{
							    dest = line.substr(pos +1,pos2 - pos - 1);
							    //cout << "dest = " << dest << ", dest size = " << dest.size() << endl;
							    edgeChar = (line.substr(pos2+1,1))[0];
							    //Check if source vertex exist in map
							    it = m_mapVertex.find(source);//If not exist need to throw an exception
								if (it != m_mapVertex.end())
								{
                                    //Creating the edge and adding it to the
                                    //edges vector of the source vertex
                                    e = new AutoEdge();
									(*e).setSource(it->second);
									//Check if destination vertex exist in map
									it = m_mapVertex.find(dest); //If not exist need to throw an exception
									if (it != m_mapVertex.end())
									{
										(*e).setDest(it->second);
										//Updating the edge char
										(*e).setChar(edgeChar);
										(*((Vertex *)((*e).getSource()))).addEdge(e);
										autoMemory=autoMemory+2;
										if (autoMemory> memoryLimitation)
										{
                                            //DeleteSoFar();
                                            throw OutOfMemory();
										}
										e = NULL;
									}
									else
									{
									    //cout<<"in dest: " << source << endl;
                                        //delete e;
                                        throw UndefinedVertice(dest);
									}
								}
								else
                                {
									    //cout<<"source = " << source << " , source size = "<< source.size() << endl;
                                        //delete e;
                                        throw UndefinedVertice(source);
                                }
							}
						}
				}
			}
		}
	}
	else
	{
		throw InvalidInput();
	}
}

/*

void IO::DeleteSoFar()
{
    map<string,Vertex *>::iterator d_map;

     for(d_map=m_mapVertex.begin();d_map=m_mapVertex.end();d_map++)
     {
            if (d_map->second!=NULL)
            {
                Vertex *temp=d_map->second;
                delete  (temp);
            }
     }

}

*/







