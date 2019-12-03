// dieses programm erstellt ein 20x20 pixel großes schwarzes pgm bild

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
	
void writePGMHeader(std::ofstream& pgm, const unsigned int WIDTH, const unsigned int HEIGHT)
{
	if(pgm){
		pgm << "P2\n"
			<< WIDTH << " " << HEIGHT << "\n"
			<< 255 << "\n";
	}
}

void writeArrayToImage(std::ofstream& pgm, const uint8_t* image, const unsigned int WIDTH, const unsigned int HEIGHT)
{
	for(unsigned int i = 0; i < HEIGHT; i++){
		unsigned int line_index = (HEIGHT-1 - i)*WIDTH; // Start-Index der i-ten Zeile des Bildes
		for(unsigned int j = 0; j < WIDTH; j++){
			pgm << image[line_index + j] << " ";
		}
		pgm << "\n";
	}
}

int main(int argc, char* argv[]) {
	const unsigned int width = 20;
	const unsigned int height = 20;
	// initialisiere output stream
	ofstream pgm("test.pgm", std::ios::app);
	// dateikopf in datei schreiben (Bsp-Funktion siehe unten)
	writePGMHeader(pgm, width, height);
	// initialisiere array
	uint8_t img[width*height];
	// bild mit array beschreiben (Bsp-Funktion siehe unten)
	writeArrayToImage(pgm, img, width, height);
	
	return 0;
}