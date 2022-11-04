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

//set limits
const static double X1_T = -2.5;
const static double X2_T = 1.0;
const static double Y1_T = -1.0;
const static double Y2_T = 1.0;

//points au centre de la limite du set
const static double XC_T = (X2_T -X1_T)/2.0 + X1_T;
const static double YC_T = (Y2_T-X2_T)/2.0 + Y1_T;
int tricorn(double x0, double y0);

std::vector<std::vector<int>> tricornRect(double X1, double Y1, double X2, double Y2, int nX, int nY);
std::vector<std::vector<int>> tricornRect(double XC, double YC, int nX, int nY, double dX, double dY);
#endif //MANDELBROT_FRACTAL_TRICORN_H
