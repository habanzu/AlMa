#include <vector>
#include <fstream>


class Triangle {
    public:
        Triangle(char const* filename, unsigned size){
            //std::ifstream file(filename);
            //size = 5;
        }

        unsigned int size;
        std::vector<std::vector<unsigned> > data;
};
