#include "bellmanFord.h"
#include <cmath>

Graph transformGraphToLog(const Graph graph);


int main(){
    Graph graph("waren.txt", Graph::directed);
    Graph tree = bellmanFord(transformGraphToLog(graph), 1);
    //tree.print();
    return 0;
}

Graph transformGraphToLog(const Graph graph){
    const auto n = graph.num_nodes();
    Graph A(n, Graph::directed);
    for(unsigned i = 0; i < n; ++i){
        for(auto e : graph.get_node(i).adjacent_nodes()){
            A.add_edge(i, e.id(), std::log(e.edge_weight()));
        }
    }
    return A;
}
