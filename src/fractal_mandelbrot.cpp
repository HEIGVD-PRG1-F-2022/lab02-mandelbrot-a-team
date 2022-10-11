//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include "../include/fractal_mandelbrot.h"

using namespace std;

/**
 * Calculate maximum number of mandelbrot iteration before exceeding MAX_ITERATION or if numbers have a tendency to be infinite
 * @param x0 starting x offset
 * @param y0 starting y offset
 * @return number of iteration
 */
int mandelbrot(double x0, double y0) {
    int iteration = 0;
    double r = 0.0; // Real number
    double i = 0.0; // Imaginary number
    while ((r * r) + (i * i) <= 2 * 2 and iteration < 1000) {
        double xtemp = (r * r) - (i * i) + x0;
        i = 2 * r * i + y0;
        r = xtemp;

        iteration++;
    }
    return iteration;
}

/**
 * Calcule le mandelbrot depuis (X1, Y1) a (X2, Y2)
 * avec nX points entre X1 et X2 et nY points entre Y1 et Y2.
 * @param X1 starting x coordinate
 * @param Y1 starting y coordinate
 * @param X2 ending x coordinate
 * @param Y2 ending y coordinate
 * @param nX number of points to calculate for X axis (resolution)
 * @param nY number of points to calculate for Y axis (resolution)
 * @return 2D vector of size nX*nY with number of iteration for each point
 */
vector<vector<int>> calcRect(double X1, double Y1, double X2, double Y2, int nX, int nY) {
    vector<vector<int>> fractalSet(nX, vector<int>(nY, 0));

    for (int x = 0; x < nX; x++) {
        for (int y = 0; y < nY; y++) {
            double x0 = x * ((X2 - X1) / nX) + X1;
            double y0 = y * ((Y2 - Y1) / nY) + Y1;
            fractalSet[x][y] = mandelbrot(x0, y0);
        }
    }

    return fractalSet;
}

/**
 * Calcule le mandelbrot autour de (X1, Y1) avec une largeur de dX et une hauteur de dY.
 * Le vecteur a nX points en largeur et nY points en hauteur.
 * @param X1 x coordinate of point around which we want to see the set
 * @param Y1 y coordinate of point around which we want to see the set
 * @param nX number of points to calculate for X axis (resolution)
 * @param nY number of points to calculate for Y axis (resolution)
 * @param dX size of interval around X1
 * @param dY size of interval around Y1
 * @return 2D vector of size nX*nY with number of iteration for each point
 */
vector<vector<int>> calcRect(double X1, double Y1, int nX, int nY, double dX, double dY) {

    return calcRect(X1 - dX / 2, Y1 - dY / 2.0, X1 + dX / 2.0, Y1 + dY / 2, nX, nY);
}