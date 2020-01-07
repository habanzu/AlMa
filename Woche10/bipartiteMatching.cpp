#include "bipartiteMatching.h"
#include <algorithm>
#include <set>
#include <iostream>

typedef Graph::Neighbor Neighbor;
using std::vector;

struct DjikstraNode{
    NodeId nodeid;
    mutable double l;
    mutable NodeId p;

    // Zum verlgeichen von DjikstraNode brauche ich einen Funktor, den ich an das Set übergebe
    // Haesslicher technischer Boilerplate Code -.-
    struct CompareDjikstraNode{
        bool operator()(const DjikstraNode& x, const DjikstraNode& y) const {
            return x.nodeid < y.nodeid;
        }
    };

    static bool cmpLength(const DjikstraNode &a, const DjikstraNode &b){
        return a.l < b.l;
    };

};

std::vector<NodeId> shortestPath(Graph graph, NodeId start, NodeId destination){
    // Notation wie im Buch von Hougardy
    std::set<DjikstraNode, DjikstraNode::CompareDjikstraNode> R;
    std::set<DjikstraNode, DjikstraNode::CompareDjikstraNode> Q;

    Q.insert(DjikstraNode{start, 0, -1});
    while(!Q.empty()){
        DjikstraNode v = *(std::min_element(Q.begin(),Q.end(), DjikstraNode::cmpLength));
        Q.erase(v);
        R.insert(v);
        for(auto e : graph.get_node(v.nodeid).adjacent_nodes()){
            if(R.find(DjikstraNode{e.id(),0,0}) != R.end())
                continue;
            auto w = Q.find(DjikstraNode{e.id(),0,0});

            if(w == Q.end()){
                Q.insert(DjikstraNode{e.id(), v.l + e.edge_weight(), v.nodeid});
                continue;
            }
            if (v.l + e.edge_weight() < w->l){
                w->l = v.l + e.edge_weight();
                w->p = v.nodeid;
            }

        }

    }

    // Erstelle den Ausgabepfad nach der Terminierung von Djikstra
    auto reachable = R.find(DjikstraNode{destination, 0, 0});
    if (reachable == R.end())
        return vector<NodeId>{};
    auto v = *reachable;
    std::vector<NodeId> path;

    while(v.p != -1){
        path.insert(path.begin(), v.nodeid);
        v = *R.find(DjikstraNode{v.p, 0, 0});
    }
    path.insert(path.begin(), start);
    return path;
};

struct SearchNode{
    NodeId id;
    int operator() (Neighbor neighbor){
        return neighbor.id() == this->id;
    }
};

Graph bipartiteMatching(Graph graph){
    NodeId nodes = graph.num_nodes();
    NodeId bipartition = 3;
    Graph M = Graph(nodes, Graph::undirected);
    Graph H = Graph(nodes + 2, Graph::directed);
    NodeId s = nodes;
    NodeId t = nodes + 1;
    while (1){
        for(NodeId i = 0; i < bipartition; i++){
            H.add_edge(s, i);
            H.add_edge(i + bipartition, t);
        }
        for(NodeId i = 0; i < bipartition; ++i){
            for(Neighbor node : graph.get_node(i).adjacent_nodes()){
                vector<Neighbor> neighbors = M.get_node(i).adjacent_nodes();
                if(std::any_of(neighbors.begin(), neighbors.end(), SearchNode{node.id()})){
                    H.add_edge(node.id(), i);
                } else {
                    H.add_edge(i, node.id());
                }
            }
        }
        auto path = shortestPath(H, s, t);
        if (path.empty()){
            std::cout << "Pfad ist leer \n";
            return M;
        } else {
            std::cout << "Happy \n";
        }
    }
}
