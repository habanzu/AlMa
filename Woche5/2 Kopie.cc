#include <iostream>
#include <fstream>
#include <complex>
#include <cmath>
#include <algorithm>

constexpr uint32_t grayvalues = 255;

using std::ofstream;
using std::endl;
using std::complex;
using std::pow;
using std::real;
using std::imag;
using std::cout;
using std::string;
using std::to_string;
using std::fmin;

void createPGM(ofstream &img, const unsigned height, const unsigned int width){
    img.open("img.pgm");
    img << "P2" << endl;
    img << width << endl << height << endl;
    img << grayvalues << endl;
}

int grayValueOfSequence(const complex<double>& c){
    const double gamma_correct = 0.2;
    const unsigned n_max = 1024;
    const double treshold = 4;
    complex<double> z(0);
    for(unsigned i = 0; i < n_max; i++){
        if (real(z)*real(z) + imag(z)*imag(z) > treshold){
            return pow(((double)i/(double)n_max), gamma_correct)*grayvalues;
        }
        z = z*z + c;
    }
    return grayvalues;
}

void writeRow(ofstream &img, const unsigned width, const double xmin, const double xmax, const double y){
    const double deltaX = (xmax - xmin)/width;
    complex<double> z(xmin, y);
    for (unsigned int i = 0; i < width; i++){
        img << grayValueOfSequence(z) << " ";
        z += deltaX;
    }
}


int main(){
    ofstream img;
    const int w = 2500; const int h = 2200;
    const double xmin = -1.9; const double xmax = .6; const double ymin = -1.1; const double ymax = 1.1;
    createPGM(img, h,w);

    const double deltaY = (ymax - ymin)/h;
    double y = ymin;

    for (unsigned int i = 0; i < h; i++){
        writeRow(img, w, xmin, xmax, y);
        img << endl;
        y += deltaY;
    }

    img.close();
    return 0;
}
