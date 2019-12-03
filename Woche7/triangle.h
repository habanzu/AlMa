#include <vector>


class Triangle {
    public:
        Triangle(char const* filename);

        const unsigned int size;
        std::vector<std::vector<unsigned>> data;
};
