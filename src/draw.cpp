//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include <iostream>

#include "../include/util.h"
#include "../include/draw.h"

using namespace std;

/**
 * Display 2D array into terminal
 * @param fractalSet
 */
void draw(const vector <vector<int>> &fractalSet) {
    for (int x = 0; x < fractalSet.size(); x++) {
        for (int y = 0; y < fractalSet[x].size(); y++) {
            cout << (fractalSet[x][y] == 1000 ? '0' : '1');
        }
        cout << endl;
    }
}

/**
 * Display 2D array into terminal with grayscale (need compatible terminal)
 * More information here : https://tforgione.fr/posts/ansi-escape-codes/
 * @param fractalSet
 */
void drawGrayscale(const vector <vector<int>> &fractalSet) {
    for (int x = 0; x < fractalSet.size(); x++) {
        for (int y = 0; y < fractalSet[x].size(); y++) {
            int code = normalizeRange(fractalSet[y][x], 232, 255);
            cout << "\x1b[38;5;" << to_string(code) << "m " << "*" << "\x1b[0m";
        }
        cout << endl;
    }
}

/**
 * Display 2D array into terminal with grayscale (need compatible terminal)
 * More information here : https://tforgione.fr/posts/ansi-escape-codes/
 * @param fractalSet
 */
void drawColors(const vector <vector<int>> &fractalSet) {
    for (int x = 0; x < fractalSet.size(); x++) {
        for (int y = 0; y < fractalSet[x].size(); y++) {
            int code = normalizeRange(fractalSet[y][x], 0, 232);
            cout << "\x1b[38;5;" << to_string(code) << "m " << "*" << "\x1b[0m";
        }
        cout << endl;
    }
}
