#include "bipartiteMatching.h"

int main(){
    Graph graph("tutorien.txt", Graph::undirected);
    //graph.print();
    Graph matching = bipartiteMatching(graph);
    //matching.print();
    return 0;
}
