//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include<iostream>
#include "main.h"

const int MAX_ITERATION = 1000;
using namespace std;

int main() {
    vector<vector<int>> graphics(100, vector<int>(100));
    graphics = mandelbrotSet(graphics);
    draw(graphics);
    return 0;
}

vector<vector<int>> mandelbrotSet(vector<vector<int>> graphics) {
    for (int x = 0; x < graphics.size(); x++) {
        for (int y = 0; y < graphics[x].size(); y++) {
            int iteration = mandelbrot(x * ((2.47) / graphics.size()) - 2.0, -y * ((2.24) / graphics[x].size()) + 1.12);
            int codeCouleur = iteration == MAX_ITERATION ? 0 : 1;
            //x and y are reversed
            graphics[y][x] = codeCouleur;
        }
    }
    return graphics;
}

/**
 * Display 2D array into terminal
 * @param vector<vector<int>> graphics
 */
void draw(vector<vector<int>> graphics) {
    for (int x = 0; x < graphics.size(); x++) {
        for (int y = 0; y < graphics[x].size(); y++) {
            cout << graphics[x][y];
        }
        cout << endl;
    }
}

/**
 * Calculate maximum number of mandelbrot iteration before
 * @param x0
 * @param y0
 * @return number of iteration
 */
int mandelbrot(double x0, double y0) {
    int iteration = 0;
    double x = 0.0;
    double y = 0.0;
    while (x * x + y * y <= 2 * 2 and iteration < MAX_ITERATION) {
        double xtemp = x * x - y * y + x0;
        y = 2 * x * y + y0;
        x = xtemp;

        iteration = iteration + 1;
    }
    return iteration;
}