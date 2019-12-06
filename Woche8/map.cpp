#include "map.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

Map::Map(char const* fileGraph, char const* fileXCoords, char const* fileYCoords) : Graph(fileGraph, Graph::undirected){
    std::ifstream XFile(fileXCoords);
    std::ifstream YFile(fileYCoords);
    if (not XFile || not YFile) {
         throw std::runtime_error("Cannot open file.");
    }

    std::string xline, yline;
    double xcoord, ycoord;
    for(int nodeid = 0; nodeid <= this->num_nodes(); nodeid++){
        std::getline(XFile, xline);
        std::getline(YFile, yline);
        std::stringstream ssx(xline);
        std::stringstream ssy(yline);
        ssx >> xcoord; ssy >> ycoord;
        Point newPoint = {nodeid, xcoord, ycoord};
        this->Coordinates.push_back(newPoint);
        std:: cout << "NodeId " << nodeid << ", X: " << xcoord << ", Y: " << ycoord << std::endl;
    }

}
