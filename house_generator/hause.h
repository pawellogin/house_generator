#pragma once
#include <iostream>
#include <windows.h>
#include "roof.h"
#include
#include <vector>
#include <string>


using namespace std;

class forest {
	vector<roof*> roof_list;
	char** tab;
	int height, width;


public:


	void add_hause


	void add_roof(roof* t) {
		roof_list.push_back(t);

		for (int i = t->x; i < (t->x) + (t->height); i++) {

			for (int j = t->y; j < (t->y) + (t->height * 2 - 1); j++) {
				if (t->tab[i - t->x][j - t->y] == 1) {
					tab[i][j] = to_string(roof_list.size())[0];
				}
			}
		}
	}


	void print_forest() {

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		for (int i = 0; i < height; i++) {

			for (int j = 0; j < width; j++) {
				if (tab[i][j] != ' ') {
					SetConsoleTextAttribute(hConsole, stoi(string(1, tab[i][j])));
					cout << roof_list[stoi(string(1, tab[i][j])) - 1]->symbol;
					SetConsoleTextAttribute(hConsole, 15);
				}
				else cout << tab[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

	forest() {
		height = 20;
		width = 70;

		tab = new char* [height];
		for (int i = 0; i < height; i++) {
			tab[i] = new char[width];
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				tab[i][j] = ' ';
			}
		}
	}

	~forest() {

		for (int i = 0; i < height; i++) {
			delete tab[i];
		}
		delete tab;

		for (auto t : roof_list) {
			delete t;
		}

		roof_list.clear();
	}

};