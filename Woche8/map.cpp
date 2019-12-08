#include "map.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

using std::cout;
using std::endl;

std::vector<NodeId> Map::shortestPath(NodeId start, NodeId destination){
    // Notation wie im Buch von Hougardy
    std::set<DjikstraNode, DjikstraNode::CompareDjikstraNode> R;
    std::set<DjikstraNode, DjikstraNode::CompareDjikstraNode> Q;

    Q.insert(DjikstraNode{start, 0, -1});
    while(not Q.empty()){
        DjikstraNode v = *(std::min_element(Q.begin(),Q.end(), DjikstraNode::cmpLength));
        Q.erase(v);
        R.insert(v);
        for(auto e : this->get_node(v.nodeid).adjacent_nodes()){
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
    auto v = *R.find(DjikstraNode{destination, 0, 0});
    std::vector<NodeId> path;

    while(v.p != -1){
        path.insert(path.begin(), v.nodeid);
        v = *R.find(DjikstraNode{v.p, 0, 0});
    }
    path.insert(path.begin(), start);
    return path;
};

Map::Map(char const* fileGraph, char const* fileXCoords, char const* fileYCoords) : Graph(fileGraph, Graph::undirected){

    // Open and check File
    std::ifstream XFile(fileXCoords);
    std::ifstream YFile(fileYCoords);
    if (not XFile || not YFile) {
         throw std::runtime_error("Cannot open file.");
    }
    std::string xline, yline;
    double xcoord, ycoord;

    for(int nodeid = 0; nodeid <= this->num_nodes(); nodeid++){
        // Read from files
        std::getline(XFile, xline);
        std::getline(YFile, yline);
        std::stringstream ssx(xline);
        std::stringstream ssy(yline);
        ssx >> xcoord; ssy >> ycoord;

        // Create Point and add it to coordinates in Map
        Point newPoint = {nodeid, xcoord, ycoord};
        this->Coordinates.push_back(newPoint);
    }

}
