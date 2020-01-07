#include "../Woche8/graph.h"
#include <vector>

typedef Graph::NodeId NodeId;
using std::vector;

// It's required, that the first 100 nodes are one bipartition.
vector<NodeId> bipartiteMatching(Graph graph);
vector<NodeId> shortestPath(Graph graph, NodeId start, NodeId destination);
