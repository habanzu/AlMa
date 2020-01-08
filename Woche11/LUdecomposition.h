#include <vector>

using std::vector;

class LUdecomposition{
public:
    LUdecomposition(vector<double> Ab, unsigned n);
    vector<double> Ab;
    unsigned n;

    void LUdecomp();
    unsigned columnPivotSearch(int j);
    void print();

};
