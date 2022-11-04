//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include "../include/menu.h"
#include "../include/util.h"
#include "../include/navigation.h"
#include "../include/animation.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Display main menu into the terminal with a list of action todo
 */
void showMainMenu() {
    vector<string> options = {"Select your fractal", "Free navigation", "Auto zoom"};

    clearConsole();

    cout << "** Fractal set to " << FractalName[fractalSelected] << " **" << endl;

    cout << "--- Menu ---" << endl;

    for (int x = 0; x <= options.size(); x++) {
        if (x == 0) {
            cout << x << ") Exit" << endl;
            continue;
        }
        cout << x << ") " << options[x - 1] << endl;
    }

    short response = askChoice(options);

    switch (response) {
        case 0: {
            exit(0);
        }
        case 1: {
            showFractalMenu();
            break;
        }
        case 2: {
            startNavigation();
            break;
        }
        case 3: {
            startAnimation();
            break;
        }
    }
}

/**
 * Display fractal menu into the terminal fractal to select
 */
void showFractalMenu() {
    vector<string> options = {"Mandelbrot", "Julia", "Tricorn"};

    clearConsole();

    cout << "--- Fractal Menu ---" << endl;

    for (int x = 0; x <= options.size(); x++) {
        if (x == 0) {
            cout << x << ") Exit" << endl;
            continue;
        }
        cout << x << ") " << options[x - 1] << endl;
    }

    short response = askChoice(options);

    switch (response) {
        case 0:
            return;

        case 1:
            fractalSelected = Fractal::Mandelbrot;
            break;

        case 2:
            fractalSelected = Fractal::Julia;
            break;

        case 3:
            fractalSelected = Fractal::Tricorn;
            break;

    }
}

/**
 * Check the input of user based on the number of options available
 * @param optionsList reference list of all the option the user can select
 * @return value choose by the user into the range of available options
 */
short askChoice(const vector<string> &optionsList) {
    short maxValue = optionsList.size();
    short input;

    do {
        cout << "> ";
        cin >> input;
    } while (!(input >= 0 && input <= maxValue));

    return input;
}
Fractal getFractalSelected() {
    return fractalSelected;
}