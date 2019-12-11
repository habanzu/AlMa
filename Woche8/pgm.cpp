// zum erstellen von pgm dateien

#include "pgm.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

void writePGMHeader(std::ofstream& pgm, const unsigned int WIDTH, const unsigned int HEIGHT)
{
	if(pgm){
		pgm << "P2\n"
			<< WIDTH << " " << HEIGHT << "\n"
			<< 255 << "\n";
	}
}

void writeArrayToImage(std::ofstream& pgm, vector<uint8_t> image, const unsigned int WIDTH, const unsigned int HEIGHT)
{

	for(unsigned int i = 0; i < HEIGHT; i++){

		unsigned int line_index = (i)*WIDTH; // Start-Index der i-ten Zeile des Bildes
		for(unsigned int j = 0; j < WIDTH; j++){
			pgm << (int) image.at(line_index + j) << " ";

		}
		pgm << "\n";
	}
}

int createPGM(unsigned int width, unsigned int height, vector<uint8_t> img) {
	// initialisiere output stream
	ofstream pgm("my_map.pgm");
	// dateikopf in datei schreiben (Bsp-Funktion siehe unten)
	writePGMHeader(pgm, width, height);

	// bild mit array beschreiben (Bsp-Funktion siehe unten)
	writeArrayToImage(pgm, img, width, height);

	return 0;
}
