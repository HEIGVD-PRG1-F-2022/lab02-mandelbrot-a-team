//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#ifndef MANDELBROT_MENU_H
#define MANDELBROT_MENU_H

#include <vector>
#include <string>

enum Fractal {
    Mandelbrot,
    Julia,
    Tricorn
};

void showMainMenu();

short askChoice(const std::vector<std::string> &);

#endif //MANDELBROT_MENU_H
