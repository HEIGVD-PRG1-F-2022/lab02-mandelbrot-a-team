//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include <iostream>
#include "fractal_mandelbrot.h"
#include "util.h"
#include "main.h"

const int MAX_ITERATION = 7004;
using namespace std;

int main() {
#ifdef _WIN32
    system(("chcp "s + std::to_string(CP_UTF8)).c_str()); //for colored output in console
#endif
    int width = 100, height = 100;

    //drawGrayscale(calcRect(-2, -1.12, 0.47, 1.12, 1000, 1000));
    drawGrayscale(calcRect(-0.10936189822, 0.894921716226, 100, 100, 2.47 / 1000, 2.24 / 1000));
    return 0;
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
            int code = normalizeRange(graphics[y][x], 0, 232);
            cout << "\x1b[38;5;" << to_string(code) << "m " << "*" << "\x1b[0m";
        }
        cout << endl;
    }
}