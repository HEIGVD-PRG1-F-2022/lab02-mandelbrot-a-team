//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//


#ifndef MANDELBROT_MAIN_H
#define MANDELBROT_MAIN_H
#include <vector>

int mandelbrot(int x0, int y0);
std::vector<std::vector<int>>  mandelbrotSet(std::vector<std::vector<int>>);
void draw(std::vector<std::vector<int>>);

#endif //MANDELBROT_MAIN_H
