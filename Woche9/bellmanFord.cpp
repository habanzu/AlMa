#include "bellmanFord.h"


Graph bellmanFord(const Graph graph, const NodeId start){

    std::vector<double> l;
    std::vector<NodeId> p;


    const NodeId n = graph.num_nodes();


    Graph A = Graph(n,Graph::directed);
    l[start] = 0;
    p[start] = Graph::invalid_node;

    for (unsigned i = 1; i < n; ++i){
        for (auto e : bfsEdges(graph, start)){
            
        }
    }

    return(A);
}

vector<Neighbor> bfsEdges(Graph graph, NodeId id){
    vector<NodeId> visited;
    queue<NodeId> unvisited;
    vector<Neighbor> neighbors;
    vector<Neighbor> tmp;
    unvisited.push(id);

    while(unvisited.empty() == 0){
        id = unvisited.front();
        visited.push_back(id);
        unvisited.pop();
        tmp = graph.get_node(id).adjacent_nodes();
        for(auto neighbor : tmp){
            neighbors.push_back(neighbor);
            id = neighbor.id();
            if(!(std::find(visited.begin(), visited.end(), id) != visited.end()))
                unvisited.push(id);
        }
    }

    return neighbors;
}
