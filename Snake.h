#pragma once
#include <iostream>
#include "Utilities.hpp"
#include <vector>
#include <conio.h>
#include <Windows.h>

class Snake {

private:
	const int width = 20;
	const int height = 20;
	const int up = 1;
	const int down = 2;
	const int left = 3;
	const int right = 4;
	int dir;
	int sleepTime = 300;
	bool isOver;
	int headx = 0;
	int heady = 0;
	int p_headx = 0;
	int p_heady = 0;
	int fruitx = 0;
	int fruity = 0;
	int score = 0;
	char inp;
	int prev_dir;
	int tailx[300];
	int taily[300];

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	bool boundCheck(int x, int y);
	int getScore();
	void incrementScore();
	void incrementTail();
	void clearSnake();
	bool headCollide();
	bool headCollideWithBody();
	void drawBorder();
	

public:
	Snake();
	void snakeSetUp();
	void fruitSetUp();
	void draw();
	void logic();
	bool done();
};
