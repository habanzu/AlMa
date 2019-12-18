#include "bellmanFord.h"


Graph bellmanFord(const Graph graph, const NodeId start){
    const NodeId n = graph.num_nodes();

    std::vector<double> l(n, std::numeric_limits<double>::infinity());
    std::vector<NodeId> p(n, -1);




    Graph A = Graph(n,Graph::directed);
    l[start] = 0;
    p[start] = Graph::invalid_node;

    for (unsigned i = 1; i < n; ++i){
        for (unsigned j = 0; j < n; ++j){
            for( auto e: graph.get_node(j).adjacent_nodes()){
                if (l[j] + e.edge_weight() < l[e.id()]){
                    l[e.id()] = l[j] + e.edge_weight();
                    p[e.id()] = j;
                    if(circleCheck(p, e.id(), start)){
                        std::cout << "Der Graph enthält einen Kreis mit negativen Kanten" << std::endl;
                        return Graph(0, Graph::directed);
                    }
                }
            }
        }
    }

    for (unsigned i = 0; i < n; ++i){
        if (i != start){
            if (p[i] == -1) continue;
            A.add_edge(p[i], i, l[i] - l[p[i]]);
        }
    }

    return(A);
}

int circleCheck(const vector<NodeId> p, const NodeId end, const NodeId root){
    auto x = p[end];
    while(x != root){
        x = p[x];
        if (x == end) return 1;
    }
    return 0;
}
