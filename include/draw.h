//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#ifndef MANDELBROT_DRAW_H
#define MANDELBROT_DRAW_H

#include <vector>

void draw(const std::vector<std::vector<int>> &);

void drawRGB(const std::vector<std::vector<int>> &, int);

void drawGrayscale(const std::vector<std::vector<int>> &);

void drawColors(const std::vector<std::vector<int>> &, int);

#endif //MANDELBROT_DRAW_H
