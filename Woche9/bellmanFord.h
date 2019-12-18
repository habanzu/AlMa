#include "../Woche7/graph.h"
#include <queue>
#include <vector>

typedef Graph::NodeId NodeId;
typedef Graph::Neighbor Neighbor;
using std::vector;
using std::queue;

Graph bellmanFord(Graph graph, NodeId start);
int circleCheck(vector<NodeId>, NodeId start, NodeId root);
void printCircle(const vector<NodeId> p, const NodeId end);
