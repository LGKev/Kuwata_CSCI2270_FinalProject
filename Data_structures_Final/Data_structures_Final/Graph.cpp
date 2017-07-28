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
    this->addVertex("Elctricity & Magnetism", "", "");
    /* Adding the vertices of the physics map, will be replaced with a read file*/
    
    this->addVertex("Voltage", "V = I * R", "V_1 + V_2 = V_tot, Kirchoff Voltage Law");
    this->addVertex("Current", "I = V / R ", "dQ/dT");
    this->addVertex("Ohm's Law", "V = I * R", "");
    this->addVertex("Resistor", "Resistance = (P*L)/A ", "R = V / I");
    this->addVertex("Capacitor", "Q = C/V", "1/C_eq = 1/C_1 + 1/C_2 + ... + 1/C_n");
    this->addVertex("Inductor", "Emf = -L (dI/dt)", "");
    this->addVertex("Electric Charge", "Q", "");
    this->addVertex("Electric Force", "F = k * Q_1 * Q_2 / r^2", "k = 9x10^9 [N*m^2/C^2]");
    this->addVertex("Couloumb's Law", "E = F/Q", "");
    this->addVertex("Lorentz Force", "F = E_force + B_force", "F = q*E + qv X B");
    this->addVertex("Biot-Savart Law", "dB = u * I *dL X I/ (4*pi*r^2)", "");
    this->addVertex("Faraday Law", "Emf = -N * dPhi/dt", "Phi = magnetic Flux / m^2" );
    this->addVertex("Power", "P = I * V", "P = I^2 * R");
    this->addVertex("Gauss's Law", "Phi - Q/E_o", "integrate [E•dA] = Q/E_o");
    this->addVertex("Magnetic Field", "F = qv X B", "");
    this->addVertex("Ampere's Law", "Sum[B||∆l] = u_o * I", "");
    
    //vertices with out equations but help link everything
    this->addVertex("Electric Circuits", "", "");
    this->addVertex("Maxwell's Equations", "", "");
    this->addVertex("Charge", "", "");
    
    
    
    
    
    this->addEdge("Electric Circuits", "Voltage", 1);
    this->addEdge("Electric Circuits", "Current", 1);
    this->addEdge("Electric Circuits", "Power", 1);
    this->addEdge("Electric Circuits", "Resistor", 1);
    this->addEdge("Electric Circuits", "Inductor", 1);
    this->addEdge("Electric Circuits", "Capacitor", 1);
    
    this->addEdge("Voltage", "Electric Circuits",  1);
    this->addEdge("Current", "Electric Circuits",  1);
    this->addEdge("Power",  "Electric Circuits", 1);
    this->addEdge( "Resistor",  "Electric Circuits",1);
    this->addEdge( "Inductor", "Electric Circuits", 1);
    this->addEdge("Capacitor", "Electric Circuits",  1);
    
    
    
    
    
    this->addEdge("Capacitor", "Charge", 1);
    
    
    this->addEdge("Voltage", "Current", 1);
    this->addEdge("Current", "Voltage", 1);
    
    
    this->addEdge("Voltage", "Resistance", 1);
    this->addEdge( "Resistance", "Voltage", 1);
    
    this->addEdge("Current", "Power", 1);
    this->addEdge("Power", "Current",  1);
    
    this->addEdge("Current", "Resistance", 1);
    this->addEdge("Resistance", "Current",  1);
    
    this->addEdge("Current", "Charge", 1);
    this->addEdge( "Charge", "Current", 1);
    
    
    
    
    this->addEdge("Ohm's Law", "Voltage", 1);
    this->addEdge("Ohm's Law", "Current", 1);
    this->addEdge("Ohm's Law", "Power", 1);
    this->addEdge("Voltage", "Ohm's Law",  1);
    this->addEdge("Current",  "Ohm's Law", 1);
    this->addEdge("Power", "Ohm's Law",  1);
    
    
    this->addEdge("Power", "Current", 1);
    this->addEdge("Power", "Voltage", 1);
    this->addEdge("Power", "Resistance", 1);
    this->addEdge("Current", "Power",  1);
    this->addEdge("Voltage", "Power",  1);
    this->addEdge("Resistance", "Power",  1);
    
    
    
    this->addEdge("Elctricity & Magnetism", "Electric Circuits", 1);
    this->addEdge("Elctricity & Magnetism", "Charge", 1);
    this->addEdge("Elctricity & Magnetism", "Magnetic Field", 1);
    this->addEdge("Elctricity & Magnetism", "Lorentz Force", 1);
    
    this->addEdge("Electric Circuits",  "Electricity & Magnetism", 1);
    this->addEdge("Charge", "Electricity & Magnetism",  1);
    this->addEdge( "Magnetic Field", "Electricity & Magnetism",1);
    this->addEdge("Lorentz Force", "Electricity & Magnetism",  1);
    
    
    this->addEdge("Magnetic Field", "Ampere's Law", 1);
    this->addEdge( "Ampere's Law", "Magnetic Field", 1);
    
    
    
    this->addEdge("Ampere's Law", "Biot-Savart Law", 1);
    this->addEdge("Biot-Savart Law", "Ampere's Law",  1);
    
    
    this->addEdge( "Biot-Savart Law", "Faraday's Law", 1);
    this->addEdge( "Faraday's Law", "Biot-Savart Law",  1);
    
    
    
    this->addEdge( "Lorentz Force", "Maxwell's Equations", 1);
    this->addEdge(  "Maxwell's Equations", "Lorentz Force", 1);
    
    this->addEdge("Couloumb's Law", "Electric Field", 1);
    this->addEdge("Electric Field", "Couloumb's Law",  1);
    this->addEdge("Electric Field", "Electric Charge",  1);
    this->addEdge("Couloumb's Law", "Electric Charge", 1);


    
    
    
    
    
    
    
    
    
}

