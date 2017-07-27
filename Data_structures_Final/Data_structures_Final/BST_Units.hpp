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
    string topicName;
    string equation;
    //constants?
    infoBlock *parent;
    infoBlock *left;
    infoBlock *right;
    
    infoBlock(string _topic, string _eqn, infoBlock *p, infoBlock *l, infoBlock *r): topicName(_topic), equation(_eqn), parent(p), left(l), right(r){};
    
};


class BST_Units{
public:
    BST_Units();
    ~BST_Units();
    
    infoBlock *search(string topic);
    infoBlock *deleteNode(string topic); //probably won't use
    infoBlock *buildFromFile(char * fileName);
    void inOrderPrint(infoBlock * node);
    infoBlock *insertNode(string topicName, string equation);
    
    
private:
    infoBlock *root = nullptr;
    infoBlock *treeMinimum(); //probably won't use
};




#endif /* BST_Units_hpp */
