//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#ifndef MANDELBROT_FRACTAL_MANDELBROT_H
#define MANDELBROT_FRACTAL_MANDELBROT_H

#include <vector>
#include "fractal.h"

const static double X1_M = -2.0;
const static double X2_M = 0.47;
const static double Y1_M = -1.12;
const static double Y2_M = 1.12;
static std::vector<double> coords_M1 = {-0.761574, -0.0847596}; //point intéressant pour le MandelBrot set
int mandelbrot(double x0, double y0);

std::vector<std::vector<int>> calcRect(double X1, double Y1, double X2, double Y2, int nX, int nY);

std::vector<std::vector<int>> calcRect(double XC, double YC, int nX, int nY, double dX, double dY);

#endif //MANDELBROT_FRACTAL_MANDELBROT_H
