#include<iostream>
#include <vector>

using namespace std;

#define PI 3.14
vector<vector<int>> graphics(100, vector<int>(100));
void mandelSet();
int main()
{
    mandelSet();

    return 0;
}

void mandelSet() {
    for(int x0 = 0; x0< graphics.size(); x0++) {
        for(int y0= 0; y0< graphics[x0].size(); y0++) {
            int iteration = 0;
            const int max_iteration = 1000;
            double x = 0.0;
            double y = 0.0;
            while(x*x + y*y < 2*2 and iteration < max_iteration) {

                double xtemp = x*x - y*y + x0;
                y = 2*x*y + y0;
                x = xtemp;

                iteration = iteration + 1;
            }
            int codeCouleur;
            switch(iteration) {
                case max_iteration :
                    codeCouleur = 0;
                default :
                    codeCouleur = 1;
            }
            graphics[x0][y0] = codeCouleur;
            cout << graphics[x0][y0];

        }
        cout << endl;
    }
}
