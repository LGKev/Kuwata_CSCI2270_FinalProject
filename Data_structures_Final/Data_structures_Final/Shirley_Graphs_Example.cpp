////
////  Shirley_Graphs_Example.cpp
////  Data_structures_Final
////
////  Created by imac KK on 7/22/17.
////  Copyright © 2017 Kevin Kuwata. All rights reserved.
////
///*
// 
//  _____ _     _      _              _____           _
// /  ___| |   (_)    | |            /  __ \         | |
// \ `--.| |__  _ _ __| | ___ _   _  | /  \/ ___   __| | ___
//  `--. \ '_ \| | '__| |/ _ \ | | | | |    / _ \ / _` |/ _ \
// /\__/ / | | | | |  | |  __/ |_| | | \__/\ (_) | (_| |  __/
// \____/|_| |_|_|_|  |_|\___|\__, |  \____/\___/ \__,_|\___|
//                             __/ |
//                            |___/
// 
// */
//#include <iostream>
//#include <vector>
//#include <climits>
//
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
//    std::string name;
//    bool visited;
//    int distance;
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
//    void addVertex(std::string name);
//    void displayEdges();
//    void Dijkstra(string sourceVertex, string destinationVertex);
//protected:
//private:
//    //vector<edge> edges;
//    std::vector<vertex> vertices; //this is replacign my array
//    
//};
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
//void Graph::addEdge(string v1, string v2, int weight){
//    
//    for(int i = 0; i < vertices.size(); i++){
//        if(vertices[i].name == v1){
//            for(int j = 0; j < vertices.size(); j++){
//                if(vertices[j].name == v2 && i != j){
//                    adjVertex av;
//                    av.v = &vertices[j];
//                    av.weight = weight;
//                    vertices[i].adj.push_back(av);
//                    //another vertex for edge in other direction
//                    //adjVertex av2;
//                    //av2.v = &vertices[i];
//                    //av2.weight = weight;
//                    //vertices[j].adj.push_back(av2);
//                }
//            }
//        }
//    }
//}
//void Graph::addVertex(string n){
//    bool found = false;
//    for(int i = 0; i < vertices.size(); i++){
//        if(vertices[i].name == n){
//            found = true;
//            cout<<vertices[i].name<<" found."<<endl;
//        }
//    }
//    if(found == false){
//        vertex v;
//        v.name = n;
//        v.distance = 0;
//        v.visited = false;
//        v.previous = nullptr;
//        vertices.push_back(v);
//        
//    }
//}
//
//void Graph::displayEdges(){
//    //loop through all vertices and adjacent vertices
//    cout<<"============================================================"<<endl;
//    for(int i = 0; i < vertices.size(); i++){ ///like walker down my array
//        cout<<vertices[i].name<<"-->"<<endl;
//       
//        
//        //looping through adjacent vertex or adjacent lists
//        for(int j = 0; j < vertices[i].adj.size(); j++){
//            
//            
//            cout<<vertices[i].adj[j].v->name;
//            cout<<" (distance: "<<vertices[i].adj[j].v->distance
//            <<", visited: "<<vertices[i].adj[j].v->visited<<", parent: ";
//            if (vertices[i].adj[j].v->previous==nullptr)
//                cout<<" nullptr)"<<endl;
//            else
//                cout<<vertices[i].adj[j].v->previous->name<<")"<<endl;
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
//        if (vertices[i].name == starting) {
//            start = &vertices[i];
//        }
//        if (vertices[i].name == destination) {
//            ending = &vertices[i];
//        }
//    }
//    if (start != nullptr && ending != nullptr)
//    {
//        start->visited = true;
//        start->distance = 0;
//        cout<<"pushing "<<start->name<<" into solved"<<endl;
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
//                cout<<"Inspecting route from "<<u->name<<endl;
//                for (int j = 0; j < u->adj.size(); j++) {
//                    v = &solved[i]->adj[j];
//                    cout<<"-> to "<<v->v->name;
//                    if (v->v->visited == false) {
//                        cout<<", not yet solved,";
//                        int dist = u->distance + v->weight;
//                        if (dist < minDistance) {
//                            cout<<" the minimum distance was "<<minDistance;
//                            minDistance = dist;
//                            minVertex = v->v;
//                            prev = u;
//                            cout<<" but there is a new minimum distance of "<<dist<<" between "
//                            <<start->name <<" and "<<minVertex->name<<endl;
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
//            cout<<"pushing "<<minVertex->name<<" into solved ";
//            minVertex->distance = minDistance;
//            minVertex->previous = prev;
//            minVertex->visited = true;
//            cout<<minVertex->name;
//            cout<<"(distance: "<<minVertex->distance
//            <<", visited: "<<minVertex->visited
//            <<", parent: "<<minVertex->previous->name<<")"<<endl;
//            cout<<"destination "<<ending->name<<" solved? "<<ending->visited<<endl;
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
//                cout<<path[path.size()-1-i]->name;
//            else
//                cout<<path[path.size()-1-i]->name<<" - ";
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
//
//
//int main() {
//    cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
//    cout<<"This is a heavily commented program to show you \n"
//    <<"as much as possible the workings of Dijkstra.\n"
//    <<"It starts with printing each vertex, followed by \n"
//    <<"their adjacency lists, and their variable states.\n"
//    <<"Then it performs Dijkstra and prints the states of \n"
//    <<"the variables again.\n";
//    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
//    Graph g;
//    // example 1
//    g.addVertex("A");
//    g.addVertex("B");
//    g.addVertex("C");
//    g.addVertex("D");
//    //example in class
//	   /*g.addVertex("E");
//        g.addVertex("F");
//        g.addVertex("G");
//        g.addVertex("H");
//        */
//    //edges written to be undirected
//    //example 1
//    g.addEdge("A", "B", 4);
//    g.addEdge("B", "A", 4);
//    g.addEdge("A", "C", 1);
//    g.addEdge("C", "A", 1);
//    g.addEdge("B", "C", 3);
//    g.addEdge("C", "B", 3);
//    g.addEdge("B", "D", 1);
//    g.addEdge("D", "B", 1);
//    g.addEdge("C", "D", 9);
//    g.addEdge("D", "C", 9);
//    //example in class
//    /*  g.addEdge("A", "B", 1);
//     g.addEdge("A", "E", 4);
//     g.addEdge("A", "F", 8);
//     g.addEdge("B", "A", 1);
//     g.addEdge("B", "C", 2);
//     g.addEdge("B", "F", 6);
//     g.addEdge("B", "G", 6);
//     g.addEdge("C", "B", 2);
//     g.addEdge("C", "D", 1);
//     g.addEdge("C", "G", 2);
//     g.addEdge("D", "C", 1);
//     g.addEdge("D", "G", 1);
//     g.addEdge("D", "H", 4);
//     g.addEdge("E", "A", 4);
//     g.addEdge("E", "F", 5);
//     g.addEdge("F", "A", 8);
//     g.addEdge("F", "B", 6);
//     g.addEdge("F", "E", 5);
//     g.addEdge("F", "G", 1);
//     g.addEdge("G", "B", 6);
//     g.addEdge("G", "C", 2);
//     g.addEdge("G", "D", 1);
//     g.addEdge("G", "F", 1);
//     g.addEdge("G", "H", 1);
//     g.addEdge("H", "D", 4);
//     g.addEdge("H", "G", 1);
//     */
//    //example 2
//    
//    
//    g.displayEdges();
//    //running Dijkstra
//    g.Dijkstra("A", "D");
//    g.displayEdges();
//    //g.Dijkstra("A", "G");
//    //g.Dijkstra("B", "H");
//    return 0;
//}
