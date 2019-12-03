#include <vector>


class Triangle {
    public:
        Triangle(char const* filename){
            size = 5;
        }

        unsigned int size;
        std::vector<std::vector<unsigned>> data;
};
