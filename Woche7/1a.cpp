#include "graph.h"
#include <fstream>
#include <iostream>

int main(){
    Graph mygraph("Graph.txt", Graph::undirected);
    mygraph.print();
    return 0;
}
