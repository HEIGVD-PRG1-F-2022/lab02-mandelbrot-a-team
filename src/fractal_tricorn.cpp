//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
// File created by Aellen Quentin on 12.10.2022 at 16:39:56 
//

#include "../include/fractal_tricorn.h"

using namespace std;

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
    vector<vector<int>> tricornRect(double X1, double Y1, int nX, int nY, double dX, double dY) {

        return tricornRect(X1 - dX / 2.0, Y1 - dY / 2.0, X1 + dX / 2.0, Y1 + dY / 2.0, nX, nY);
    }

