#include "map.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

int main() {
  
    hause h1(3);

    map m1(30, 120);
    m1.add_hause(3,30);
    m1.add_hause(h1,16, 70);
    m1.add_tree(5, 70);
    m1.add_tree(1, 50);
    m1.add_tree(3, 10);
    m1.add_tree(20, 30);
    m1.print_map();

    return 0;
}

