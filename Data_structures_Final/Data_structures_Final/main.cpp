////
////  main.cpp
////  Data_structures_Final
////
////  Created by imac KK on 7/22/17.
////  Copyright © 2017 Kevin Kuwata. All rights reserved.
////
//



#include <iostream>
#include <string>
#include <fstream>

#include "Graph.hpp"


using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    
    Graph test;
    
    test.print_equations();
    
    test.printGraph2();
    
    
    test.BFS_traversal("Elctricity & Magnetism");
    
    cout <<"============================================================" << endl;

    test.DFS_iterrative("Elctricity & Magnetism");
    cout <<"============================================================" << endl;

    test.DFS_traversal("Elctricity & Magnetism");
    
    test.Dijkstra("Elctricity & Magnetism", "Power");
    
    
    
    return 0;
}

