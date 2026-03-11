#include "pixel.h"

void average_colors(std::vector<Pixel> &pixel_list) {
	if (pixel_list.empty()) {
		std::cout << "No pixels loaded.\n";
		return;
	}

	double total_r = 0.0;
	double total_g = 0.0;
	double total_b = 0.0;

	for (const auto &p : pixel_list) {
		total_r += p.r;
		total_g += p.g;
		total_b += p.b;
	}

	double count = static_cast<double>(pixel_list.size());

	std::cout << "Average R: " << total_r / count << "\n";
	std::cout << "Average G: " << total_g / count << "\n";
	std::cout << "Average B: " << total_b / count << "\n";
}

void flip_vertically(std::vector<Pixel> &pixel_list) {
	const int WIDTH = 512;
	const int HEIGHT = 256;

	for (auto &p : pixel_list) {
		p.y = (HEIGHT - 1) - p.y;  // 255 - y
	}

	std::ofstream out("flipped.dat");

	if (!out) {
		std::cerr << "Error creating flipped.dat\n";
		return;
	}

	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {

			// Reverse the y-index to correct ordering
			int index = x * HEIGHT + (HEIGHT - 1 - y);

			const Pixel &p = pixel_list[index];

			out << x << ", "
				<< y << ", "
				<< p.r << ", "
				<< p.g << ", "
				<< p.b << "\n";
		}
	}

}
