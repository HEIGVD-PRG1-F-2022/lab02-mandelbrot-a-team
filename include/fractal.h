//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
// File created by Aellen Quentin on 12.10.2022 at 16:17:24 
//

#ifndef MANDELBROT_FRACTAL_H
#define MANDELBROT_FRACTAL_H

const static int DEFAULT_MAX_ITERATION = 1000;
//set limits for Mandelbrot
const static double X1_M = -2.0;
const static double X2_M = 0.47;
const static double Y1_M = -1.12;
const static double Y2_M = 1.12;

//for Julia
const static double R_J = 2.0; //set limit
const static double CX_J = -0.512511498387847167; //x coordinate of point of interest
const static double CY_J = 0.521295573094847167; //y coordinate of point of interest

//for Tricorn
//set limits
const static double X1_T = -2.5;
const static double X2_T = 1.0;
const static double Y1_T = -1.0;
const static double Y2_T = 1.0;
#endif //MANDELBROT_FRACTAL_H
