#include <iostream>
#include <iomanip>

using std::cout;

int main(){
    int x,y;
    std:: cout << "x = ";
    std:: cin >> x;
    std:: cout << "y = ";
    std:: cin >> y;
    std:: cout << x << " + " << y << " = " << x + y << std::endl;

    if (y != 0){
        std::streamsize prec = std::cout.precision();

        std:: cout << x << " / " << y << " = " << std::fixed << std::setprecision(3) << (float) x / y << std::setprecision(prec) << std::endl;
    }
}
