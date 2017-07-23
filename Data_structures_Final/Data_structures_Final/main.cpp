////
////  main.cpp
////  Data_structures_Final
////
////  Created by imac KK on 7/22/17.
////  Copyright © 2017 Kevin Kuwata. All rights reserved.
////
//
#include <iostream>
#include "graphs_physics.hpp"
#include <string>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    if(argc !=2){
        cout << "Please provide an input file" << endl;
        return -1;
    }
    
    string fileName = argv[1];
    
    cout << "filename: " << fileName << endl;
    
    char * filePTR = &fileName[0]; //string -> array of characters-> address of first element to get derefrence address of first character.
    
    graphs_physics myWeb;
    
    myWeb.loadFile(filePTR); //load, parse, create array, fill array
   
    
    /*
    myWeb.addVertex("test1");
    myWeb.addVertex("test2");
    myWeb.addVertex("test3");
    
    

    
    //testing corner case: where 2nd vertex trying to link to somethign that doesn't exist.
    myWeb.addEdge("test1", "test does not exist", 1);
    //testing corner case: where 1st vertex does not exist.
    myWeb.addEdge("3", "test1", 1);
    
    
    
    */
    myWeb.printGraph();
    
    // testing valid case:
    myWeb.addEdge("line 1", "line 2", 1); //pass
    myWeb.addEdge("test3", "test1", 1); //fail
    myWeb.addEdge("line 2", "line 5", 1);
    myWeb.addEdge("line 4", "line 5", 1);
    myWeb.addEdge("line 5", "line 2", 1);
    
    
    //verify results are correct
    myWeb.printGraph();
    return 0;
}

