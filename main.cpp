#include <iostream>
#include "Family.h"
#include "Cat.h"
#include "Mother.h"
#include "Father.h"
#include "Kid1.h"
#include "Human.h"
#include <vector>

using namespace std;


void start_simulation() {
    srand((unsigned int) time(NULL));
    std::cout << "Simulation started." << std::endl;

    int step = 1;

    while (true) {
        std::cout << "Simulation step - " << step << std::endl;
        cat.doStep();
        for (Human *h : family) {
            h->doStep();
        }
        step++;
        cout << "Next step (y/n):";
        char ch = '0';
        cin >> ch;
        if (ch != 'y') {
            break;
        }
    }

}

int main() {
   family.push_back(new Mother());
   family.push_back(new Father());
   family.push_back(new Kid1());

   start_simulation();

   return 0;
}

