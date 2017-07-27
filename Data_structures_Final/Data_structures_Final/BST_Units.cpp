//
//  BST_Units.cpp
//  Data_structures_Final
//
//  Created by imac KK on 7/25/17.
//  Copyright © 2017 Kevin Kuwata. All rights reserved.
//

#include "BST_Units.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
BST_Units:: BST_Units(){}
BST_Units:: ~BST_Units(){}

infoBlock * BST_Units:: insertNode(string topicName, string equation){
    infoBlock *newBlock = new infoBlock(topicName, equation, nullptr, nullptr, nullptr);
    if(root == nullptr){
        root = newBlock;
    }else{
        infoBlock *walker = root;
        infoBlock *walker_parent = root;
        while(walker != nullptr){
            walker_parent = walker;//when nullptr reached, cannot access parent
            if(topicName < walker-> topicName){
                walker = walker->left;
            }else{
                walker = walker->right;
            }
        }//finished traversing/found location for newNode
        if(topicName < walker_parent->topicName){//newNode will be a left child
            walker_parent->left = newBlock;
            newBlock->parent = walker_parent;
            //cout<<"newNode: "<<newNode->key<<" with parent: "<<walker_parent->key<<endl;
        }else{//newNode will be a right child
            walker_parent->right = newBlock;
            newBlock->parent = walker_parent;
            //cout<<"newNode: "<<newNode->key<<" with parent: "<<walker_parent->key<<endl;
        }
    }
    return root;
}

infoBlock * BST_Units:: buildFromFile(char * fileName){
    //all about parsing, more important to figure out how to insert
    return root;
}


infoBlock * BST_Units:: search(string topic){
    return root;
}








void  BST_Units:: inOrderPrint(infoBlock * node){
    if(node->left != nullptr){
        inOrderPrint(node->left);
    }
    cout<<node->equation<<" ";
    if(node->right != nullptr){
        inOrderPrint(node->right);
    }
}


/*
 Not yet utilized.
 */
infoBlock * BST_Units:: treeMinimum(){ //probably won't use
    return root;
}

infoBlock * BST_Units:: deleteNode(string topic){ //probably won't use
    return root;
}
