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

std::vector<std::vector<int>> juliaRect(double cx, double cy, double R, int nX, int nY) {
    std::vector<std::vector<int>> set(nX, std::vector<int>(nY, 0));
    for (int x = 0; x < nX; x++) {
        for (int y = 0; y < nY; y++) {
            double zx = x * ((2 * R) / nX) - R;
            double zy = y * ((2 * R) / nY) - R;
            set[x][y] = julia(zx, zy, cx, cy);
        }
    }
    return set;
}
