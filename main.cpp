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
    int width = 100, height = 100;
    vector<vector<int>> graphics(width, vector<int>(height));
    mandelbrotSet(graphics);
    //draw(graphics);
    drawGrayscale(graphics);
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
            // x and y are reversed
            graphics[y][x] = iteration;
        }
    }
}

/**
 * Will normalize value between a new defined range
 * @param value the current value you want to match your new range
 * @param targetMin lowest limit of your new range
 * @param targetMax highest limit of your new range
 * @param currentMin lowest value possible of current value range
 * @param currentMax highest value possible of current value range
 * @return equivalent interpretation of the value in the specified new range
 */
int normalizeIterationRange(int value, int targetMin, int targetMax, int currentMin = 0, int currentMax = MAX_ITERATION) {
    return (value-currentMin) / (currentMax - currentMin) * (targetMax-targetMin) + targetMin;
}

/**
 * Display 2D array into terminal
 * @param graphics
 */
void draw(vector<vector<int>> &graphics) {
    for (int x = 0; x < graphics.size(); x++) {
        for (int y = 0; y < graphics[x].size(); y++) {
            cout << (graphics[x][y] == MAX_ITERATION ? '0' : '1');
        }
        cout << endl;
    }
}

/**
 * Display 2D array into terminal with grayscale (need compatible terminal)
 * More information here : https://tforgione.fr/posts/ansi-escape-codes/
 * @param graphics
 */
void drawGrayscale(vector<vector<int>> &graphics) {
    for (int x = 0; x < graphics.size(); x++) {
        for (int y = 0; y < graphics[x].size(); y++) {
            int code = normalizeIterationRange(graphics[x][y], 232, 255);
            cout << "\x1b[38;5;" << to_string(code) << "m " << "*" << "\x1b[0m";
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