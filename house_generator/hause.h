#pragma once
#include <iostream>
#include <windows.h>
#include "triangle.h"
#include "rectangle.h"
#include "right_triangle.h"
#include "border.h"

using namespace std;

class hause : public shape {

	char** tab;
	int** color_tab;
	int col;

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
		
	}

	void make_full_hause() {

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		triangle roof(6, '^', 11+col);
		right_triangle left_roof(2, '^', 11 + col, 'l');
		right_triangle right_roof(2, '^', 11 + col, 'r');
		rectangle wall(6, 11, '#', 3 + col);
		border door(5, 4, '#', 5 + col);
		border window(3, 3, '#', 9 + col);

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 11; j++) {
				if (wall.get_tab(i, j) != ' ') {
					tab[i + 6][j + 2] = wall.get_tab(i, j);
					color_tab[i + 6][j + 2] = wall.get_color();
				}
			}
		}

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 11; j++) {
				if (roof.get_tab(i, j) != ' ') {
					tab[i + 0][j + 2] = roof.get_tab(i, j);
					color_tab[i + 0][j + 2] = roof.get_color();
				}
			}
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (left_roof.get_tab(i, j) != ' ') {
					tab[i + 6][j + 0] = left_roof.get_tab(i, j);
					color_tab[i + 6][j + 0] = left_roof.get_color();
				}
			}
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (right_roof.get_tab(i, j) != ' ') {
					tab[i + 6][j + 13] = right_roof.get_tab(i, j);
					color_tab[i + 6][j + 13] = right_roof.get_color();
				}
			}
		}
		
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 4; j++) {
				if (door.get_tab(i, j) != ' ') {
					tab[i + 7][j + 3] = door.get_tab(i, j);
					color_tab[i + 7][j + 3] = door.get_color();
				}
				else tab[i + 7][j + 3] = ' ';
			}
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (window.get_tab(i, j) != ' ') {
					tab[i + 7][j + 9] = window.get_tab(i, j);
					color_tab[i + 7][j + 9] = window.get_color();
				}
				else tab[i + 7][j + 9] = ' ';
			}
		}

	}

public:

	hause(int c) : shape(0, 0, ' ', 15) {
		int h = 12 ;
		int w = 15 ;

		col = c;


		
		shape::height = h;
		shape::width = w;

		

		draw();
		make_full_hause();
	}

	hause() : shape(12, 15, ' ', 15) {
		
		draw();
		make_full_hause();
	}

	char get_tab(int x, int y) {
		return tab[x][y];
	}

	int get_color(int x, int y) {
		return color_tab[x][y];
	}

	int get_height() {
		return height;
	}

	int get_width() {
		return width;
	}

	void print() override {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				SetConsoleTextAttribute(hConsole, color_tab[i][j]);
				cout << tab[i][j];
				SetConsoleTextAttribute(hConsole, 15);
			}
			cout << endl;
		}
	}
};