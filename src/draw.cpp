//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include <iostream>
#include <cmath>

#include "../include/util.h"
#include "../include/draw.h"

using namespace std;

/**
 * Display 2D array into terminal
 * @param fractalSet
 */
void draw(const vector <vector<int>> &fractalSet) {
    string content = "";
    for (int x = 0; x < fractalSet.size(); x++) {
        for (int y = 0; y < fractalSet[x].size(); y++) {
            content += (fractalSet[x][y] == 1000 ? '0' : '1');
        }
        content += "\n";
    }
    cout << content;
}

/**
 * Display 2D array into terminal with grayscale (need compatible terminal)
 * More information here : https://tforgione.fr/posts/ansi-escape-codes/
 * @param fractalSet
 */
void drawGrayscale(const vector <vector<int>> &fractalSet) {
    string content = "";
    for (int x = 0; x < fractalSet.size(); x++) {
        for (int y = 0; y < fractalSet[x].size(); y++) {
            int code = normalizeRange(fractalSet[y][x], 232, 255);
            content += "\x1b[38;5;" + to_string(code) + "m  *\x1b[0m";
        }
        content += "\n";
    }
    cout << content;
}

/**
 * Display 2D array into terminal with grayscale (need compatible terminal)
 * More information here : https://tforgione.fr/posts/ansi-escape-codes/
 * @param fractalSet
 */
void drawColors(const vector <vector<int>> &fractalSet, int max_iteration) {
    string content = "";
    for (int x = 0; x < fractalSet.size(); x++) {
        for (int y = 0; y < fractalSet[x].size(); y++) {
            int code = normalizeRange(fractalSet[y][x], 0, 232, 0, max_iteration);
            content += "\x1b[38;5;" + to_string(code) + "m *\x1b[0m";
        }
        content += "\n";
    }
    cout << content;
}

/**
 * Display 2D array into terminal with grayscale (need compatible terminal)
 * More information here : https://tforgione.fr/posts/ansi-escape-codes/
 * @param fractalSet
 */
void drawRGB(const vector <vector<int>> &fractalSet, int max_iteration) {
    string content = "";
    for (int x = 0; x < fractalSet.size(); x++) {
        for (int y = 0; y < fractalSet[x].size(); y++) {
            float v = normalizeRGB(fractalSet[y][x], max_iteration);

            content += "\x1b[38;2;" + to_string((int)(v*255)) + ";" + to_string((int)(v*255)) + ";" + to_string((int)(v*255)) + "m *\x1b[0m";
        }
        content += "\n";
    }
    cout << content;
}
