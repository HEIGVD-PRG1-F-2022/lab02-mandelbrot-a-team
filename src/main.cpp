//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include <iostream>
#include "../include/fractal_mandelbrot.h"
#include "../include/draw.h"
#include "../include/main.h"

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