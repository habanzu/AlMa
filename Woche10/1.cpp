#include "bipartiteMatching.h"

int main(){
    //Graph graph("tutorien.txt", Graph::undirected);
    Graph graph("simpleGraph.txt", Graph::undirected);
    //graph.print();
    Graph matching = bipartiteMatching(graph);
    matching.print();
    return 0;
}
