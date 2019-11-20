#include <iostream>
#include <fstream>
#include <complex>
#include <cmath>
#include <chrono>

typedef std::complex<long double> comp;

constexpr uint32_t GRAY_VALUES = 255;
constexpr long double GAMMA_CORRECT = 0.4;
constexpr uint32_t THRESHOLD = 4;
constexpr uint32_t N_MAX = 255;

void createPGM(std::ofstream &img, const uint32_t height, const uint32_t width) {
   img.open("img.pgm");
   img << "P2\n"
       << width << "\n"
       << height << "\n"
       << GRAY_VALUES << std::endl;
}

uint32_t grayValueOfSequence(const comp& c) {
   comp z(0);
   for(uint32_t i = 0; i < N_MAX; ++i) {
      if (real(z) * real(z) + imag(z) * imag(z) > THRESHOLD) {
         return pow((double(i)/N_MAX), GAMMA_CORRECT) * GRAY_VALUES;
      }
      z = z * z + c;
   }
   return GRAY_VALUES;
}
 
void writeRow(std::ofstream &img, const uint32_t width, const long double xmin, const long double xmax, const long double y) {
   const comp deltaX((xmax - xmin)/width,0);
   comp z(xmin, y);
   for (uint32_t i = 0; i < width; ++i) {
      img << grayValueOfSequence(z) << " ";
      z += deltaX;
   }
}

int main() {
   const auto start = std::chrono::steady_clock::now();

   std::ofstream img;
   const uint32_t w = 2500;
   const uint32_t h = 2200;
   const long double x_min = -1.9;
   const long double x_max = .6;
   const long double y_min = -1.1;
   const long double y_max = 1.1;
   createPGM(img, h,w);

   comp x(0,0);

   const auto deltaY = (y_max - y_min) / h;
   auto y = y_min;

   for (uint32_t i = 0; i < h; ++i) {
      writeRow(img, w, x_min, x_max, y);
      img << "\n";
      y += deltaY;
      std::cout << "\rRow " << i << " of " << h << "..." << std::flush;
   }

   img.close();

   const auto end = std::chrono::steady_clock::now();
   const auto diff = end - start;
   const auto sec = std::chrono::duration_cast<std::chrono::seconds>(diff).count();
   const auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();

   std::cout << "\nTook: " << sec << "." << msec << "s" << std::endl;
}

//115 sec
//112 nach arithmetik
//5 sec release x64
//3.39 sec
//603 sec with 65535 N_MAX
//422 sec for 25000x22000 with N_MAX = 100
