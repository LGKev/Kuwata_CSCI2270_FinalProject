READ ME
=========================================================================================================================================================================



Project Summary:
=========================================================================================================================================================================
	This project is focusing on the graph data structure to store topics from Electricity and Magnetism. It also uses a linked list to store relevant equations. This program could be useful for understaning the relationships between many topics required to solve a E & M problem. 

How To Run:
=========================================================================================================================================================================
	Example graph object: test
	
1) Print all equations: test.print_equations
	input: - 				
	output: prints all equations stored

2) Add a vertice to graph:     test.addVertex(std::string topic, string _eqn1, string _eqn2); 
	input: a topic name, and 2 relevant equations   
	output: none

3) Add an Edge to graph    test.addEdge(std::string v1, std::string v2, int weight); 
	input: name two valid strings of vertices you want connected, and weight (= 1)
	output: none

4) Print Graph:    test.printGraph();
	input: -
	output: prints the edges of the graph

5) Find Dijkstra Shortest Path: test.Dijkstra(string sourceVertex, string destinationVertex)
	input: start vertex name, end vertex name
	output: shortest path with a printout of the shortest path

6) BFS_Traversal: test.BFS_traversal()
	input: -
	output: prints the graph in the Breadth First Search Pattern

7) DFS_traversal: test.DFS_traversal()
	input: -
	output: used for DFS to help traverse recursively

8) Depth First Search:  test.DFS();
	input: vertex topic
	output: print out of the DFS search pattern

9) Depth First Search non Recursively: test.DFS_iterrative
	input: vertex
	output: printout of the DFS search pattern

Dependencies:
=========================================================================================================================================================================
No third party dependencies. Standard Library. C11

System Requirements
=========================================================================================================================================================================
Tested on Mac. Should work on others due to no dependencies.

=========================================================================================================================================================================

██╗  ██╗███████╗██╗   ██╗██╗███╗   ██╗    ██╗  ██╗██╗   ██╗██╗    ██╗ █████╗ ████████╗ █████╗ 
██║ ██╔╝██╔════╝██║   ██║██║████╗  ██║    ██║ ██╔╝██║   ██║██║    ██║██╔══██╗╚══██╔══╝██╔══██╗
█████╔╝ █████╗  ██║   ██║██║██╔██╗ ██║    █████╔╝ ██║   ██║██║ █╗ ██║███████║   ██║   ███████║
██╔═██╗ ██╔══╝  ╚██╗ ██╔╝██║██║╚██╗██║    ██╔═██╗ ██║   ██║██║███╗██║██╔══██║   ██║   ██╔══██║
██║  ██╗███████╗ ╚████╔╝ ██║██║ ╚████║    ██║  ██╗╚██████╔╝╚███╔███╔╝██║  ██║   ██║   ██║  ██║
╚═╝  ╚═╝╚══════╝  ╚═══╝  ╚═╝╚═╝  ╚═══╝    ╚═╝  ╚═╝ ╚═════╝  ╚══╝╚══╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝
                                                                                              
(Kevin Kuwata)

=========================================================================================================================================================================
Open Issues/ Bugs
- printout for the breadth first search has poor formating, it is correct but could be presented better

=========================================================================================================================================================================
