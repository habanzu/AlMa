#include "../Woche8/graph.h"
#include <vector>

typedef Graph::NodeId NodeId;

// It's required, that the first 100 nodes are one bipartition.
Graph bipartiteMatching(Graph graph);
std::vector<NodeId> shortestPath(Graph graph, NodeId start, NodeId destination);
