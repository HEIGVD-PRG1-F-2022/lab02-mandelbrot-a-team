//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include <vector>
#include <cmath>
#include <iostream>
#include "../include/animation.h"
#include "../include/menu.h"
#include "../include/util.h"
#include "../include/draw.h"
#include "../include/fractal_mandelbrot.h"
#include "../include/fractal_julia.h"
#include "../include/fractal_tricorn.h"

using namespace std;

void startAnimation()
{
    const vector<double> initialXY = {0.0, 0.0};
    const double initialZoom = zoom;
    double x = 0.0, y = 0.0;

    const double maxZoom = zoom * pow(2, 20);

    while (true)
    {
        if (zoom >= maxZoom)
        {
            zoom = initialZoom;
            cout << "> Press enter a key to leave";
            cin.ignore();
            if (cin.get() == '\n')
                break;
            break;
        }

        vector<string> options = {"Select your fractal", "Free navigation", "Auto zoom"};

        vector<vector<int>> fractalSet;
        switch (getFractalSelected())
        {
        case Fractal::Mandelbrot:
            fractalSet = calcRect(coords_M1[0] + x, coords_M1[1] + y, width, height, (X2_M - X1_M) / zoom,
                                  (Y2_M - Y1_M) / zoom);
            break;
        case Fractal::Julia:
            fractalSet = juliaRect(x, y, CX_J, CY_J, R_J / zoom, width, height);
            break;
        case Fractal::Tricorn:
            fractalSet = tricornRect(XC_T + x, YC_T + y,
                                     100, 100, (X2_T - X1_T) / zoom, (Y2_T - Y1_T) / zoom);
            break;
        }

        setConsoleCursorToStart();
        drawColors(fractalSet, DEFAULT_MAX_ITERATION);
        zoom *= 1.1;
        wait(50);
    }
    return;
}