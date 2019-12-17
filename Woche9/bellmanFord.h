#include "../Woche7/graph.h"
#include <queue>
#include <vector>

typedef Graph::NodeId NodeId;
typedef Graph::Neighbor Neighbor;
using std::vector;
using std::queue;

Graph bellmanFord(Graph graph, Graph::NodeId start);
