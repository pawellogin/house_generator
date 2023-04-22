#pragma once
#include <iostream>
#include <windows.h>
#include "shape.h"

using namespace std;

class rectangle : public shape {

	void draw() override {

		tab = new char* [height];
		for (int i = 0; i < height; i++) {
			tab[i] = new char[width];
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				tab[i][j] = symbol;
			}
		}
	}


public:

	rectangle(int h, int w, char s, int c) : shape(h, w, s, c) {

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
	


	~rectangle() {
		for (int i = 0; i < height; i++) {
			delete[] tab[i];
		}
		delete[] tab;
	}
};

