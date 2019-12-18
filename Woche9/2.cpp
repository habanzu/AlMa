#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include "../Woche7/graph.h"

using namespace std;
typedef Graph::NodeId NodeId;

//modified dfs to return a path from start to end or an empty vector
vector<NodeId> findConnection(Graph & graph, NodeId start, NodeId end) 
{
    set<NodeId> visited;
    vector<NodeId> connection; //use it like a stack
    connection.push_back(start);
    visited.insert(start);
    NodeId current_node;
    while(connection.size() > 0) {
        current_node = connection.back();
        
        NodeId id;
        for(auto neighbor : graph.get_node(current_node).adjacent_nodes()){
            id = neighbor.id();
            if(id == end) {
                connection.push_back(id);
                return connection;
            } else if(visited.find(id) == visited.end()) {
                connection.push_back(id);
                visited.insert(id);
            }
        }
        if(current_node == connection.back()) {
            connection.pop_back();
        }

    }
    return connection;
}

void addMoreEdges(Graph & g, char const* filename) {
    fstream f(filename);
    if(f.is_open()) {
        int n1, n2;
        f >> n1; //just to get it out of the way
        while(f >> n1 && f >> n2) {
            
            g.add_edge(n1, n2);
        }
        f.close();
    } else {
        cout << "Could not open file." << endl;
    }
}

void testForContradiction(Graph & g, char const* filename) {
    fstream f(filename);
    if(f.is_open()) {
        NodeId n1, n2;
        f >> n1; //get the first line out of the way
        vector<NodeId> connection; 
        while(f >> n1 && f >> n2) {
            connection = findConnection(g, n1, n2);
            if(connection.empty()) { 
            }
            else {

                cout << "Das haut so aber nicht hin!" << endl
                << "Es gilt: " << connection.at(0);
                for(int i = 1; i < connection.size(); i++) {
                    cout << " = " << connection.at(i);
                }
                cout << "," << endl << "aber auch: " << n1 << " != " << n2 << endl; 
            }
        }
        f.close();
    } else {
        cout << "Could not open file." << endl;
    }
}

int main() 
{   
    Graph equality(100, Graph::undirected);
    addMoreEdges(equality, "gleichungen.txt");
    testForContradiction(equality, "ungleichungen.txt");

    

}