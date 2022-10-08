//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include <iostream>
#include "main.h"

const int MAX_ITERATION = 1000;
using namespace std;

int main() {
    int width = 1000, height = 1000;
    vector<vector<int>> graphics(width, vector<int>(height));
    mandelbrotSet(graphics);
    draw(graphics);
    return 0;
}

/**
 * Calculate mandelbrotSet values and save them into a 2D array
 * @param graphics
 */
void mandelbrotSet(vector<vector<int>> &graphics) {
    int graphicsVectorWidth = graphics.size();

    for (int x = 0; x < graphicsVectorWidth; x++) {
        int graphicsVectorHeight = graphics[x].size();
        for (int y = 0; y < graphicsVectorHeight; y++) {
            double xStart = x * ((2.47) / graphicsVectorWidth) - 2.0;
            double yStart = -y * ((2.24) / graphicsVectorHeight) + 1.12;

            int iteration = mandelbrot(xStart, yStart);

            int colorCode = iteration == MAX_ITERATION ? 0 : 1;
            // x and y are reversed
            graphics[y][x] = colorCode;
        }
    }
}

/**
 * Display 2D array into terminal
 * @param graphics
 */
void draw(vector<vector<int>> &graphics) {
    for (int x = 0; x < graphics.size(); x++) {
        for (int y = 0; y < graphics[x].size(); y++) {
            cout << graphics[x][y];
        }
        cout << endl;
    }
}

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
    while ((r * r) + (i * i) <= 2 * 2 and iteration < MAX_ITERATION) {
        double xtemp = (r * r) - (i * i) + x0;
        i = 2 * r * i + y0;
        r = xtemp;

        iteration++;
    }
    return iteration;
}