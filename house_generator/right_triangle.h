#pragma once
#include <iostream>
#include <windows.h>
#include "shape.h"

using namespace std;

class right_triangle : public shape {

	char direction;

	void draw() override {

		tab = new char* [width];
		for (int i = 0; i < width; i++) {
			tab[i] = new char[width];
		}

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < width; j++) {
				tab[i][j] = ' ';
			}
		}

		if (direction == 'r' || direction == 'R') {
			for (int i = 0; i < width; i++) {
				for (int j = 0; j <= i; j++) {
					tab[i][j] = symbol;
				}
			}
		}
		else if (direction == 'l' || direction == 'L') {
			for (int i = 0; i < width; i++) {
				for (int j = width-1-i; j <width ; j++) {
					tab[i][j] = symbol;
				}
			}
		}
	}

public:

	right_triangle(int w, char s, int c,char dir) : shape(w, w, s, c) {
		direction = dir;
		draw();

	}

	void print() override {


		for (int i = 0; i < width; i++) {

			for (int j = 0; j < width ; j++) {
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


	~right_triangle() {
		for (int i = 0; i < width; i++) {
			delete[] tab[i];
		}
		delete[] tab;
	}

};
