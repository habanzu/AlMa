#include "map.h"
#include "pgm.h"
#include "drawline.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    Map map("Graph8.txt", "xcoords.txt", "ycoords.txt");

    int number_of_nodes = 2331;
    unsigned int my_width = 20;
    unsigned int my_height = 20;
    vector<uint8_t> image(my_width*my_height);

    for(int i = 0; i < my_width*my_height; i++) {
        image.at(i) = 255;
    }

    for(int i = 0; i < number_of_nodes; i++) {
        for(int ii = 0; ii < i; ii++) {
            for(auto n : map.get_node(i).adjacent_nodes()) {

                if(n.id() == ii) {
                    //cout << map.Coordinates.at(i).x <<" "<< map.Coordinates.at(i).y<<" "<< map.Coordinates.at(ii).x<< " "<< map.Coordinates.at(ii).y << endl;
                    draw_line(map.Coordinates.at(i).x , map.Coordinates.at(i).y, map.Coordinates.at(ii).x, map.Coordinates.at(ii).y, 3, 0, image, my_width, my_height);
                }
            }
        }
    }

    for(auto i : image) {
        cout << (int) i << endl;
    }

    createPGM(my_width, my_height, image);




}
