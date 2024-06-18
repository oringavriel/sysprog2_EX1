#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
using namespace std;

TEST_CASE("test graph functions"){
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK_FALSE(g.getIsWeighed());
    CHECK_FALSE(g.getIsDirected());
}

TEST_CASE("invalid graph: diagonal line not equal to 0"){
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {1 ,0, 0, 0}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("invalid graph:not square matrix"){
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 1, 0},
        {1, 1, 0},
        {1 ,0, 0}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("empty graph"){
    ariel::Graph g;
    vector<vector<int>> graph = {};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite");
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 4) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "No cycle detected");
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph doesn't contain a negative cycle");
}

TEST_CASE("0's graph"){
    ariel::Graph g;
    vector<vector<int>> graph = 
    {{0,0}, 
    {0,0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={1}");
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 4) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "No cycle detected");
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph doesn't contain a negative cycle");
}

TEST_CASE("Test throw exception in shortest path between enexistant vertices")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}

TEST_CASE("directed unweighed graph"){
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 0},
        {1 ,0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 4) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->0");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph doesn't contain a negative cycle");

    vector<vector<int>> graph1 = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0 ,0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->2->3");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "No cycle detected");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph doesn't contain a negative cycle");
}

TEST_CASE("directed weighed graph"){
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 2, 0, 0},
        {0, 0, -3, 0},
        {0, 0, 0, 4},
        {0 ,-5, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 3) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "1->2->3->1");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains a negative cycle");

    vector<vector<int>> graph1 = {
        {0, 3, 6, 0},
        {0, 0, 2, 7},
        {0, 0, 0, 4},
        {1 ,0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->2->3->0");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph doesn't contain a negative cycle");
}

TEST_CASE("undirected unweighed graph"){
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1 ,0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->2->3->0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph doesn't contain a negative cycle");

    vector<vector<int>> graph1 = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 1},
        {1, 0 ,1, 0, 0},
        {0, 0, 1, 0, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 3, 1) == "3->0->1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->2->3->0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3, 4}");
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph doesn't contain a negative cycle");
}

TEST_CASE("undirected weighed graph"){
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0 , 0},
        {1, 0, 2, 1, 3, 0},
        {0, 2, 0, 0, 0, 0},
        {1, 1, 0, 0, 2, 0},
       {0, 3, 0, 2, 0, 1},
       {0, 0, 0, 0, 1, 0} };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 5) == "0->3->4->5");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->3->0");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph doesn't contain a negative cycle");

     vector<vector<int>> graph1 = {
        {0, 2, -5},
        {2, 0, 3},
        {-5, 3, 0} };
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->2->0");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains a negative cycle");
}

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "No cycle detected");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->2->0");
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}