Graph::~Graph()
{
}



void Graph::addVertex(string n, string _eqn1, string _eqn2){
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
        
        
        infoBlock *eqn1 = new infoBlock;
        infoBlock *eqn2 = new infoBlock;
        eqn1->equation = _eqn1;
        eqn2->equation = _eqn2;
        eqn1->next = eqn2;
        eqn2->next = nullptr;
        
        v.equations = eqn1;
        
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
            int valueTest =(vertices[i].adj.size());
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
    cout <<"============================================================" << endl;
    
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
        cout << endl;
    }
}

void Graph:: DFS(vertex * topic){
    topic->visited = true;
    for(int x = 0; x < topic->adj.size(); x++){
        if(!topic->adj[x].v->visited){
            cout << topic->adj[x].v->topic;
            DFS(topic->adj[x].v);
        }
    }
}

void Graph:: DFS_traversal(string _topic){
    
    
    vertex * searchVertex = search_Vertex(_topic);
    
    cout << "% vertex->name: " << searchVertex->topic << endl;
    
    DFS(searchVertex);
    
    
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

void  Graph:: DFS_iterrative(string _topic){
    
    //KEY you need to make sure the values are correct before you go down this path.
    for(int i=0; i<vertices.size(); i++){
        vertices[i].visited = false;
    }
    
    vertex * searchVertex = search_Vertex(_topic);
    searchVertex->visited =true;
    searchVertex->distance = 0;
    queue<vertex *> stack;
    
    stack.push(searchVertex);
    while(!stack.empty()){
        vertex * temp = stack.front();
        stack.pop();
        cout << temp->topic;
        for(int x= 0; x< temp->adj.size(); x++){
            if(!temp->adj[x].v->visited){
                temp->adj[x].v->visited = true;
                stack.push(temp->adj[x].v);
            }
            cout << " ";
        }
    }
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
            path.push_back(vert); //this is where its at.
            vert = vert->previous;
        }
        cout << "Shortist Pat &h" << endl;
        for (int i = 0; i < path.size(); i++) {
            if (i == path.size()-1)
                cout<<path[path.size()-1-i]->topic;
            else
                cout<<path[path.size()-1-i]->topic<<" -> ";
            
        }
        //        cout <<"============================================================" << endl;
        //        for (int j=0; j<path.size()-1; j++) {
        //            cout << path[path.size()-1-j]->equations->topicName << endl;
        //        }
        //        cout <<"============================================================" << endl;
        //
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



void Graph:: print_equations(){
    infoBlock *walker = nullptr;
    for(int i=0; i < vertices.size(); i++){
        
        walker = vertices[i].equations;
        
        while(walker!=nullptr){
            if(walker->equation == ""){
                break;
            }
            else{
                cout << walker->equation << endl;
            }
            walker = walker->next;
        }
        
        
    }
}














































