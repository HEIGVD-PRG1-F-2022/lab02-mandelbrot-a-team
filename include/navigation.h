//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#ifndef MANDELBROT_NAVIGATION_H
#define MANDELBROT_NAVIGATION_H

#include <vector>

double getZoomScale();

void startNavigation();

void displayNavigationCommandsHelper();

void drawWithNavigation(const std::vector<std::vector<int>> &, int maxIterations);

#endif //MANDELBROT_NAVIGATION_H
