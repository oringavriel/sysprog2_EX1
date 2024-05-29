#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
using namespace ariel;

Graph::Graph(){
    this->edgeNum=0;
    this->verNum=0;
    this->isDirected=false;
    this->isWeighed=false;
}
void Graph::loadGraph(vector<vector<int>> gr) {
        this->graph=gr;
        this->verNum=gr.size();
        this->isDirected=false;
        this->isWeighed=false;
        int count=0;
        if (graph[0].size()!= graph.size()) { //prints an error if the graph is not square
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
        for (size_t i=0; i<gr.size(); i++){
                for (size_t j=0; j<gr.size(); j++){
                        if (gr[i][j]>1) { // if one of the numbers in the graph is bigger than 1 then the graph is weighed
                                this->isWeighed=true;
                        }
                        if (gr[i][j]!=gr[j][i]) { // check if the graph is symetric (symetric = undirected)
                                this->isDirected=true;
                        }
                        if (gr[i][j]!=0) { //count edges
                                count++;
                        }
                }
        }     
        if (this->isDirected == true){
             this->edgeNum=count;   
        }
        else{
             this->edgeNum= count/2;   // if the graph is not directed the we need to divide the number of edges by 2
        }  
}
void Graph:: printGraph(){
        cout<< "Graph with " << this->verNum<< " vertices and " << this->edgeNum<<" edges."<< endl;
}
vector<vector<int>> Graph:: getGraph() {
        return this->graph;
}
int Graph:: getVerNum(){
        return this->verNum;
}
int Graph::getEdgeNum(){
        return this->edgeNum;
}
bool Graph::getIsDirected(){
        return this->isDirected;
}
bool Graph::getIsWeighed(){
        return this->isWeighed;
}
