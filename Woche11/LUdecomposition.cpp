#include "LUdecomposition.h"
#include <cmath>
#include <iostream>

using std::cout; using std::endl;

LUdecomposition::LUdecomposition(vector<double> Ab, unsigned n){
    this->Ab = Ab;
    this->n = n;
}

void LUdecomposition::LUdecomp(){
    for(int i = 0; i < n; ++i){

    }
}

void LUdecomposition::print(){
    for(unsigned i = 0; i < n; ++i){
        cout << "(";
        for(unsigned j = 0; j < n; ++j){
            cout << Ab[(n+1)*i + j] << " ";
        }
        cout << "| " << Ab[(n+1)*(i+1) - 1] << " )" << endl;
    }
}
