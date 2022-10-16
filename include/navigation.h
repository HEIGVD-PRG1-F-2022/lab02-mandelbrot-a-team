//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#ifndef MANDELBROT_NAVIGATION_H
#define MANDELBROT_NAVIGATION_H

#include <vector>

static int width = 100, height = 100;

static std::vector<double> coords = {-0.761574, -0.0847596};

static double zoom = 1;

static double zoomScale = 0.2;

static double getZoomScale();

void startNavigation();

void displayNavigationCommandsHelper();

void drawWithNavigation(const std::vector<std::vector<int>> &, int maxIterations);

#endif //MANDELBROT_NAVIGATION_H
