#include "graph.h"
#include <iostream>
#include <vector>

typedef Graph::NodeId NodeId;

class Map : public Graph{
public:
    Map(char const* fileGraph, char const* fileXCoords, char const* fileYCoords);

    // Die Node Klasse zu modifizieren ist leider serh aufwendig, von daher erstelle ich eine neue Datenstruktur
    struct Point {
    public:
        Graph::NodeId nodeid;
        double x;
        double y;
    };

    // Vektor, der alle Punkte mit ihren Koordinaten enthält
    std::vector<Point> Coordinates;

    //Gibt einen Vektor zurück, der die NodeIds des kürzesten Pfades enthält
    std::vector<NodeId> shortestPath();
private:
    struct DjikstraNode{
        
    }

};
