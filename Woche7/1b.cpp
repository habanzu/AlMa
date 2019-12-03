#include "graph.h"
#include <fstream>
#include <iostream>

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
    printNode(mygraph, 1);
    return 0;
}
