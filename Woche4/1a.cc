#include <cmath>
#include <iostream>

using std::cout;
using std::endl;

double inv(double y){
    return pow(y/3, 3);
}

double binary_approx(double a, double epsilon){
    double y_max = 3*(a+1);
    double y_min = 0;
    double y, x;
    do {
        y = (y_max + y_min)/2;
        x = inv(y);
        if(x >= a)
            y_max = y;
        else
            y_min = y;
    }
    while ((abs(x -a)) > epsilon);
    return y;
}

int main(){
    double a = 27;
    double epsilon = 1e-2;
    cout << binary_approx(a, epsilon) << endl;
}
