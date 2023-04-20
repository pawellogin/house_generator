#include "hause.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>


int roof::count = 0;

using namespace std;

void add_roof_to_forest(forest* f);

int main() {

    int choice = 0;

    forest forest1;
    forest1.add_roof(new roof(3, '#', 3, 3, 3));
    forest1.add_roof(new roof(4, '*', 8, 7, 10));
    forest1.add_roof(new roof(5, '@', 5, 8, 11));

    while (1) {

        forest1.print_forest();

        cout << "1. add_roof()" << endl;
        cout << "2. exit(0)" << endl;

        cout << "enter choice" << endl;
        Sleep(1000);
        cin >> choice;
        system("cls");


        switch (choice) {

        case 1:
            add_roof_to_forest(&forest1); break;

        case 2: exit(0); break;

        default: break;
        }

    }

    return 0;
}

void add_roof_to_forest(forest* f) {

    int height;
    char symbol;
    int color;
    int x;
    int y;

    system("cls");
    Sleep(300);

    cout << "type in height, symbol, color (0-15) of a roof, x and y cords" << endl;
    cin >> height;
    cin >> symbol;
    cin >> color;
    cin >> x;
    cin >> y;

    system("cls");

    f->add_roof(new roof(height, symbol, color, x, y));


}

