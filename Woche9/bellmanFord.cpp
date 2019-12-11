#include "bellmanFord.h"

typedef Graph::NodeId NodeId;

Graph bellmanFord(const Graph graph, const Graph::NodeId start){

    std::vector<double> l;
    std::vector<NodeId> p;


    const NodeId n = graph.num_nodes();


    Graph A = Graph(n,Graph::directed);
    l[start] = 0;
    p[start] = Graph::invalid_node;

    for (unsigned i = 1; i < n; ++i){
        for (auto e : )
    }

    return(A);
}
