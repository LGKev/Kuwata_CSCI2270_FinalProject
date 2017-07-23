//
//  graphs_physics.hpp
//  Data_structures_Final
//
//  Created by imac KK on 7/22/17.
//  Copyright © 2017 Kevin Kuwata. All rights reserved.
//

#ifndef graphs_physics_hpp
#define graphs_physics_hpp

#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

struct vertex;

// link list of adjacent nodes/vertex
// a collection of nodes that are adjacenet make up an adjacent list.
struct adjVertex{
    
    string topic_name;
    bool visted = false;
    int weight = 1;
    adjVertex * next;//down the link list column
    adjVertex * parent; //link up, for undriectional
    
};


struct adjList{
    adjVertex * head; //node below the given vertex. (think of a column)
};




//graphs class
class graphs_physics{

public:
        //print, add, delete, shortest path, count number of nodes, longest path?
    graphs_physics();
    ~graphs_physics();
    void addVertex(string _topic);
    void addEdge(string t1, string t2, int _weight);
    // hardest topic? maybe number of conenctions?
    void displayEdges();
    void printGraph();
    int loadFile(char * fileName);

    
private:
    //attributes of graph class:
    adjList * graph_array; //array of linked lists, vertices.
    int graph_array_size; // determined by number of vertices
    int current_array_index = 0; //used to keep track of current size from file read.
    
    
};








/*
 
 my issue was i was trying to make an array of vertices. then have the vertices->next point to the next element in a column
 
 this is not possible because then you get a adjList pointer and a vertex pointer. 
 
 solution was to make an array of linked lists. this way each element in the array is the head of a new node.
 
 then you have access to next and so you can add the new link (if found) to next and say currentNode->next = newestNode2.
 
 so then it can be linked together
 
 this is not a linked list of linked lists. this is an array of linked lists
 
 */


























































































#endif /* graphs_physics_hpp */
