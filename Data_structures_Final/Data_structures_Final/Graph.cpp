//
//  Graph.cpp
//  Data_structures_Final
//
//  Created by imac KK on 7/24/17.
//  Copyright © 2017 Kevin Kuwata. All rights reserved.
//
/*
 
 The following methods have been adapated and derived from Rhonda Hoenigman's e-book "Visualizing Data Structures". 
    - Dijkstra, insertVertex, insertEdge
 
 */

#include "Graph.hpp"
#include <queue>


Graph::Graph()
{
 
    
    /* Adding the vertices of the physics map, will be replaced with a read file*/
    this->addVertex("Mechanics");
    this->addVertex("Velocity & Acceleration");
    this->addVertex("Conservation Laws");
    this->addVertex("Periodic Motion");
    this->addVertex("Newton's Laws");
    this->addVertex("Mass");
    this->addVertex("Forces");
    this->addVertex("Gravity");
    this->addVertex("Work, Energy, Power");
    this->addVertex("Conservation of Energy");
    this->addVertex("Conservation of Linear Momentum");
    this->addVertex("Conservation of Angular Momentum");
    this->addVertex("Circular Motion");
    this->addVertex("Orbits");
    this->addVertex("Rotation");
    this->addVertex("Torques");
    this->addVertex("Equilibrium");
    this->addVertex("Work-Energy Principle");
    
    /* Adding the edges of the physics map, will be replaced with a read file*/
    this->addEdge("Mechanics", "Velocity & Acceleration", 1);
    this->addEdge("Mechanics", "Conservation Laws", 1);
    this->addEdge("Mechanics", "Circular Motion", 1);

    
    
    this->addEdge("Velocity & Acceleration", "Newton's Laws", 1);
    this->addEdge("Newton's Laws", "Mass", 1);
    this->addEdge("Newton's Laws", "Forces", 1);
    this->addEdge("Forces", "Gravity", 1);
    
    
    this->addEdge("Conservation of Energy", "Work, Energy, Power", 1);
    this->addEdge("Conservation of Energy", "Work-Energy Principle", 1);
    this->addEdge("Conservation Laws", "Conservation of Energy", 1);
    this->addEdge("Conservation of Energy", "Work, Energy, Power", 1);
    this->addEdge("Work, Energy, Power", "Work-Energy Principle", 1);
    this->addEdge("Conservation Laws", "Conservation of Angular Momentum", 1);
    this->addEdge("Conservation Laws", "Conservation of Linear Momentum", 1);
    
    this->addEdge("Circular Motion", "Orbits", 1);
    this->addEdge("Orbits", "Rotation", 1);
    this->addEdge("Torques", "Equilibrium", 1);
    this->addEdge("Conservation of Angular Momentum", "Torques", 1);
    
    
    //**
    this->addEdge("Velocity & Acceleration","Mechanics",  1);
    this->addEdge("Velocity & Acceleration",    "Periodic Motion",  1);
    this->addEdge(    "Periodic Motion", "Velocity & Acceleration",  1);


    this->addEdge( "Newton's Laws","Velocity & Acceleration", 1);
    this->addEdge( "Mass","Newton's Laws", 1);
    this->addEdge( "Forces", "Newton's Laws",1);
    this->addEdge("Gravity","Forces",  1);
    
    
    this->addEdge( "Conservation of Energy","Conservation Laws", 1);
    this->addEdge( "Work, Energy, Power", "Conservation of Energy",1);
    this->addEdge( "Work-Energy Principle","Conservation of Energy", 1);
    this->addEdge("Conservation Laws", "Mechanics", 1);
    this->addEdge( "Conservation of Energy","Conservation Laws", 1);
    this->addEdge( "Work, Energy, Power", "Conservation of Energy",1);
    this->addEdge( "Work-Energy Principle", "Work, Energy, Power",1);
    this->addEdge("Conservation of Angular Momentum","Conservation Laws", 1);
    this->addEdge( "Conservation of Linear Momentum", "Conservation Laws",1);
    
    this->addEdge( "Orbits","Circular Motion", 1);
    this->addEdge( "Rotation","Orbits", 1);
    this->addEdge("Equilibrium","Torques",  1);
    this->addEdge( "Torques", "Conservation of Angular Momentum",1);

}

Graph::~Graph()
{
}



void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].topic == n){
            found = true;
            cout<<vertices[i].topic<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.topic = n;
        v.distance = 0;
        v.visited = false;
        //in here we ened to find a logical way to link equations to the topic?
        //maybe a for loop and loop through the vertex topics and if match found link that root
        //then when we printout we probably should print each set of equations with each topic? or only at end?
        v.previous = nullptr;
        vertices.push_back(v);
        
    }
}

