#include "map.h"
#include "pgm.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Map map("Graph8.txt", "xcoords.txt", "ycoords.txt");
    unsigned int size = 1000;
    vector<uint8_t> image = map.draw_map(size);

    cout << image.size();

    map.draw_path(image, map.shortestPath(200, 50), size);

    /*for(auto i : image) {
        cout << (int) i;
    }*/
    createPGM(size, size, image);

    cout << endl;


}
