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
    //make sure t1 and t2 are both in the array, if not then we must quit since one of them isn't even a valid starting/ending point
    bool doesVertexExist1 = false;
    bool doesVertexExist2 = false;

    
    for(int i=0; i < current_array_index; i++){
        if(graph_array[i].head->topic_name == t1){
            doesVertexExist1 = true;
            //match found, search again for t2
            for(int j=0; j < current_array_index; j++){
                if(graph_array[j].head->topic_name == t2){
                    //match found for t2, then a link could be made.
                    doesVertexExist2 = true;
                    cout << "t1: >>" << t1 <<" & "<<  "t2: >>" << t2 << " was found." <<  " A valid edge can be made" << endl;
                    break;
                }
            }
        }
    }
    
    if(doesVertexExist1 == false || doesVertexExist2 == false){
        cout << "a valid edge cannot be formed" << endl;
        if(doesVertexExist1 == false && doesVertexExist2 == false){
            cout << t1 << " & " << t2 << "are not valid vertex" << endl;
        }
        else if(doesVertexExist1 == false){
            cout << "t1: >>" << t1 << "<< is not a valid vertex" << endl;
        }
        else if(doesVertexExist2 == false){
            cout << "t2: >>" << t2 << "<< is not a valid vertex" << endl;
        }
        return;
    }
    
    
    
    
    
    adjVertex * newVertex = new adjVertex;
    newVertex ->topic_name = t2;
    newVertex ->next = nullptr;
    
    
    // search for where to attach newest node.
    for(int i =0; i < current_array_index; i++){ //loop through the vertices
        if(graph_array[i].head->topic_name == t1){
            
            //trying to traverse down linked list from a given element in the graph_array.
            // graph array is an array of vertices. , a collection of head pointers.
            
            //here walker is 'head' of the linked list down a column.
            adjVertex *walker = graph_array[i].head;
            
            
            while(walker->next != nullptr){
                //now we traverse the linked list.
                if(walker->topic_name == t2){
                    //we can connect becasuse they share a path.
                    //make them connect with passing next and null and hsit. like parents and child. link forward and bakcwards.
                    cout <<"already exists. terminating" << endl;
                    return;
                }
                
                walker = walker->next;
            }
            
            //not found so we can add it then.
            cout << "edge added" << endl;
            walker->next = newVertex;
            return;
            
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
        for(int i=0; i<graph_array_size; i++){
            graph_array[i].head = NULL; //just to solve any bad access when adding nodes. we depend on if null or not
        }
        
        return graph_array_size;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
