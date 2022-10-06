//
// Project name : LAB 02 - Mandelbrot
// Project members :
// - Tranchida Rachel
// - Aellen Quentin
//

#include<iostream>
#include <vector>

using namespace std;
const int MAX_ITERATION = 1000;
#define PI 3.14
vector<vector<int>> graphics(100, vector<int>(100));
void mandelSet();
void draw();
int main()
{
    mandelSet();
    draw();
    return 0;
}

void mandelSet() {
    for(int x0 = 0; x0< graphics.size(); x0++) {
        for(int y0= 0; y0< graphics[x0].size(); y0++) {

            int codeCouleur;
            switch(iteration) {
                case MAX_ITERATION :
                    codeCouleur = 0;
                default :
                    codeCouleur = 1;
            }
            graphics[x0][y0] = codeCouleur;
            //cout << graphics[x0][y0];

        }
        cout << endl;
    }
}

void draw() {
    for(int x = 0; x < graphics.size(); x++) {
        for(int y = 0; y < graphics[x].size(); y++) {
            cout << graphics[x][y];
        }
        cout << endl;
    }
}
int mandelbrot(int x0, int y0) {
    int iteration = 0;
    double x = 0.0;
    double y = 0.0;
    while(x*x + y*y < 2*2 and iteration < MAX_ITERATION) {

        double xtemp = x*x - y*y + x0/100.0;
        y = 2*x*y + y0/100.0;
        x = xtemp;

        iteration = iteration + 1;
    }
    return iteration;
}