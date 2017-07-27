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

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string topic;
    bool visited;
    int distance;
//    infoBlock *equations;
    vertex *previous;
    std::vector<adjVertex> adj; //mine this is the HEAD of the linked list
};

class Graph
{
public:
    Graph();
    ~Graph();
    void addEdge(std::string v1, std::string v2, int weight);
    void addVertex(std::string topic);
    void printGraph2();
    void printGraph();
    void Dijkstra(string sourceVertex, string destinationVertex);
    int BFSFind(string startVertex);
protected:
private:
    //vector<edge> edges;
    std::vector<vertex> vertices; //this is replacign my array
    
};


//class Graph{
//public:
//    
//    
//private:
//    
//   
//    
//};

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
