// Diese Woche richte ich mich nach dem AlMa Skript, Kapitel 9
#include "LUdecomposition.h"
#include <iostream>

int main(){
    vector<double> A{2,1,1,2,1,1};
    LUdecomposition LR(A, 2);
    LR.LUdecomp();
    LR.print();
    return 0;
}
