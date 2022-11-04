//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#ifndef MANDELBROT_UTIL_H
#define MANDELBROT_UTIL_H

#ifdef _WIN32

#include <windows.h>

void setWindowsConsoleToUTF8();

#else

#include <stdlib.h>
#include <unistd.h>

#endif

int normalizeRange(int value, int targetMin, int targetMax, int currentMin = 0, int currentMax = 1000);

void clearConsole();

void setConsoleCursorToStart();

void wait(int milliseconds);

#endif //MANDELBROT_UTIL_H
