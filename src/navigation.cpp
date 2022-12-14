//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include <vector>
#include <iostream>
#include <cmath>
#include "../include/menu.h"
#include "../include/navigation.h"
#include "../include/util.h"
#include "../include/draw.h"
#include "../include/fractal_mandelbrot.h"
#include "../include/fractal_julia.h"
#include "../include/fractal_tricorn.h"

using namespace std;

void startNavigation()
{
    const vector<double> initialXY = {0.0, 0.0};
    const double initialZoom = zoom;
    double x = 0.0, y = 0.0;

    while (true)
    {
        char input;
        vector<string> options = {"Select your fractal", "Free navigation", "Auto zoom"};

        setConsoleCursorToStart();

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

        drawWithNavigation(fractalSet, DEFAULT_MAX_ITERATION);

        cin >> input;

        switch (input)
        {
        case 'w':
            y -= getZoomScale();
            break;
        case 's':
            y += getZoomScale();
            break;
        case 'a':
            x -= getZoomScale();
            break;
        case 'd':
            x += getZoomScale();
            break;
        case '+':
            if (zoom < zoom * pow(2, 64))
                zoom *= 2;
            break;
        case '-':
            if (zoom == 1)
            {
                break;
            }
            zoom /= 2;
            break;
        case 'q':
            zoom = initialZoom;
            return;
        }
    }
}

double getZoomScale()
{
    return zoomScale / zoom;
}

void displayNavigationCommandsHelper()
{
    cout << "Navigation (w=Top, s=Bottom, a=Left, d=Right)\nZoom (+=Zoom in, -=Zoom out)\nExit (q)\n> ";
}

void drawWithNavigation(const vector<vector<int>> &fractalSet, int maxIteration)
{
    setConsoleCursorToStart();
    drawColors(fractalSet, maxIteration);
    displayNavigationCommandsHelper();
}