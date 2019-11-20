#include <iostream>

int test_zweier_potenz(int x){
    while(x > 2){
        if (x % 2 == 1)
            return 0;
        x /= 2;
    }
    return 1;
}

int main(){
    int x,y;
    std:: cout << "x = ";
    std:: cin >> x;
    if (test_zweier_potenz(x))
        std:: cout << x << " ist eine Zweierpotenz." << std::endl;
    else
        std:: cout << x << " ist keine Zweierpotenz." << std::endl;
    return 0;
}
