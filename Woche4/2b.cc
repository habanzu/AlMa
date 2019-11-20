#include <iostream>
#include <iomanip> 
using std::cout;
using std::endl;

double f(double a, double b){
    double a2 = a*a;
    double b2 = b*b;
    double b4 = b2*b2;
    double b6 = b4*b2;
    double b8 = b4*b4;
    double result = (333.75 -a2)*b6 + a2*(11*a2*b2 - 121*b4 -2) + 5.5*b8 + a/(2*b);
    return result;
}

float f(float a, float b){
    float a2 = a*a;
    float b2 = b*b;
    float b4 = b2*b2;
    float b6 = b4*b2;
    float b8 = b4*b4;
    float result = (333.75f -a2)*b6 + a2*(11.f*a2*b2 - 121.f*b4 -2.f) + 5.5f*b8 + a/(2.f*b);
    return result;
}

int main(){
    double a = 77617;
    double b = 33096;
    float af = a;
    float bf = b;
    cout << std::setprecision(10) << "Double: " << f(a,b) << " Float: " << f(af,bf) << endl;
}
