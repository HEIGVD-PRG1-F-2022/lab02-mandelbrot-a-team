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

void startNavigation() {
    double x1 = X1Y1[0], y1 = X1Y1[1];

    while (true) {
        char input;
        double x = coords[0], y = coords[1];
        vector<string> options = {"Select your fractal", "Free navigation", "Auto zoom"};

        setConsoleCursorToStart();

        vector<vector<int>> fractalSet;

        switch (fractalSelected) {
            case Fractal::Mandelbrot:
                fractalSet = calcRect(x1, y1, width, height, 2.47 / zoom, 2.24 / zoom);
                break;
            case Fractal::Julia:
                // TODO
                break;
            case Fractal::Tricorn:
                // TODO
                break;
        }

        drawWithNavigation(fractalSet, DEFAULT_MAX_ITERATION);


        cin >> input;

        switch (input) {
            case 'w':
                y1 -= getZoomScale();
                break;
            case 's':
                y1 += getZoomScale();
                break;
            case 'a':
                x1 -= getZoomScale();
                break;
            case 'd':
                x1 += getZoomScale();
                break;
            case '+':
                if (zoom < zoom * pow(2, 64))
                    zoom *= 2;
                break;
            case '-':
                if (zoom == 1) {
                    break;
                }
                zoom /= 2;
                break;
            case 'q':
                return;
        }
    }
}

static double getZoomScale() {
    return zoomScale / zoom;
}

void displayNavigationCommandsHelper() {
    cout << "Navigation (w=Top, s=Bottom, a=Left, d=Right)\nZoom (+=Zoom in, -=Zoom out)\nExit (q)\n> ";
}

void drawWithNavigation(const vector<vector<int>> &fractalSet, int maxIteration) {
    setConsoleCursorToStart();
    drawColors(fractalSet, maxIteration);
    displayNavigationCommandsHelper();
}