#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

class shape {

protected:
	int height;
	int width;
	char symbol;
	int color;
	char** tab;

	virtual void draw() = 0;


public:

	shape(int h, int w, char s,int c) : height(h), width(w), symbol(s), color(c) {

		tab = {};
	}

	virtual void print() = 0;



};
