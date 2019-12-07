#include "map.h"
#include <iostream>

int main(){
    //Map map("smallGraph.txt", "xcoords.txt", "ycoords.txt");
    Map map("smallGraph.txt", "xcoords.txt", "ycoords.txt");
    std::cout << "Kürzester Pfad" << std::endl;
    for(auto nodeid : map.shortestPath(0, 1)){
        std::cout << nodeid << std::endl;
    }
}
