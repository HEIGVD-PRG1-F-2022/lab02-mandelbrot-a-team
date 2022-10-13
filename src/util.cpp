//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include <string>
#include <cmath>
#include "../include/util.h"

using namespace std;

/**
 * Will normalize value between a new defined range
 * @param value the current value you want to match your new range
 * @param targetMin lowest limit of your new range
 * @param targetMax highest limit of your new range
 * @param currentMin lowest value possible of current value range
 * @param currentMax highest value possible of current value range
 * @return equivalent interpretation of the value in the specified new range
 */
int normalizeRange(int value, int targetMin, int targetMax, int currentMin, int currentMax) {
    return ((currentMax - value) * 1.0 - currentMin) / (1.0 * currentMax - currentMin) * (1.0 * targetMax - targetMin) +
           1.0 * targetMin;
}

float normalizeRGB(int iteration, int maxIteration){
    double s = 3;
    double a = pow((double)iteration/maxIteration,s);
    double N = 255;
    double b = pow(a*N, 1.5);
    double res = fmod(b, N);
    return res;
}

#ifdef _WIN32

/**
 * Set Windows console format to UTF-8 to support display of colors
 */
void setWindowsConsoleToUTF8() {
    system(("chcp "s + std::to_string(CP_UTF8)).c_str()); //for colored output in console
}

#endif

/**
 * Clear console with system cmd based on if it's a Windows or a UNIX system
 */
void clearConsole() {
    char cmd[] = "clear";
#ifdef _WIN32
    cmd = "cls"
#endif
    system(cmd);
}