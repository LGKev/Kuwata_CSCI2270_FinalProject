//
//  graphs_physics.cpp
//  Data_structures_Final
//
//  Created by imac KK on 7/22/17.
//  Copyright © 2017 Kevin Kuwata. All rights reserved.
//

#include "graphs_physics.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>



graphs_physics:: graphs_physics(){
    
    
    
    //graph_array_size = 2; //just a test, this will be determined by reading/parsing the text file
    
   // graph_array  =  new adjList[graph_array_size]; //make a new dynamic array.
    
    //loop through indices of graph array and add all the vertices.
    
}

graphs_physics::  ~graphs_physics(){}




void graphs_physics:: addVertex(string _topic){
    bool found = false;
    
    
    
    
    for(int i =0; i < graph_array_size && graph_array[i].head != NULL; i++){
        if(graph_array[i].head->topic_name  == _topic){
            found = true;
            cout << "vertex already exitst, this is a duplicate" << endl;
            break;
        }
    }
    //end of search, not found
    if(found == false){
        
        if(current_array_index > graph_array_size){
            cout << "graph full" << endl;
            return;
        }
        
        adjVertex* newVertex = new adjVertex;
        
        newVertex->topic_name = _topic;
        newVertex->next = nullptr;
        
        graph_array[current_array_index].head = newVertex;
        current_array_index++;
    }
    
}

void graphs_physics:: addEdge(string t1, string t2, int _weight){
    for(int i =0; i < graph_array_size; i++){ //loop through the vertices
        if(graph_array[i].head->topic_name == t1){
            
            //trying to traverse down linked list from a given element in the graph_array.
            // graph array is an array of vertices. , a collection of head pointers.
            
            //here walker is 'head' of the linked list down a column.
            adjVertex *walker = graph_array[i].head;
            
            
            while(walker != nullptr){
               //now we traverse the linked list.
                if(walker->topic_name == t2){
                    //we can connect becasuse they share a path.
                    //make them connect with passing next and null and hsit. like parents and child. link forward and bakcwards.
                }
               
                walker = walker->next;
            }
        }
    }
}


//array size should be not totally size but the number of elements.
void graphs_physics:: printGraph(){
    int i;
    for(i=0; i < current_array_index; i++){
        adjVertex * walker = graph_array[i].head;
        while(walker!= nullptr){
            cout << walker->topic_name << "-->" ;
            walker = walker->next;
        }
        cout << endl;
    }
}


int graphs_physics:: loadFile(char * fileName){
   
    ifstream inputFile(fileName);
    
    
    int attributeCount = 0; //could be used if each vertex in graph has more info than just name, such as weight.
   
    
    if(inputFile.is_open() == true){
        string singleLine; // each line parsed at new line

        
        while(getline(inputFile, singleLine, '\n')){
            cout << "line read: " << singleLine << endl;
            graph_array_size++;
        }// end of while loop parsing at new line.
    }
    
    
    
    //now create the array since we know the size
    
    graph_array = new adjList[graph_array_size];
   
    return graph_array_size;
}

































































