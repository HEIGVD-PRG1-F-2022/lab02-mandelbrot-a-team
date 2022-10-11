//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include <iostream>
#include "main.h"
const int MAX_ITERATION = 7004;
using namespace std;

int main() {
#ifdef _WIN32
    system(("chcp "s + std::to_string(CP_UTF8)).c_str()); //for colored output in console
#endif
    int width = 100, height = 100;
    vector<vector<int>> graphics(width, vector<int>(height));
    mandelbrotSet(graphics);
    //draw(graphics);
    //drawGrayscale(calcRect(-2, -1.12, 0.47, 1.12, 1000, 1000));
    drawGrayscale(calcRect(	-0.10936189822, 0.894921716226, 100, 100, 2.47/1000, 2.24/1000));
    //drawGrayscale(graphics);
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

    return ((currentMax-value)*1.0-currentMin) / (1.0*currentMax - currentMin) * (1.0*targetMax-targetMin) + 1.0*targetMin;
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
void drawGrayscale(const vector<vector<int>> &graphics) {
    for (int x = 0; x < graphics.size(); x++) {
        for (int y = 0; y < graphics[x].size(); y++) {
            int code = normalizeIterationRange(graphics[y][x], 0, 232);
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
// Calcule le mandelbrot depuis (X1, Y1) a (X2, Y2) avec nX points entre X1 et X2
// et nY points entre Y1 et Y2.
/**
 * Calcule le mandelbrot depuis (X1, Y1) a (X2, Y2)
 * avec nX points entre X1 et X2 et nY points entre Y1 et Y2.
 * @param X1 starting x coordinate
 * @param Y1 starting y coordinate
 * @param X2 ending x coordinate
 * @param Y2 ending y coordinate
 * @param nX number of points to calculate for X axis (resolution)
 * @param nY number of points to calculate for Y axis (resolution)
 * @return 2D vector of size nX*nY with number of iteration for each point
 */
vector<vector<int>> calcRect(double X1, double Y1, double X2, double Y2, int nX, int nY) {
    vector<vector<int>> set(nX, vector<int>(nY, 0));

    for(int x = 0; x < nX; x++) {
        for(int y = 0; y < nY; y++) {
            double x0 =  x * ((X2-X1) / nX) + X1;
            double y0 =  y * ((Y2-Y1) / nY) + Y1;
            set[x][y] = mandelbrot(x0,y0);
        }
    }

    return set;

}
/**
 * Calcule le mandelbrot autour de (X1, Y1) avec une largeur de dX et une hauteur de dY.
 * Le vecteur a nX points en largeur et nY points en hauteur.
 * @param X1 x coordinate of point around which we want to see the set
 * @param Y1 y coordinate of point around which we want to see the set
 * @param nX number of points to calculate for X axis (resolution)
 * @param nY number of points to calculate for Y axis (resolution)
 * @param dX size of interval around X1
 * @param dY size of interval around Y1
 * @return 2D vector of size nX*nY with number of iteration for each point
 */
vector<vector<int>> calcRect(double X1, double Y1, int nX, int nY, double dX, double dY) {

    return calcRect(X1-dX/2, Y1-dY/2.0, X1 + dX/2.0, Y1 + dY/2, nX, nY);
}