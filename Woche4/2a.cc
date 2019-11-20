#include <iostream>
#include <iomanip>

using std::endl;
using std::cout;
using std::setw;
using std::setprecision;
using std::scientific;

float an(float start, unsigned int n){
    if(n == 0){
        return start - 1;
    }
    float result = an(start, n -1);
    //std::cout << "Ergebnis = " << result << " = " << n -1 << " * an-1 - 1 " << endl;
    return n * result -1;
}

double an(double start, unsigned int n){
    if(n == 0){
        return start - 1;
    }
    return n * an(start, n -1) -1;
}

int main(){
    double e1 = 2.71828182845904523536028747135;
    float e2 = e1;
    int precision = 10;
    unsigned int n = 25;
    for(int i; i < 25; i++){
        cout << "n = " << setw(2) << i << ", Float Ergebnis: " << scientific << setprecision(precision) << an(e2,i) << ", Double Ergebnis " <<  setprecision(precision) << an(e1,i) << std::endl;
    }
    //std::cout << "Float Ergebnis: " << an(e2,n) << std::endl << "Double Ergebnis" <<
    //            an(e1,n) << std::endl;
}
