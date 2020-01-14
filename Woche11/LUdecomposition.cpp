#include "LUdecomposition.h"
#include <cmath>
#include <iostream>

using std::cout; using std::endl;

LUdecomposition::LUdecomposition(vector<double> matrix, unsigned dim) :Ab(matrix), n(dim){}

void LUdecomposition::LUdecomp(){
    int i; const int n = this->n;
    for(int j = 0; j < this->n - 1; ++j){
        if((i = this->columnPivotSearch(j)) == -1)
            return;
        if(i != j)
            this->changeColumn(i, j);
        subtractRows(j);
    }
    //this->Ab[(n-1)*(n+1) + n] /= this->Ab[(n-1)*(n+1) + n -1 ];
    //this->Ab[(n-1)*(n+1) + n -1 ] = 1;

}

void solveR

void LUdecomposition::subtractRows(unsigned row){
    for(int i = row + 1; i < this->n; ++i){
        this->Ab[i*(this->n+1) + row] = this->Ab[i*(this->n+1) + row] / this->Ab[row*(this->n+1) + row];
        for(int j = row + 1; j <= this->n; ++j){
            this->Ab[i*(this->n+1) + j] -= this->Ab[i*(this->n+1) + row]*this->Ab[row*(this->n+1) + j];
        }
    }
}


void LUdecomposition::changeColumn(unsigned i1, unsigned i2){
    double tmp;
    for (int j = 0; j <= this->n; ++j){
        tmp = this->Ab[i1*(this->n +1) + j];
        Ab[i1*(this->n +1) + j] = Ab[i2*(this->n +1) + j];
        Ab[i2*(this->n +1) + j] = tmp;

    }
}

int LUdecomposition::columnPivotSearch(int j){
    for(int i = j; i < this->n; i++){
        if(this->Ab[i*(this->n +1) + j] != 0)
            return i;
    }
    cout << "Spalte " << j << " ist überall 0. Die Matrix ist singulär." << endl;
    return (-1);
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
