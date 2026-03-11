#ifndef PIXEL_H
#define PIXEL_H

#include <vector>
#include <iostream>
#include <fstream>

typedef struct Pixel {
	int x;
	int y;
	float r;
	float g;
	float b;
} Pixel;

void average_colors(std::vector<Pixel> &pixel_list);
void flip_vertically(std::vector<Pixel> &pixel_list);

#endif
