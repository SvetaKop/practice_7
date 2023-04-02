#include <iostream>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <conio.h>
using namespace std;

void goToXY(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

const int hurdleCount = 4;

class Flappy_Bird {
	int hurdlePos[hurdleCount][2];
	int screenWidth = 79;
	int screenHeight = 25;
	int hurdleGap = 8;
	int betweenHurdleGap;

	int birdX = 17;
	int birdY = 15;

	int jump = 4;
	int score = 0;
public:
	Flappy_Bird() {
		srand(time(NULL));

		betweenHurdleGap = (screenWidth / hurdleCount) + 10;
		for (int i = 0; i < hurdleCount; i++) {
			hurdlePos[i][0] = betweenHurdleGap * (i + 1);

			int breakPos = rand() % (screenHeight / 3) + hurdleGap;
			hurdlePos[i][1] = breakPos;
		}
	}
