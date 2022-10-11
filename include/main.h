//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#ifndef MANDELBROT_MAIN_H
#define MANDELBROT_MAIN_H

#include <vector>

#ifdef _WIN32

#include <windows.h> //for colored output in console if using Windows

#endif

void mandelbrotSet(std::vector<std::vector<int>> &);

void draw(std::vector<std::vector<int>> &);

void drawGrayscale(const std::vector<std::vector<int>> &);

#endif //MANDELBROT_MAIN_H
