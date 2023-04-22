#pragma once

#include <iostream>
#include <windows.h>
#include "hause.h"
#include "tree.h"

using namespace std;


class map {

	int height;
	int width;
	char** tab;
	int** color_tab;
	border* frame;

public:

	map(int h, int w) {
		height = h;
		width = w;

		frame = new border(height, width, '#', 15);

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

		add_frame();
	}

	void add_frame() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				tab[i][j] = frame->get_tab(i, j);
			}
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {

				color_tab[i][j] = frame->get_color();

			}
		}
	}

	void add_hause(hause ha1, int x, int y) {
		for (int i = 0; i < ha1.get_height(); i++) {
			for (int j = 0; j < ha1.get_width(); j++) {
				tab[i + x][j + y] = ha1.get_tab(i, j);
			}
		}

		for (int i = 0; i < ha1.get_height(); i++) {
			for (int j = 0; j < ha1.get_width(); j++) {
				color_tab[i + x][j + y] = ha1.get_color(i, j);
			}
		}
	}

	void add_hause(int x, int y) {

		hause temp_h;

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 15; j++) {
				tab[i + x][j + y] = temp_h.get_tab(i, j);
			}
		}

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 15; j++) {
				color_tab[i + x][j + y] = temp_h.get_color(i, j);
			}
		}
	}

	void add_tree(int x, int y) {

		tree tree_temp;


		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				tab[i + x][j + y] = tree_temp.get_tab(i, j);
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				color_tab[i + x][j + y] = tree_temp.get_color(i, j);
			}
		}
	}

	

	void print_map() {

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
