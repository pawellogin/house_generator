#pragma once
#include <iostream>
#include <windows.h>
#include "shape.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;

class tree : public shape {

	rectangle* trunk;
	triangle* top;
	int** color_tab;

	void draw() override {

		tab = new char* [height];
		for (int i = 0; i < height; i++) {
			tab[i] = new char[width];
			for (int j = 0; j < width; j++) {
				tab[i][j] = ' ';
			}
		}

		color_tab = new int* [height];
		for (int i = 0; i < height; i++) {
			color_tab[i] = new int[width];
			for (int j = 0; j < width; j++) {
				color_tab[i][j] = 15;
			}
		}
		
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 1; j++) {
				tab[i+2][j+1] = trunk->get_tab(i, j);
				
			}
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 1; j++) {
				color_tab[i + 2][j + 1] = trunk->get_color();

			}
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				tab[i][j] = top->get_tab(i, j);
			}
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				color_tab[i][j] = top->get_color();
			}
		}


	}
public:

	tree() : shape(0, 0, ' ', 15) {
		shape::height = 4;
		shape::width = 3;

		trunk = new rectangle (2, 1, '|', 9);
		top = new triangle (2, '/', 12);
		
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

	int get_color(int x, int y) {
		return color_tab[x][y];
	}


	~tree() {
		for (int i = 0; i < width; i++) {
			delete[] tab[i];
		}
		delete[] tab;
	}

};

