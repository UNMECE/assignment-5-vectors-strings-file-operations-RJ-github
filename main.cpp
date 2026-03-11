#include "pixel.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() {
	std::vector<Pixel> pixel_list;
	std::ifstream file("pixels.dat");
	std::string line;


	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string value;
		std::vector<std::string> values;

		// Split by comma
		while (std::getline(ss, value, ',')) {
			values.push_back(value);

			if (values.size() == 5) {
				Pixel p;
				p.x = std::stoi(values[0]);
				p.y = std::stoi(values[1]);
				p.r = std::stof(values[2]);
				p.g = std::stof(values[3]);
				p.b = std::stof(values[4]);

				pixel_list.push_back(p);
			}
		}
	}

	average_colors(pixel_list);
	flip_vertically(pixel_list);

	return 0;
}
