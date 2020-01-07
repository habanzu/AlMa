#include "bipartiteMatching.h"
#include <algorithm>

typedef Graph::NodeId NodeId;
typedef Graph::Neighbor Neighbor;
using std::vector;

Graph bipartiteMatching(Graph graph){
    NodeId nodes = graph.num_nodes();
    NodeId bipartition = 100;
    Graph M = Graph(nodes, Graph::undirected);
    Graph H = Graph(nodes + 2, Graph::directed);
    Graph::NodeId s = nodes + 1;
    Graph::NodeId t = nodes + 2;
    while (1){
        for(NodeId i = 0; i < bipartition; i++){
            H.add_edge(s, i);
            H.add_edge(i + 100, t);
        }
        for(NodeId i = 0; i < nodes; i++){
            for(Neighbor node : graph.get_node(i).adjacent_nodes()){
                vector<Neighbor> neighbors = M.get_node(i).adjacent_nodes();
                for(auto neighbor : neighbors){
                    if(neighbor.id() == node.id())
                        H.add_edge(node.id(), i);
                    else
                        H.add_edge(i, node.id());
                }
            }
        }
        // Hier mit Djikstra einen Pfad findne
    }
    return Graph(4, Graph::undirected);
}
