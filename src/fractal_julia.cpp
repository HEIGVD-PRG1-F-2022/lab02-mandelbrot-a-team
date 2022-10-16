//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include <vector>
#include "../include/fractal_julia.h"

using namespace std;

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

vector<vector<int>> juliaRect(double cx, double cy, double R, int nX, int nY) {
    vector<vector<int>> set(nX, vector<int>(nY, 0));
    for (int x = 0; x < nX; x++) {
        for (int y = 0; y < nY; y++) {
            double zx = x * ((2 * R) / nX) - R;
            double zy = y * ((2 * R) / nY) - R;
            set[x][y] = julia(zx, zy, cx, cy);
        }
    }
    return set;
}
vector<vector<int>> juliaRect(double X1, double Y1, int nX, int nY, double dX, double dY) {

    return juliaRect(X1 - dX / 2, Y1 - dY / 2.0, X1 + dX / 2.0, Y1 + dY / 2, nX, nY);
}