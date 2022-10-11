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

int normalizeIterationRange(int value, int targetMin, int targetMax, int currentMin, int currentMax);
int mandelbrot(double x0, double y0);
void mandelbrotSet(std::vector<std::vector<int>> &);

void draw(std::vector<std::vector<int>> &);
void drawGrayscale(const std::vector<std::vector<int>> &);
std::vector<std::vector<int>> calcRect(double X1, double Y1, double X2, double Y2, int nX, int nY);
std::vector<std::vector<int>> calcRect(double X1, double Y1, int nX, int nY, double dX, double dY);
#endif //MANDELBROT_MAIN_H
