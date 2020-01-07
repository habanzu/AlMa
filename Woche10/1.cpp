#include "bipartiteMatching.h"
#include <iostream>

int main(){
    //Graph graph("simpleGraph.txt", Graph::undirected);
    Graph graph("tutorien.txt", Graph::undirected);
    vector<NodeId> matching = bipartiteMatching(graph);
    for(int i = 0; i < 100; i++){
        (matching[i] == -1) ?
            (std::cout << "Keine Kante im Matching für " << i << std::endl) :
            (std::cout << "Kante zwischen " << i << " und " << matching[i] << std::endl);

    }
    return 0;
}
