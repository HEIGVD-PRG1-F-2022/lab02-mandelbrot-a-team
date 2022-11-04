//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
// File created by Aellen Quentin on 12.10.2022 at 16:39:56 
//

#include "../include/fractal_tricorn.h"

using namespace std;
/**
 * Calculate maximum number of mandelbrot iteration before exceeding MAX_ITERATION or if numbers have a tendency to be infinite
 * @param x0 starting x offset
 * @param y0 starting y offset
 * @return number of iteration
 */
int tricorn(double x0, double y0) {
    int iteration = 0;
    double x = 0.0; // real part of complex number
    double y = 0.0; // imaginary part of complex number
    while ((x * x) + (y * y) < 2 * 2 and iteration < DEFAULT_MAX_ITERATION) {
        double xtemp = (x * x) - (y * y) + x0;
        y = -(2 * x * y) + y0;
        x = xtemp;

        iteration++;
    }
    return iteration;
}

/**
 * Calculate the tricorn set from coords (X1, Y1) to (X2, Y2)
 * with nX points between X1 and X2 and nY points between Y1 et Y2.
 * @param X1 starting x coordinate
 * @param Y1 starting y coordinate
 * @param X2 ending x coordinate
 * @param Y2 ending y coordinate
 * @param nX number of points to calculate for X axis (resolution)
 * @param nY number of points to calculate for Y axis (resolution)
 * @return 2D vector of size nX*nY with number of iteration for each point
 */
vector <vector<int>> tricornRect(double X1, double Y1, double X2, double Y2, int nX, int nY) {
    vector <vector<int>> set(nX, vector<int>(nY, 0));

    for (int x = 0; x < nX; x++) {
        for (int y = 0; y < nY; y++) {
            double x0 = x * ((X2 - X1) / nX) + X1;
            double y0 = y * ((Y2 - Y1) / nY) + Y1;
            set[x][y] = tricorn(x0, y0);
        }
    }

    return set;

}
/**
 * Calculate the tricorn around coords (X1, Y1) with a width of dX and a height of dY.
 * The vector have nX points in width and nY points in height.
 * @param XC x coordinate of point around which we want to see the set
 * @param YC y coordinate of point around which we want to see the set
 * @param nX number of points to calculate for X axis (resolution)
 * @param nY number of points to calculate for Y axis (resolution)
 * @param dX size of interval around X1
 * @param dY size of interval around Y1
 * @return 2D vector of size nX*nY with number of iteration for each point
 */
    vector<vector<int>> tricornRect(double XC, double YC, int nX, int nY, double dX, double dY) {

        return tricornRect(XC - dX / 2.0, YC - dY / 2.0, XC + dX / 2.0, YC + dY / 2.0, nX, nY);
    }

