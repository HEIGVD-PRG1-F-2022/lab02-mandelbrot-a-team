//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include "../include/util.h"
#include "../include/menu.h"

using namespace std;

int main() {
#ifdef _WIN32
    setWindowsConsoleToUTF8();
#endif
    while (true) {
        showMainMenu();
    }
    return 0;
}