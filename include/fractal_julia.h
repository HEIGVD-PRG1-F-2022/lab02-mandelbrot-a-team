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
//for Julia
const static double R_J = 2.0; //set limit
const static double CX_J = -0.512511498387847167; //x coordinate of point of interest
const static double CY_J = 0.521295573094847167; //y coordinate of point of interest

int julia(double zx, double zy, double cx, double cy);

std::vector<std::vector<int>> juliaRect(double zx0, double zy0, double cx, double cy, double R, int nX, int nY);
#endif //MANDELBROT_FRACTAL_JULIA_H
