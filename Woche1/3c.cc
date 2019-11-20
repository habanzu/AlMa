#include <iostream>
#include <stdlib.h>

int modulo(int x, int n){
    if (n == 0){
        std::cout << "Unzulässige Eingabe!";
        return 0;
    }
    return x - (x/n)*n;
}

int main(){
    int x,y;
    std:: cout << "x = ";
    std:: cin >> x;
    std:: cout << "y = ";
    std:: cin >> y;
    std:: cout << x << " % " << y << " = " << modulo(x,y) << std::endl;
    return 0;
}
