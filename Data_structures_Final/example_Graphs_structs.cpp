//////
//////  example_Graphs_structs.cpp
//////  Data_structures_Final
//////
//////  Created by imac KK on 7/22/17.
//////  Copyright © 2017 Kevin Kuwata. All rights reserved.
//////
////
//#include <stdio.h>
//#include "Graph.hpp"
//using namespace std;
//
//struct vertex;
//
//struct adjVertex{
//    vertex *v;
//    int weight;
//};
//
//struct vertex{
//    std::string topic;
//    bool visited;
//    int distance;
//    //infoBlock *equations; extra, defined in main :-/
//    vertex *previous;
//    std::vector<adjVertex> adj; //mine this is the HEAD of the linked list
//};
//
//class Graph
//{
//public:
//    Graph();
//    ~Graph();
//    void addEdge(std::string v1, std::string v2, int weight);
//    void addVertex(std::string topic);
//    void printGraph2();
//    void printGraph();
//    void Dijkstra(string sourceVertex, string destinationVertex);
//    int BFSFind(string startVertex);
//protected:
//private:
//    //vector<edge> edges;
//    std::vector<vertex> vertices; //this is replacign my array
//    
//};
//
//
//Graph::Graph()
//{
//    
//}
//
//Graph::~Graph()
//{
//    //dtor
//}
//
//
//
//void Graph::addVertex(string n){
//    bool found = false;
//    for(int i = 0; i < vertices.size(); i++){
//        if(vertices[i].topic == n){
//            found = true;
//            cout<<vertices[i].topic<<" found."<<endl;
//        }
//    }
//    if(found == false){
//        vertex v;
//        v.topic = n;
//        v.distance = 0;
//        v.visited = false;
//        //in here we ened to find a logical way to link equations to the topic?
//        //maybe a for loop and loop through the vertex topics and if match found link that root
//        //then when we printout we probably should print each set of equations with each topic? or only at end?
//        v.previous = nullptr;
//        vertices.push_back(v);
//        
//    }
//}
//
//
///*
// ALternative. what if I simply just made a tree and made a graph. when the graph prints out the user could be promped if they want the equations or not. so we find the shortest path
// then we ask show equations?
// then we use the parents to traverse the list to get the path
// and at each vertex in the path we print out a mini tree  of equations
// we know which tree to print by searching topic names and matching to the root->topicName;
// 
// vertiex->name == root->topicName
// print out equations, traversed.
// 
// 
// */
//void Graph::addEdge(string v1, string v2, int weight){
//    
//    for(int i = 0; i < vertices.size(); i++){
//        if(vertices[i].topic == v1){
//            for(int j = 0; j < vertices.size(); j++){
//                if(vertices[j].topic == v2 && i != j){
//                    adjVertex av;
//                    av.v = &vertices[j];
//                    av.weight = weight;
//                    vertices[i].adj.push_back(av);
//                    //another vertex for edge in other direction
//                    adjVertex av2;
//                    av2.v = &vertices[i];
//                    av2.weight = weight;
//                    vertices[j].adj.push_back(av2);
//                }
//            }
//        }
//    }
//}
//
//
////pssibly not owrking. add more nodes to find out. book code seg faults randomly.
//void Graph:: printGraph(){
//    for(int x = 0; x < vertices.size(); x++){
//        cout << "** "<<vertices[x].topic << "-->" ;
//        for(int i = 0; i<vertices[i].adj.size(); i ++){
//            if(vertices[x].adj.size() == 0){
//                break;
//            }
//            else{
//                cout << vertices[x].adj[i].v -> topic << " ";
//            }
//        }//end of loop going down a vector list
//        cout << endl;
//    }//end of loop going accross vertices
//}
//
//void Graph::printGraph2(){
//    //loop through all vertices and adjacent vertices
//    cout<<"============================================================"<<endl;
//    for(int i = 0; i < vertices.size(); i++){ ///like walker down my array
//        cout<<vertices[i].topic<<"-->"<<endl;
//        
//        
//        //looping through adjacent vertex or adjacent lists
//        for(int j = 0; j < vertices[i].adj.size(); j++){
//            
//            
//            cout<<vertices[i].adj[j].v->topic;
//            cout<<" (distance: "<<vertices[i].adj[j].v->distance
//            <<", visited: "<<vertices[i].adj[j].v->visited<<", parent: ";
//            if (vertices[i].adj[j].v->previous==nullptr)
//                cout<<" nullptr)"<<endl;
//            else
//                cout<<vertices[i].adj[j].v->previous->topic<<")"<<endl;
//        }
//        cout<<"============================================================"<<endl;
//    }
//}
//
//void Graph::Dijkstra(string starting, string destination){
//    
//    vertex * start = nullptr;
//    vertex * ending = nullptr;
//    //search routine to find starting and destination
//    for (int i = 0; i < vertices.size(); i++) {
//        vertices[i].visited = false;
//        vertices[i].distance = INT_MAX;
//        vertices[i].previous = nullptr;
//        if (vertices[i].topic == starting) {
//            start = &vertices[i];
//        }
//        if (vertices[i].topic == destination) {
//            ending = &vertices[i];
//        }
//    }
//    if (start != nullptr && ending != nullptr)
//    {
//        start->visited = true;
//        start->distance = 0;
//        cout<<"pushing "<<start->topic<<" into solved"<<endl;
//        vector<vertex *> solved;
//        vector<vertex *> path;
//        solved.push_back(start);
//        //path.push_back(start);
//        adjVertex * v;
//        vertex * u;
//        vertex * minVertex;
//        vertex * prev;
//        while (ending->visited == false) {
//            int minDistance = INT_MAX;
//            for (int i = 0; i < solved.size(); i++) {
//                u = solved[i];
//                cout<<endl;
//                cout<<"Inspecting route from "<<u->topic<<endl;
//                for (int j = 0; j < u->adj.size(); j++) {
//                    v = &solved[i]->adj[j];
//                    cout<<"-> to "<<v->v->topic;
//                    if (v->v->visited == false) {
//                        cout<<", not yet solved,";
//                        int dist = u->distance + v->weight;
//                        if (dist < minDistance) {
//                            cout<<" the minimum distance was "<<minDistance;
//                            minDistance = dist;
//                            minVertex = v->v;
//                            prev = u;
//                            cout<<" but there is a new minimum distance of "<<dist<<" between "
//                            <<start->topic <<" and "<<minVertex->topic<<endl;
//                        }else{cout<<" the minimum distance is "<<minDistance
//                            <<" and there is not a new minimum distance "<<dist<<endl;}
//                    }else{
//                        cout<<" already solved, moving on"<<endl;
//                    }
//                }
//                
//            }
//            solved.push_back(minVertex);
//            cout<<endl;
//            cout<<"pushing "<<minVertex->topic<<" into solved ";
//            minVertex->distance = minDistance;
//            minVertex->previous = prev;
//            minVertex->visited = true;
//            cout<<minVertex->topic;
//            cout<<"(distance: "<<minVertex->distance
//            <<", visited: "<<minVertex->visited
//            <<", parent: "<<minVertex->previous->topic<<")"<<endl;
//            cout<<"destination "<<ending->topic<<" solved? "<<ending->visited<<endl;
//            cout<<endl;
//        }
//        cout<<"Shortest Path"<<endl;
//        vertex * vert = ending;
//        while (vert != nullptr) {
//            path.push_back(vert);
//            vert = vert->previous;
//        }
//        for (int i = 0; i < path.size(); i++) {
//            if (i == path.size()-1)
//                cout<<path[path.size()-1-i]->topic;
//            else
//                cout<<path[path.size()-1-i]->topic<<" - ";
//            
//        }
//        cout<<endl;
//        cout<<"Minimum Distance: "<<solved[solved.size()-1]->distance<<endl;
//    }else if (ending!=nullptr){
//        cout<<"start not found"<<endl;
//        exit(1);
//    }else{
//        cout<<"ending not found"<<endl;
//        exit(1);
//    }
//}
