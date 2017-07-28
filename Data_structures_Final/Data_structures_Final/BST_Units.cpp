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
BST_Units:: BST_Units(){
}


BST_Units:: ~BST_Units(){}



void  BST_Units:: inOrderPrint(){
    
}


infoBlock * BST_Units::buildList(string array[], int sizeA)
{
    infoBlock *walker = nullptr;
    for(int i=0;i<sizeA;i++){
        infoBlock *temp = new infoBlock;//each time build a node
        temp->equation = array[i];//initialize with value in array
        temp->next = nullptr;//initialize to nullptr
        if(head == nullptr){ //if list is empty
            head = temp;
            walker = head;
        }
        else{//if list has nodes
            walker->next = temp;
            walker = walker->next;
        }
    }
    return head;
}

