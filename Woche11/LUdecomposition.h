#include <vector>

using std::vector;

class LUdecomposition{
public:
    LUdecomposition(vector<double> Ab, unsigned n);
    vector<double> Ab;
    const unsigned n;

    void LUdecomp();
    int columnPivotSearch(int j);
    void changeColumn(unsigned i1, unsigned i2);
    void subtractRows(unsigned row);
    void print();
};
