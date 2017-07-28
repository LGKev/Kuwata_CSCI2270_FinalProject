//
//  BST_Units.hpp
//  Data_structures_Final
//
//  Created by imac KK on 7/25/17.
//  Copyright © 2017 Kevin Kuwata. All rights reserved.
//

#ifndef BST_Units_hpp
#define BST_Units_hpp

#include <stdio.h>
#include <string>
using namespace std;

struct infoBlock{
    string equation= "";
    //constants?
    infoBlock * next;
    
    
};


class BST_Units{
public:
    BST_Units();
    ~BST_Units();
    
    void inOrderPrint();
    infoBlock *insertNode( infoBlock * head, string _equation);
    infoBlock *buildList(string array[], int sizeA);
    
    
    
private:
    infoBlock *head = nullptr;
    infoBlock *treeMinimum(); //probably won't use
};




#endif /* BST_Units_hpp */
