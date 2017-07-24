
//
//  graphs_physics.cpp
//  Data_structures_Final
//
//  Created by imac KK on 7/22/17.
//  Copyright © 2017 Kevin Kuwata. All rights reserved.
//

#include "graphs_physics.hpp"
#include <iostream>
#include <fstream> //for files
#include <sstream> //for parsing
#include <stdio.h>
#include <vector>
#include <climits>





graphs_physics:: graphs_physics(){
    
    
    
    //graph_array_size = 2; //just a test, this will be determined by reading/parsing the text file
    
    // graph_array  =  new adjList[graph_array_size]; //make a new dynamic array.
    
    //loop through indices of graph array and add all the vertices.
    
}

graphs_physics::  ~graphs_physics(){}




void graphs_physics:: addVertex(string _topic){
    bool found = false;
    
    for(int i =0; i < current_array_index && graph_array[i].head != NULL; i++){
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
        cout << "a valid edge cannot be formed:  \t";
        if(doesVertexExist1 == false && doesVertexExist2 == false){
            cout << t1 << " & " << t2 << " are not valid vertex" << endl;
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
                if(walker->next->topic_name == t2){
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
            while(walker->next != nullptr){
                cout << walker->topic_name << "-->" ;
                walker = walker->next;
            }
            cout << walker->topic_name ;
            cout << endl;
        }
    }
    
    
    int graphs_physics:: loadFile(char * fileName){
        
        ifstream inputFile(fileName);
        bool readlinks = false; //used to trigger when to start forming linked lists for adjacent vertex
        
        
        
        
        //determine the size of the array required;
        //will equal to the number of new lines.
        if(inputFile.is_open() == true){
            string singleLine; // each line parsed at new line
            while(getline(inputFile, singleLine, '\n')){
                graph_array_size++;
            }// end of while loop parsing at new line.
            inputFile.close();
        }
        
        //testing
        if(inputFile.is_open() == false){
            cout <<"testtt " <<endl << endl;
        }
        //end testing
        
        inputFile.open(fileName);

        
        cout <<"count is: " << graph_array_size << endl;
    
        //now create the array since we know the size
        graph_array = new adjList[graph_array_size];
        
        for(int i=0; i<graph_array_size; i++){
            
            graph_array[i].head = nullptr;
        }

        
        current_array_index = 0;
        //PARSE AGAIN: this time to place all the vertices
        if(inputFile.is_open() == true){
            string singleLine;
            while(getline(inputFile, singleLine, '\n')){
                
                if(readlinks == true){
                    //want to get a pair
                    cout << "we have just parsed: " << singleLine <<endl;
                    
                    stringstream newPairStream(singleLine);
                    string linkVertex;
                    int parsecount = 0;
                    string start_Vertex;
                    string end_Vertex;
                    while(getline(newPairStream, linkVertex, ',')){
                        if(parsecount==0){
                            start_Vertex = linkVertex;
                            parsecount++;
                        }
                        else if(parsecount == 1){
                            end_Vertex = linkVertex;
                            parsecount = 0;
                        }
                    }
                    addEdge(start_Vertex, end_Vertex, 1);
                   // addEdge("line 1", "line 6", 2); //does this auto add to the graph?
                    
                }

                
                //if we see **** then we know its the links
                if(singleLine == "****"){
                    cout << " next we will get links" << endl;
                    readlinks = true;
                }
                
//                if(readlinks == true){
//                    graph_array[current_array_index].head->next = ;
//                }
                
                if(readlinks == false){
                //get a line, parse it for each vertex
                //create new vertex
                adjVertex *newVertex = new adjVertex;
                newVertex->topic_name = singleLine;
                newVertex->next = nullptr;
                //insert into vertex array
                graph_array[current_array_index].head = newVertex;
                
                //graph_array[current_array_index].head->topic_name= singleLine;
                current_array_index++;
                }
            }
        }
        return current_array_index;
}
    
    

void graphs_physics:: Dijkstra(string starting, string destination){

    adjVertex * start = nullptr;
    adjVertex * ending = nullptr;
    //search routine to find starting and destination
    for (int i = 0; i < current_array_index; i++) {
        graph_array[i].head->visited = false;
        graph_array[i].head->distance = INT_MAX;
        graph_array[i].head->previous = nullptr;
        if (graph_array[i].head->topic_name == starting) {
            start = graph_array[i].head;
        }
        if (graph_array[i].head->topic_name == destination) {
            ending = graph_array[i].head;
            break;// modified
        }
    }
    if (start != nullptr && ending != nullptr)
    {
        start->visited = true;
        start->distance = 0;
        cout<<"pushing "<<start->topic_name<<" into solved"<<endl;
        vector<adjVertex *> solved;
        vector<adjVertex *> path;
        solved.push_back(start);
            //path.push_back(start);
        adjVertex * v;
        adjVertex * u;
        adjVertex * minVertex;
        adjVertex * prev;
        while (ending->visited == false) {
            int minDistance = INT_MAX;
            int testingSolvedsize = solved.size();
            for (int i = 0; i < solved.size(); i++) {
                u = solved[i];
                cout<<endl;
                cout<<"Inspecting route from "<<u->topic_name<<endl;
                
                
                //MODIFIED
                /* Side note to find the size of a given linked list*/
                int linkedListSize = 0;
                adjVertex *walker = u;
                while(walker!=nullptr){
                    linkedListSize++;
                    walker = walker->next;
                }
                
                
                
                
                
                //MODIFIED
                //for (int j = 0; j < u->adj.size(); j++) {
               // for (int j = 0; j < linkedListSize; j++) {
                walker = solved[i]->next;
                v = walker;
                while(walker != nullptr){
               // v = &solved[i]->adj[j];
//                    v = walker;
                    
                    cout<<"-> to "<<v->topic_name;
                    
                    
                    if (v->visited == false) {
                        cout<<", not yet solved,";
                        int dist = u->distance + v->weight;
                        if (dist < minDistance) {
                            cout<<" the minimum distance was "<<minDistance;
                            minDistance = dist;
                           // minVertex = v->v;
                            minVertex = v;
                            
                            prev = u;
                            cout<<" but there is a new minimum distance of "<<dist<<" between "
                            <<start->topic_name <<" and "<<minVertex->topic_name<<endl;
                        }
                        else{
                            cout<<" the minimum distance is "<< minDistance
                            <<" and there is not a new minimum distance "<<dist<<endl;
                        }
                    }else
                    {
                        cout<<" already solved, moving on"<<endl;
                    }
                    
                    walker = walker->next;
                }//end of traverse over the linked list.

            }
            solved.push_back(minVertex);
            cout<<endl;
            cout<<"pushing "<<minVertex->topic_name<<" into solved ";
            minVertex->distance = minDistance;
            minVertex->previous = prev;
            v->visited =true; // modified
           // ending->visited = true; //we know that ending is not being updated when v is updated. or min is update, but we also know that when v is updated so is minVertex, they share the same address.
            //we see that ending does not share address with miVertex. its a copy.
            //strangly we see that start has the same address as u.?! why
            
            minVertex->visited = true;
            cout<<minVertex->topic_name;
            cout<<"(distance: "<<minVertex->distance
            <<", visited: "<<minVertex->visited
            <<", parent: "<<minVertex->previous->topic_name<<")"<<endl;
            cout<<"destination "<<ending->topic_name<<" solved? "<<ending->visited<<endl;
            cout<<endl;
        }
        cout<<"Shortest Path"<<endl;
        adjVertex * vert = ending;
        while (vert != nullptr) {
            path.push_back(vert);
            vert = vert->previous;
        }
        for (int i = 0; i < path.size(); i++) {
            if (i == path.size()-1)
                cout<<path[path.size()-1-i]->topic_name;
            else
                cout<<path[path.size()-1-i]->topic_name<<" - ";

        }
        cout<<endl;
        cout<<"Minimum Distance: "<<solved[solved.size()-1]->distance<<endl;
    }else if (ending!=nullptr){
        cout<<"start not found"<<endl;
        exit(1);
    }else{
        cout<<"ending not found"<<endl;
        exit(1);
    }
}



    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

