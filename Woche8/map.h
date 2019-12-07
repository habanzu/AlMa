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
        NodeId nodeid;
        double x;
        double y;
    };

    // Vektor, der alle Punkte mit ihren Koordinaten enthält
    std::vector<Point> Coordinates;

    //Gibt einen Vektor zurück, der die NodeIds des kürzesten Pfades enthält
    std::vector<NodeId> shortestPath(NodeId start);
private:
    // Die Private Datenstrukturen brauche ich intern, die am bestein einfach nicht verwenden
    struct DjikstraNode{
        NodeId nodeid;
        double l;
        NodeId p;

        // Zum verlgeichen von DjikstraNode brauche ich einen Funktor, den ich an das Set übergebe
        // Haesslicher technischer Boilerplate Code -.-
        struct CompareDjikstraNode{
            bool operator()(const DjikstraNode& x, const DjikstraNode& y) const {
                return x.nodeid < y.nodeid;
            }
        };

    };



};
