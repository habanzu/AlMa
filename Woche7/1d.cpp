#include "graph.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef Graph::NodeId NodeId;
using std::vector;
using std::queue;
using std::cout;
using std::endl;

vector<NodeId> bfs(Graph graph, NodeId id){
    vector<NodeId> visited;
    queue<NodeId> unvisited;
    vector<Graph::Neighbor> tmp;
    unvisited.push(id);

    while(unvisited.empty() == 0){
        id = unvisited.front();
        visited.push_back(id);
        unvisited.pop();

        for(auto neighbor : graph.get_node(id).adjacent_nodes()){
            id = neighbor.id();
            if(!(std::find(visited.begin(), visited.end(), id) != visited.end()))
                unvisited.push(id);
        }
    }

    return visited;
}

vector<vector<NodeId>> components(Graph graph){
    unsigned amount = graph.num_nodes();
    vector<vector<NodeId>> components;
    int found = 0;

    for(NodeId i =0; i < amount; ++i){
        found = 0;
        for(auto component : components){
            if(std::find(component.begin(), component.end(), i) != component.end()){
                found = 1;
                break;
            }
        }
        if (found == 0){
            auto component = bfs(graph, i);
            std::sort(component.begin(), component.end());
            components.push_back(component);
        }
    }
    return components;
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

void printComponents(Graph graph){
    int i = 1;
    for(auto component : components(graph)){
        cout << i << ".te Komponente: " << endl;
            for(auto node : component){
                cout << node << ", ";
            }
        cout << endl << endl;
        ++i;
    }
}

int main(){
    Graph graph("Graph.txt", Graph::undirected);
    printComponents(graph);
    return 0;
}
