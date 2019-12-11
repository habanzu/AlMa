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
        double x; //sollte zwischen 0 und 2 liegen
        double y; //(0,0) ist unten links
    };

    // Vektor, der alle Punkte mit ihren Koordinaten enthält, mit 0 =< x,y =< 2
    std::vector<Point> Coordinates;

    //Gibt einen Vektor zurück, der die NodeIds des kürzesten Pfades enthält
    std::vector<NodeId> shortestPath(NodeId start, NodeId destination);

    //Erstellt ein Bild der Karte in Form eines Vektors, der mit createPGM in eine PGM Datei geschrieben werden kann
    std::vector<uint8_t> draw_map(unsigned int size);

    //zeichnet einen Weg auf dere Karte
    void draw_path(std::vector<uint8_t> image, std::vector<NodeId> path, unsigned int size);

    //zeichnet eine Kante auf der Karte
    void draw_edge(Point point1, Point point2, double thickness, uint8_t color, std::vector<uint8_t> image, unsigned int size);

private:
    // Die Private Datenstrukturen brauche ich intern, die am bestein einfach nicht verwenden
    struct DjikstraNode{
        NodeId nodeid;
        mutable double l;
        mutable NodeId p;

        // Zum verlgeichen von DjikstraNode brauche ich einen Funktor, den ich an das Set übergebe
        // Haesslicher technischer Boilerplate Code -.-
        struct CompareDjikstraNode{
            bool operator()(const DjikstraNode& x, const DjikstraNode& y) const {
                return x.nodeid < y.nodeid;
            }
        };

        static bool cmpLength(const DjikstraNode &a, const DjikstraNode &b){
            return a.l < b.l;
        };

    };

};
