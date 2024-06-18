# System programming- assignment 1
The project presents an implementation of a graph and various functions on it in c++.
There are two main classes – Graph and Algorithms and a test class.
## Graph 
The class present the graph and its fields.
 The graph is presented by 2d adjacency matrix.
 It has the private fields:  verNum- number of vertices, edgeNum-number of edges, isDirected -indicates if the graph is directed or not and isWeighed- indicates if the graph is weighed or not.
The class includes the public methods:
1.	Graph() - default  constructor.
2.	void loadGraph(const vector<vector<int>>& gr) – a method that gets a 2d adjacency matrix and loads it into the graph object. The method also checks if the graph is directed by checking symmetry, if it's weighed by finding an edge bigger than 1 and if it's invalid by checking if the diagonal line is different than 0.
It also defines the number of edges.
3.	void printGraph() – a print method that prints the number of edges and vertices of the graph.
4.	vector<vector<int>> getGraph() – a method that returns the graph .
5.	int getVerNum() – a method that returns the number of vertices of the graph.
6.	int getEdgeNum() – a method that returns the number of edges of the graph.
7.	bool getIsDirected() – a method that returns true/false if the graph is directed or not.
8.	bool getIsWeighed() – a method that returns true/false if the graph is weighed or not.
## Algorithms
The class presents public static algorithms that can be implemented on the graph:
1.	static bool isConnected(Graph &gr) -the function gets a graph and returns true if it's connected or false if it isn't. the method uses the BFS algorithm.
2.	static string shortestPath(Graph &gr,int start, int end) – the function gets a graph and a starting and ending point, and finds the shortest path between them. If there isn't a path the function returns -1. 
The function is divided into 2 cases : 
-shortestPathWeighed (Graph &gr,int start, int end)- if the graph is weighed it finds the shortest path using Bellman-Ford algorithm. 
-shortestPathUnweighed (Graph &gr,int start, int end)- if the graph is unweighed it finds the shortest path using BFS algorithm. 
It returns the shortest path using a helper function-
string printway(vector<size_t> &way).
3.	static string isContainsCycle(Graph &gr) -  the function gets the graph and checks whether it contains a cycle . It's divided it into 2 cases using helper functions for directed and undirected graph and checks if the graph contains a cycle using DFS algorithm. If a cycle is detected it returns it using a helper function- string printCycle(const vector<size_t>& way) or else it returns there isn't a cycle detected.  
4.	static string isBipartite(Graph &gr) - the function gets a graph and returns if it's bipartite or not by dividing it into 2 colors using the BFS algorithm.  If the graph has 2 neighbors with the same color then it's not bipartite and the function will return 0. Otherwise, it will return the partition.
5.	static string negativeCycle(Graph &gr) - the function gets a graph and returns if it has a negative cycle by using Bellman-Ford algorithm. The function goes over the vertices v-1 times (v- number of vertices) and does the "relax" process. If the function is able to do "relax" in the v'th time then the graph has negative cycle.

