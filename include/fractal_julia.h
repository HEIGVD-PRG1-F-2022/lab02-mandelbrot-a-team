//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#ifndef MANDELBROT_FRACTAL_JULIA_H
#define MANDELBROT_FRACTAL_JULIA_H

#include <vector>
#include "fractal.h"

int julia(double zx, double zy, double cx, double cy);

std::vector<std::vector<int>> juliaRect(double zx0, double zy0, double cx, double cy, double R, int nX, int nY);
#endif //MANDELBROT_FRACTAL_JULIA_H
