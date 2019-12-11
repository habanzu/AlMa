#include "bellmanFord.h"

int main(){
    Graph graph("../Woche7/Graph.txt", Graph::undirected);
    Graph tree = bellmanFord(graph, 0);
    tree.print();
    return 0;
}
