#pragma once
#include <iostream>
#include <windows.h>
#include "rectangle.h"

using namespace std;

class border : public rectangle {

	void draw() override {

		tab = new char* [height];
		for (int i = 0; i < height; i++) {
			tab[i] = new char[width];
			for (int j = 0; j < width; j++) {
				tab[i][j] = ' ';
			}
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (i == 0 || i == height - 1) {
					tab[i][j] = symbol;  // top and bottom rows
				}
				else if (j == 0 || j == width - 1) {
					tab[i][j] = symbol;  // left and right columns
				}
			}
		}
	}

public:

	border(int h, int w, char s, int c) : rectangle(h, w, s, c) {

		draw();

	}

	void print() override {


		for (int i = 0; i < height; i++) {

			for (int j = 0; j < width; j++) {
				cout << tab[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

	char get_tab(int x, int y) {
		return tab[x][y];
	}

	int get_color() {
		return color;
	}


	/*~border() {
		for (int i = 0; i < height; i++) {
			delete[] tab[i];
		}
		delete[] tab;
	}*/
};



