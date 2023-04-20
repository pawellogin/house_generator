#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

class roof {
	int height;
	char symbol;
	int color;
	int x, y;
	int** tab;
	static int count;

	friend class forest;

public:

	void printroof() {

		for (int i = 0; i < height; i++) {

			for (int j = 0; j < height * 2 - 1; j++) {
				cout << tab[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

	roof(int h, char s, int c, int xx, int yy) {
		count++;
		height = h;
		symbol = s;
		color = c;
		x = xx;
		y = yy;

		tab = new int* [height];
		for (int i = 0; i < height; i++) {
			tab[i] = new int[height * 2 - 1];
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < height * 2 - 1; j++) {
				tab[i][j] = 0;
			}
		}

		for (int i = 0; i < height; i++) {
			for (int j = height - i - 1; j < height + i; j++) {
				tab[i][j] = 1;
			}
		}

	}

	~roof() {
		count--;
		for (int i = 0; i < height; i++) {
			delete tab[i];
		}
		delete tab;
	}
};

