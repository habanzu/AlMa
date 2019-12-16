#include <iostream>
#include <fstream>

#include <vector>
#include <algorithm>
#include "../Woche7/graph.h"

using namespace std;
typedef Graph::NodeId NodeId;

void findConnection(Graph & graph, vector<NodeId> & connection, NodeId start, NodeId end) //modified dfs
{
    vector<NodeId> visited;
    //vector<NodeId> connection; //use it like a stack
    connection.push_back(start);
    visited.push_back(start);
    NodeId current_node;
    while(! connection.empty()){
        current_node = connection.back();
        
        NodeId id;
        for(auto neighbor : graph.get_node(current_node).adjacent_nodes()){
            id = neighbor.id();
            if(id == end) {
                connection.push_back(id);
                return;
            } else if(find(visited.begin(), visited.end(), id) == visited.end()) {
                connection.push_back(id);
                visited.push_back(id);

            } else {
                connection.pop_back();
            }
        }
    }
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
            connection.clear();
            findConnection(g, connection, n1, n2);
            if(! connection.empty()) {

                cout << "Das haut so aber nicht hin!" << endl
                << "Es gilt: " << connection.at(0);
                for(int i = 1; i < connection.size(); i++) {
                    cout << " = " << connection.at(i);
                }
                cout << " ," << endl << "aber auch: " << n1 << " != " << n2 << endl; 
                f.close();
                return;               
            }
        }

        cout << "Keine Widersprüche gefunden." << endl;
        f.close();
    } else {
        cout << "Could not open file." << endl;
    }
}

int main() 
{   
    Graph equality(100, Graph::undirected);
    addMoreEdges(equality, "gleichungen.txt");
    vector<NodeId> connection;
    findConnection(equality, connection, 1, 10);
    //testForContradiction(equality, "ungleichungen.txt");
}