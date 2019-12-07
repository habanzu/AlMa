#include "map.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>

std::vector<NodeId> Map::shortestPath(NodeId start){
    std::vector<NodeId> path;

    // Notation wie im Buch von Hougardy
    std::set<DjikstraNode, DjikstraNode::CompareDjikstraNode> R;
    std::set<DjikstraNode, DjikstraNode::CompareDjikstraNode> Q;

    //Q.insert(DjikstraNode{start, 0, -1});
    while(not Q.empty()){

    }

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
