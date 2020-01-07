#include "bipartiteMatching.h"

int main(){
    Graph graph("tutorien.txt", Graph::undirected);
    Graph matching = bipartiteMatching(graph);
    matching.print();
    return 0;
}
