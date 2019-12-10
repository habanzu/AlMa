#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void writePGMHeader(std::ofstream&, const unsigned int, const unsigned int);

void writeArrayToImage(std::ofstream&, vector<uint8_t>, const unsigned int, const unsigned int);

int createPGM(unsigned int, unsigned int, vector<uint8_t>);
