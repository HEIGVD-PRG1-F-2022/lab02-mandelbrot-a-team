//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//


#ifndef MANDELBROT_MAIN_H
#define MANDELBROT_MAIN_H
#include <vector>

int mandelbrot(double x0, double y0);
void mandelbrotSet(std::vector<std::vector<int>> &);
void draw(std::vector<std::vector<int>>);

#endif //MANDELBROT_MAIN_H
