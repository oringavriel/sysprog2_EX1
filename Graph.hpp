#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Graph
    {
    private:
        vector<vector<int>> graph;
        int verNum;
        int edgeNum;
        bool isDirected;
        bool isWeighed;
    public:
        Graph(); // constructor
        void loadGraph(const vector<vector<int>> &gr); // passing by reference
        void printGraph();
        vector<vector<int>> getGraph();
        int getVerNum();
        int getEdgeNum();
        bool getIsDirected();
        bool getIsWeighed();   
    } ;
}
#endif