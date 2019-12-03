#include "graph.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef Graph::NodeId NodeId;
using std::vector;
using std::queue;

vector<NodeId> bfs(Graph graph, NodeId id){
    vector<NodeId> visited;
    queue<NodeId> unvisited;
    vector<Graph::Neighbor> tmp;
    unvisited.push(id);

    while(unvisited.empty() == 0){
        id = unvisited.front();
        visited.push_back(id);
        unvisited.pop();
        tmp = graph.get_node(id).adjacent_nodes();
        for(auto neighbor : tmp){
            id = neighbor.id();
            if(!(std::find(visited.begin(), visited.end(), id) != visited.end()))
                unvisited.push(id);
        }
    }

    return visited;
}

void printNode(Graph graph, Graph::NodeId nodeId){
    Graph::Node node = graph.get_node(nodeId);
    std::cout << "The following edges are ";
    if (graph.dirtype == Graph::directed) {
        std::cout << "leaving";
    } else {
        std::cout << "incident to";
    }
    std::cout << " vertex " << nodeId << ":\n";
    for (auto neighbor: node.adjacent_nodes()) {
        std::cout << nodeId << " - " << neighbor.id()
                  << " weight = " << neighbor.edge_weight() << "\n";
    }
}

int main(){
    Graph mygraph("Graph.txt", Graph::undirected);
    for(auto node: bfs(mygraph, 1)){
        std::cout << node << std::endl;
    }
    return 0;
}
