#include "map.h"
#include "pgm.h"
#include "drawline.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Map map("Graph8.txt", "xcoords.txt", "ycoords.txt");

    int number_of_nodes = 2331;
    unsigned int my_width = 8000;
    unsigned int my_height = my_width;
    vector<uint8_t> image(my_width*my_height);

    for(int i = 0; i < image.size(); i++) {
        image.at(i) = 255;
    }

    for(int i = 0; i < number_of_nodes; i++) {
        for(int ii = 0; ii < i; ii++) {
            for(auto n : map.get_node(i).adjacent_nodes()) {

                if(n.id() == ii) {
                    //cout << map.Coordinates.at(i).x <<" "<< map.Coordinates.at(i).y<<" "<< map.Coordinates.at(ii).x<< " "<< map.Coordinates.at(ii).y << endl;
                    draw_line(map.Coordinates.at(i).x*my_width/2, map.Coordinates.at(i).y*my_height/2, map.Coordinates.at(ii).x*my_width/2, map.Coordinates.at(ii).y*my_height/2, 7, 100, &image[0], my_width, my_height);
                }
            }
        }
    }



    int i = 1;
    vector<NodeId> shortest_path = map.shortestPath(1758, 584);
    while(i < shortest_path.size()) {
        draw_line(map.Coordinates.at(shortest_path.at(i-1)).x*my_width/2, map.Coordinates.at(shortest_path.at(i-1)).y*my_height/2, map.Coordinates.at(shortest_path.at(i)).x*my_width/2, map.Coordinates.at(shortest_path.at(i)).y*my_height/2, 20, 0, &image[0], my_width, my_height);
        i++;
    }

    createPGM(my_width, my_height, image);




}
