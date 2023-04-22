#pragma once
#include <iostream>
#include <windows.h>
#include "shape.h"

using namespace std;

class triangle : public shape {
	void draw() override {

		tab = new char* [width];
		for (int i = 0; i < width; i++) {
			tab[i] = new char[width * 2 - 1];
		}

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < width * 2 - 1; j++) {
				tab[i][j] = ' ';
			}
		}

		for (int i = 0; i < width; i++) {
			for (int j = width - i - 1; j < width + i; j++) {
				tab[i][j] = symbol;
			}
		}
	}
public:

	triangle(int h, char s, int c) : shape(h,h,s,c) {
		
		draw();

	}

	

	void print() override {


		for (int i = 0; i < width; i++) {

			for (int j = 0; j < width * 2 - 1; j++) {
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


	~triangle() {
		for (int i = 0; i < width; i++) {
			delete[] tab[i];
		}
		delete[] tab;
	}

};

