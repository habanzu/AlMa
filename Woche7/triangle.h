#include <vector>


class Triangle {
    public:
        Triangle(char const* filename, unsigned size);

        unsigned int size;
        std::vector<std::vector<unsigned> > data;
};
