#include <iostream>

int test_zweier_potenz(unsigned int x){
    return ((n&-n) == n);
}

int main(){
    unsigned int x,y;
    std:: cout << "x = ";
    std:: cin >> x;
    if (test_zweier_potenz(x))
        std:: cout << x << " ist eine Zweierpotenz." << std::endl;
    else
        std:: cout << x << " ist keine Zweierpotenz." << std::endl;
    return 0;
}
