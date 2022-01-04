#include "Snake.h"

using namespace std;

void Snake::moveUp()
{
	clearSnake();
	p_headx = headx;
	p_heady = heady;
	int temp = 0;
	temp = heady - 1;
	if (boundCheck(headx, temp)) {
		--heady;
	}
	else if (temp == 0) {
		heady = height - 1;
	}
	if (headCollideWithBody()) {
		isOver = true;
		return;
	}
	incrementScore();
	incrementTail();
}

void Snake::moveDown()
{
	clearSnake();
	p_headx = headx;
	p_heady = heady;
	int temp = 0;
	temp = heady + 1;
	if (boundCheck(headx, temp)) {
		++heady;
	}
	else if (temp == height) {
		heady = 1;
	}
	if (headCollideWithBody()) {
		isOver = true;
		return;
	}
	incrementScore();
	incrementTail();
}

void Snake::moveLeft()
{
	clearSnake();
	p_headx = headx;
	p_heady = heady;
	int temp = 0;
	temp = headx - 1;
	if (boundCheck(temp, heady)) {
		--headx;
	}
	else if (temp == 0) {
		headx = width - 1;
	}
	if (headCollideWithBody()) {
		isOver = true;
		return;
	}
	incrementScore();
	incrementTail();
}

void Snake::moveRight()
{
	clearSnake();
	p_headx = headx;
	p_heady = heady;
	int temp = 0;
	temp = headx + 1;
	if (boundCheck(temp, heady)) {
		++headx;
	}
	else if (temp == width) {
		headx = 1;
	}
	if (headCollideWithBody()) {
		isOver = true;
		return;
	}
	incrementScore();
	incrementTail();
}

Snake::Snake()
{
	ShowConsoleCursor(false);
	randomNumberSeed();
	isOver = false;
	drawBorder();
	dir = right;
	prev_dir = right;
}

void Snake::drawBorder()
{
	// draw border
	clearScreen();
	for (int row = 0; row <= height; row++) {
		for (int col = 0; col <= width; col++) {
			if (row == 0 || row == height) {
				placeXY(col, row);
				cout << "*" << flush;
			}
			else if (col == 0 || col == width) {
				placeXY(col, row);
				cout << "*" << flush;
			}
		}
		cout << "\n" << flush;
	}

	placeXY(0, height + 2);
	cout << "Score: " << getScore()  << " (" << inp << ")" << endl;
}

void Snake::snakeSetUp()
{
	headx = randomNumber() % (width - 1) + 1;
	heady = randomNumber() % (height - 1) + 1;
}

void Snake::fruitSetUp()
{
	fruitx = randomNumber() % (width - 1) + 1;
	fruity = randomNumber() % (height - 1) + 1;
	if (fruitx == headx && fruity == heady) {
		fruitx = randomNumber() % (width - 1) + 1;
		fruity = randomNumber() % (height - 1) + 1;
	}

	for (int i = 0; i < score; i++) {
		if (fruitx == tailx[i] && fruity == taily[i]) {
			fruitx = randomNumber() % (width - 1) + 1;
			fruity = randomNumber() % (height - 1) + 1;
		}
	}

	placeXY(fruitx, fruity);
	cout << "F" << flush;
}

void Snake::draw()
{
	// print head
	placeXY(headx, heady);
	cout << "O" << flush;

	// print tail
	for (int i = 0; i < score; i++) {
		placeXY(tailx[i], taily[i]);
		cout << "o" << flush;
	}

	// print score
	placeXY(0, height + 2);
	cout << "Score: " << getScore() << " (" << inp << ")" << endl;
}

void Snake::logic()
{
	while (prev_dir == dir) {
		if (_kbhit())
		{
			switch (getChar())
			{
			case 'a':
			case 'A':
				dir = left;
				inp = 'a';
				break;
			case 'd':
			case 'D':
				dir = right;
				inp = 'd';
				break;
			case 'w':
			case 'W':
				dir = up;
				inp = 'w';
				break;
			case 's':
			case 'S':
				dir = down;
				inp = 's';
				break;
			}
		}

		if (score > 5 && score < 10) {
			sleepTime = 250;
		}
		else if (score > 10 && score < 20) {
			sleepTime = 175;
		}
		else if (score > 25) {
			sleepTime = 100;
		}

		if (dir == left) {
			moveLeft();
		}
		else if (dir == right) {
			moveRight();
		}
		else if (dir == up) {
			moveUp();
		}
		else if (dir == down) {
			moveDown();
		}
		draw();
		Sleep(sleepTime);
	}

	prev_dir = dir;
}

void Snake::incrementScore()
{
	if (headCollide()) {
		score++;
		fruitSetUp();
	}
}

void Snake::incrementTail()
{	
	for (int i = score - 1; i >= 0; i--) {
		// move coord to next elem
		tailx[i + 1] = tailx[i];
		taily[i + 1] = taily[i];
	}
	// copy head coord to first elem
	tailx[0] = p_headx;
	taily[0] = p_heady;
}

void Snake::clearSnake()
{
	placeXY(headx, heady);
	cout << " " << flush;

	for (int i = 0; i < score; i++) {
		placeXY(tailx[i], taily[i]);
		cout << " " << flush;
	}
}

bool Snake::headCollide()
{
	if (headx == fruitx && heady == fruity) {
		return true;
	}
	return false;
}

bool Snake::headCollideWithBody()
{
	for (int i = 0; i < score; i++) {
		if (headx == tailx[i] && heady == taily[i]) {
			return true;
		}
	}
	return false;
}

int Snake::getScore()
{
	return score;
}

bool Snake::done()
{
	if (isOver){
		placeXY(0, height + 4);
		cout << "Game Over!" << endl;
	}
	return isOver;
}

bool Snake::boundCheck(int x, int y)
{
	return (x > 0 && x < width) && (y > 0 && y < height);
}
