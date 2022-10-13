//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include <vector>
#include <iostream>
#include "../include/navigation.h"
#include "../include/util.h"
#include "../include/draw.h"

using namespace std;

void displayNavigationCommandsHelper() {
    cout << "Navigation (w=Top, s=Bottom, a=Left, d=Right)\nZoom (+=Zoom in, -=Zoom out)\nExit (q)\n> ";
}

void drawWithNavigation(const vector<vector<int>> &fractalSet, int maxIteration) {
    clearConsole();
    drawColors(fractalSet, maxIteration);
    displayNavigationCommandsHelper();
}