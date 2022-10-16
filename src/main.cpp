//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include <iostream>
#include <cmath>
#include "../include/fractal_mandelbrot.h"
#include "../include/fractal_julia.h"
#include "../include/fractal_tricorn.h"
#include "../include/draw.h"
#include "../include/util.h"
#include "../include/navigation.h"
#include "../include/menu.h"

using namespace std;

int main() {
#ifdef _WIN32
    setWindowsConsoleToUTF8();
#endif

    while(true) {
        showMainMenu();
    }

    /*int width = 100, height = 100;

    char input;
    double x1 = -0.761574, y1 = -0.0847596;
    unsigned long long int zoom = 3125;

    bool flag = true;
    drawColors(juliaRect(-0.835, -0.232, 2, width, height), DEFAULT_MAX_ITERATION);

    while (flag) {
        drawWithNavigation(calcRect(x1, y1, width, height, 2.47 / zoom, 2.24 / zoom), DEFAULT_MAX_ITERATION);

        cin >> input;

        switch (input) {
            case 'w':
                y1 -= 0.2 / zoom;
                break;
            case 's':
                y1 += 0.2 / zoom;
                break;
            case 'a':
                x1 -= 0.2 / zoom;
                break;
            case 'd':
                x1 += 0.2 / zoom;
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
                flag = false;
                clearConsole();
                break;
        }
    }*/

    //draw(calcRect(-2, -1.12, 0.47, 1.12, width, height));
    //drawGrayscale(calcRect(-2, -1.12, 0.47, 1.12, width, height));
    //drawGrayscale(calcRect(-0.10936189822, 0.894921716226, width, height, 2.47 / 1000, 2.24 / 1000));
    //drawColors(calcRect(-0.10936189822, 0.894921716226, width, height, 2.47 / 1000, 2.24 / 1000));
    return 0;
}