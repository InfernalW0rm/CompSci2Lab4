#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

void readColorsFromFile(const string& filename, Picture& picture) {
	ifstream file(filename);
	if (!file.is_open()) {
		throw FileNotFoundException();
	}

	int x, y, r, g, b;
	while (file >> x >> y >> r >> g >> b) {
		if (file.fail()) {
			throw ColorFileFormatException();
		}

		if (x < 0 || y < 0) {
			cout << "CordinateOutOfRangeException: (" << x << "," << y << ")" << endl;
			continue;
		}
		if (r < 0 || r>225 || r < 0 || g>225 || b < 0 || b>225) {
			string errorMsg = "Error! X: " + to_string(x) + "Y:" + to_string(y);
			if (r < 0) errorMsg = +" Red value too low: min: 0, actual: " + to_string(r);
			if (r > 225) errorMsg = +" Red value too high: max: 225, actual: " + to_string(r);
			if (g < 0) errorMsg = +" Green value too low: min: 0, actual: " + to_string(g);
			if (g > 225) errorMsg = +" Green value too high: max: 225, actual: " + to_string(g);
			if (b < 0) errorMsg = +" Blue value too low: min: 0, actual: " + to_string(b);
			if (b > 225) errorMsg = +" Blue value too low: max: 225, actual: " + to_string(b);
			cout << errorMsg << endl;
			
			

 		}
		picture.setPixel(x, y, Color(r, g, b));
	}
}