//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#ifndef MANDELBROT_FRACTAL_MANDELBROT_H
#define MANDELBROT_FRACTAL_MANDELBROT_H

#include <vector>

const static int MAX_ITERATION = 1000;
const static std::vector<double> X1Y1 = {-2, 0.47};
const static std::vector<double> X2Y2 = {-1.12, 1.12};
int mandelbrot(double x0, double y0);
int julia(double zx, double zy, double cx, double cy);
int tricorn(double x0, double y0);

std::vector<std::vector<int>> calcRect(double X1, double Y1, double X2, double Y2, int nX, int nY);
std::vector<std::vector<int>> calcRect(double X1, double Y1, int nX, int nY, double dX, double dY);

std::vector<std::vector<int>> tricornRect(double X1, double Y1, double X2, double Y2, int nX, int nY);
std::vector<std::vector<int>> juliaRect(double cx, double cy, double R, int nX, int nY);
#endif //MANDELBROT_FRACTAL_MANDELBROT_H
