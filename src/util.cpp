//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include <string>
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
    return ((currentMax-value) * 1.0 - currentMin) / (1.0 * currentMax - currentMin) * (1.0 * targetMax - targetMin) +
           1.0 * targetMin;

}

#ifdef _WIN32

/**
 * Set Windows console format to UTF-8 to support display of colors
 */
void SetWConsoleToUTF8() {
    system(("chcp "s + std::to_string(CP_UTF8)).c_str()); //for colored output in console
}

#endif
