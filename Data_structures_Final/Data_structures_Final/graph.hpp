//
//  Graph.hpp
//  Data_structures_Final
//
//  Created by imac KK on 7/24/17.
//  Copyright © 2017 Kevin Kuwata. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
using namespace std;


struct infoBlock{
    string equation= "";
    //constants?
    infoBlock * next;
    
    
};




struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};



struct vertex{
    std::string topic;
    bool visited;
    int distance;
    infoBlock *equations;
    vertex *previous;
    std::vector<adjVertex> adj; //mine this is the HEAD of the linked list
};

class Graph
{
public:
    Graph();
    ~Graph();
    void addEdge(std::string v1, std::string v2, int weight); // (1)
    void addVertex(std::string topic, string _eqn1, string _eqn2); // (2)
    void printGraph2(); // (3)
    void printGraph();
     void Dijkstra(string sourceVertex, string destinationVertex); //(4)
    
    int BFSFind(string startVertex); //(5)
    void BFS_traversal(string _topic); //(6)
    void DFS_traversal(string _topic); //(7)
    void DFS(vertex * topic); //(8)
    
    //print all equations is my 7th thing
    void print_equations(); //(9)
    
    void DFS_iterrative(string _topic); //(10)

    
    int search_index(string _topic); // returns index
    vertex * search_Vertex(string _topic); //returns pointer to a vertex.


private:
    //vector<edge> edges;
    std::vector<vertex> vertices; //this is replacign my array
    
};

#endif /* Graph_hpp */


/*
 
        Possibly Useful:
 
 ==============================================================================
 int Graph::BFSFind(std::string startVertex)
 {
 bool foundStartVertex=false;
 for (int i=0;i<vertices.size(); i++){
 if (vertices[i].name == startVertex){
 return i;
 }
 }
 cout<<"starting vertex does not exist"<<endl;
 return -1;
 }}
 
 
 
 ==============================================================================
 
 
 ==============================================================================

 
 
 
 
 ==============================================================================

 
 */
