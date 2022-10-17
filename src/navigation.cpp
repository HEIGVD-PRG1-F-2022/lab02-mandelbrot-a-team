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
    const vector<double> initialXY = coords;
    const double initialZoom = zoom;
    double x = coords[0], y = coords[1];

    while (true) {
        char input;
        vector<string> options = {"Select your fractal", "Free navigation", "Auto zoom"};

        setConsoleCursorToStart();

        vector<vector<int>> fractalSet;

        switch (fractalSelected) {
            case Fractal::Mandelbrot:
                fractalSet = calcRect(x, y, width, height, (X2-X1) / zoom, (Y2-Y1) / zoom);
                break;
            case Fractal::Julia:
              fractalSet = juliaRect(-0.512511498387847167, 0.521295573094847167, 2/zoom, 100, 100);// TODO
                break;
            case Fractal::Tricorn:
                fractalSet = tricornRect(-1.25, 0, 100, 100, 3.5/zoom, 2/zoom);// TODO
                break;
        }

        drawWithNavigation(fractalSet, DEFAULT_MAX_ITERATION);


        cin >> input;

        switch (input) {
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
                if (zoom == 1) {
                    break;
                }
                zoom /= 2;
                break;
            case 'q':
                coords = initialXY;
                zoom = initialZoom;
                return;
        }
    }
}

double getZoomScale() {
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