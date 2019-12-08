#include "map.h"
#include <iostream>

int main(){
    Map map("Graph8.txt", "xcoords.txt", "ycoords.txt");
    
    std::cout << "Kürzester Pfad" << std::endl;
    for(auto nodeid : map.shortestPath(1758, 584)){
        std::cout << nodeid << std::endl;
    }
}
