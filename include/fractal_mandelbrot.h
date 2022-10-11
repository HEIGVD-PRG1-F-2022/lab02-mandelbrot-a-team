//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#ifndef MANDELBROT_FRACTAL_MANDELBROT_H
#define MANDELBROT_FRACTAL_MANDELBROT_H

#include <vector>

int mandelbrot(double x0, double y0);

std::vector<std::vector<int>> calcRect(double X1, double Y1, double X2, double Y2, int nX, int nY);
std::vector<std::vector<int>> calcRect(double X1, double Y1, int nX, int nY, double dX, double dY);

#endif //MANDELBROT_FRACTAL_MANDELBROT_H