void Graph::addEdge(string v1, string v2, int weight){
    
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].topic == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].topic == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                }
            }
        }
    }
}

void Graph:: printGraph(){
    for(int x = 0; x < vertices.size(); x++){
        cout << "** "<<vertices[x].topic << "-->" ;
        for(int i = 0; i < (vertices[i].adj.size()); i ++){
            int valueTest =(vertices[i].adj.size())/5;
            if(vertices[x].adj.size() == 0){
                break;
            }
            else{
                cout << vertices[x].adj[i].v -> topic << " ";
            }
        }//end of loop going down a vector list
        cout << endl;
    }//end of loop going accross vertices
}


void Graph::printGraph2(){
    //loop through all vertices and adjacent vertices
    cout<<"============================================================"<<endl;
    for(int i = 0; i < vertices.size(); i++){ ///like walker down my array
        cout<<vertices[i].topic<<"-->"<<endl;
        
        
        //looping through adjacent vertex or adjacent lists
        for(int j = 0; j < vertices[i].adj.size(); j++){
            int testValue2 =    (vertices[i].adj.size());
            for(int t=0; t< vertices[i].adj.size(); t++){
                cout << "\t";
            }
            cout<<vertices[i].adj[j].v->topic << endl;
        }
        cout<<"============================================================"<<endl;
    }
}

void Graph:: BFS_traversal(string _topic){
    vertex * startingVertex = search_Vertex(_topic);
    
    //KEY you need to make sure the values are correct before you go down this path.
    for(int i=0; i<vertices.size(); i++){
        vertices[i].visited = false;
    }
    cout << "# " << _topic << endl;

    startingVertex-> visited = true;
    queue<vertex *> visitedQ;
    visitedQ.push(startingVertex); //line 3
    while(!visitedQ.empty()){
        vertex * n = visitedQ.front();//line 5 //to save teh value we want to deque
        visitedQ.pop(); //to remove what we just dequeued.
        for(int x =0; x  < n->adj.size(); x++){
            if(n->adj[x].v->visited == false){
                n->adj[x].v->visited = true;
                cout << "# " << n->adj[x].v->topic << endl;
                visitedQ.push(n->adj[x].v);
            }
        }
    }
}

int Graph::  search_index(string _topic){ //returns index
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].topic == _topic){
            return i;
        }
    }
    return NULL;
}
/*====================================================================================================================================================================================================================*/
vertex * Graph::  search_Vertex(string _topic){ //returns vertex.
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].topic == _topic){
            return &vertices[i];
        }
    }
    return nullptr;
}


void Graph::Dijkstra(string starting, string destination)
{
    vertex * start = nullptr;
    vertex * ending = nullptr;
    
    for(int i =0; i< vertices.size(); i++)
    {
        vertices[i].visited = false;
        vertices[i].distance = INT_MAX;
        vertices[i].previous = nullptr;
        if(vertices[i].topic == starting)
        {
            start = &vertices[i];
        }
        if(vertices[i].topic == destination)
        {
            ending = &vertices[i];
        }
        
    }
    if( start != nullptr && ending != nullptr)
    {
        start -> visited = true;
        start -> distance = 0;
        vector <vertex *> solved;
        vector <vertex *> path;
        solved.push_back(start);
        adjVertex *v;
        vertex * u;
        vertex * minVertex;
        vertex * prev;
        while(ending -> visited == false)
        {
            int minDistance = INT_MAX;
            for (int i = 0; i< solved.size(); i++)
            {
                u=solved[i];
                for(int j = 0; j < u->adj.size(); j++  )
                {
                    v = &solved[i] ->adj[j];
                    if(v->v->visited == false)
                    {
                        int dist = u ->distance + v->weight;
                        if(dist < minDistance)
                        {
                           	minDistance = dist;
                           	minVertex = v -> v;
                           	prev = u;
                            
                        }
                        
                    }
                }
            }
            solved.push_back(minVertex);
            minVertex -> distance = minDistance;
            minVertex ->previous = prev;
            minVertex -> visited = true;
        }
        vertex *vert = ending;
        while (vert != nullptr) {
            path.push_back(vert);
            vert = vert->previous;
        }
        cout << "Shorthis Path" << endl;
        for (int i = 0; i < path.size(); i++) {
            if (i == path.size()-1)
                cout<<path[path.size()-1-i]->topic;
            else
                cout<<path[path.size()-1-i]->topic<<" - ";
            
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
