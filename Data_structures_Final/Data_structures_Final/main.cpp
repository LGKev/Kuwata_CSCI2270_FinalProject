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
    
    myWeb.loadFile(filePTR);
   
    
    
    myWeb.addVertex("test1");
    myWeb.addVertex("test2");
    myWeb.addVertex("test3");
    
    myWeb.addEdge("test1", "test3", 1);
    
    
    myWeb.printGraph();
    
    
    return 0;
}

