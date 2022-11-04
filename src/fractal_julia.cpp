//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include <vector>
#include "../include/fractal_julia.h"

using namespace std;

/**
 * Calculate maximum number of julia iteration of point (cx, cy( before exceeding MAX_ITERATION or if numbers have a tendency to be infinite
 * @param zx starting x offset
 * @param zy starting y offset
 * @param cx coordinate x of C number of the julia set
 * @param cy coordinate y of C number of the julia set
 * @return number of iteration
 */
int julia(double zx, double zy, double cx, double cy) {
    int iteration = 0;
    while ((zx * zx) + (zy * zy) <= 2 * 2 and iteration < DEFAULT_MAX_ITERATION) {
        double xtemp = (zx * zx) - (zy * zy) + cx;
        zy = 2 * zx * zy + cy;
        zx = xtemp;

        iteration++;
    }
    return iteration;
}
/**
 * Calculate the mandelbrot from coords for coords (cx, cy)
 * with center (zx0, zy0) with nx points between zx0 - R and zx0 + R and nY points between zy0 -R and zy0 + R.
 * @param zx0 center of set x coordinate
 * @param zy0 center of set y coordinate
 * @param cx x coordinate of point of this julia set
 * @param cy y coordinate of point of this julia set
 * @param R range before set diverges
 * @param nX number of points to calculate for X axis (resolution)
 * @param nY number of points to calculate for Y axis (resolution)
 * @return 2D vector of size nX*nY with number of iteration for each point
 */
vector<vector<int>> juliaRect(double zx0, double zy0, double cx, double cy, double R, int nX, int nY) {
  vector<vector<int>> set(nX, std::vector<int>(nY, 0));
    for (int x = 0; x < nX; x++) {
        for (int y = 0; y < nY; y++) {
            double zx = x * ((2 * R) / nX) - R + zx0;
            double zy = y * ((2 * R) / nY) - R+ zy0;
            set[x][y] = julia(zx, zy, cx, cy);
        }
    }
    return set;
}
