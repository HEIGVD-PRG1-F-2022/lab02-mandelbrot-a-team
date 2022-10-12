//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
// File created by Aellen Quentin on 12.10.2022 at 16:39:56 
//

#ifndef MANDELBROT_FRACTAL_TRICORN_H
#define MANDELBROT_FRACTAL_TRICORN_H

#include <vector>
#include "fractal.h"

int tricorn(double x0, double y0);

std::vector<std::vector<int>> tricornRect(double X1, double Y1, double X2, double Y2, int nX, int nY);

#endif //MANDELBROT_FRACTAL_TRICORN_H
