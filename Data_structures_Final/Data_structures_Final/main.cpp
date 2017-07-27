////
////  main.cpp
////  Data_structures_Final
////
////  Created by imac KK on 7/22/17.
////  Copyright © 2017 Kevin Kuwata. All rights reserved.
////
//




/*
 Some Ideas for second data strcuture:
    - binary search tree for units 
    - binary search tree for major discovery sorted by date and topic. so each topic will have 5 events and you can search for the 'latest' or the 'first'
    - hash table to  'encrypt' a  password to start program.
 
 
 */
#include <iostream>
#include "graphs_physics.hpp"
#include <string>
#include <fstream>

#include "Graph.hpp"
#include "BST_Units.hpp"


using namespace std;


/*
 ALternative. what if I simply just made a tree and made a graph. when the graph prints out the user could be promped if they want the equations or not. so we find the shortest path
 then we ask show equations?
    then we use the parents to traverse the list to get the path
    and at each vertex in the path we print out a mini tree  of equations
 we know which tree to print by searching topic names and matching to the root->topicName;
 
 vertiex->name == root->topicName 
    print out equations, traversed.
 
 
 */


// int Graph:: BFSFind(string startVertex){
//    bool foundStartVertex=false;
//    for (int i=0;i<vertices.size(); i++){
//        if (vertices[i].name == startVertex){
//            return i;
//        }
//    }
//    cout<<"starting vertex does not exist"<<endl;
//    return -1;
//
//}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    if(argc !=2){
        cout << "Please provide an input file" << endl;
        return -1;
    }
    
    string filetopic = argv[1];
    
    cout << "filetopic: " << filetopic << endl;
    
    char * filePTR = &filetopic[0]; //string -> array of characters-> address of first element to get derefrence address of first character.
    
    
    
    Graph test;
    
//   test.printGraph();
    test.printGraph2();
    
    //test.printGraph();
    cout << endl << endl;
    
    test.Dijkstra("Mechanics", "Work-Energy Principle");
    test.Dijkstra( "Work-Energy Principle","Mechanics");
    
    cout <<"============================================================" << endl;
    
    test.BFS_traversal("Mechanics");
    
    /* old Code, physics_graph ADT.*/
//    
////    graphs_physics myWeb;
////    
////    myWeb.loadFile(filePTR); //load, parse & count, create array, fill array, fill in linked lists too.
//
//
//
//
//    //verify results are correct
//    cout << endl;
//    myWeb.printGraph();
    


    
    BST_Units ex;
   
    cout << endl << endl;
    
    
    infoBlock * energy = ex.insertNode("Kinetic", "1/2mv^2");
    ex.insertNode("Potential", "mgh");
    ex.insertNode("Work", "force cross distance");

    ex.inOrderPrint(energy);
    
    cout << endl;
    
    
    return 0;
}

