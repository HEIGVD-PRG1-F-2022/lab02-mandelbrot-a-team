//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include "../include/menu.h"
#include "../include/util.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


static Fractal fractalSelected = Mandelbrot;

void showMainMenu() {
    vector<string> options = {"Select your fractal", "Free navigation", "Auto zoom"};

    setConsoleCursorToStart();

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
            return;
            break;
        }
        case 1: {
            cout << "case 1";
            break;
        }
        case 2: {
            cout << "case 2";
            break;
        }
        case 3: {
            cout << "case 3";
            break;
        }
    }
}

short askChoice(const vector<string> &optionsList) {
    short maxValue = optionsList.size();
    short input;

    do {
        cout << "> ";
        cin >> input;
    } while (!(input >= 0 && input <= maxValue));

    return input;
}