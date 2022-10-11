//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include "../include/fractal_mandelbrot.h"
#include "../include/draw.h"
#include "../include/util.h"

using namespace std;

int main() {
#ifdef _WIN32
    SetWConsoleToUTF8();
#endif
    static const int MAX_ITERATION = 100;

    int width = 100, height = 100;

    //drawGrayscale(calcRect(-2, -1.12, 0.47, 1.12, 1000, 1000));
    drawGrayscale(calcRect(-0.10936189822, 0.894921716226, 100, 100, 2.47 / 1000, 2.24 / 1000));
    return 0;
}