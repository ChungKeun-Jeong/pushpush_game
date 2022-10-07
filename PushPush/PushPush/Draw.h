#ifndef DRAW_H
#define DRAW_H
#include <iostream>
#include "Consola.h"
#include "Move.h"
#include "UnDo.h"
using namespace std;

#define MAP_X1 10
#define MAP_Y1 10
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

class Draw
{	
	int mapData[10][10] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 1, 1, 1, 1, 0, 0},
		{1, 0, 2, 0, 0, 0, 0, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 4, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	const char* cellSymbol[7] = { "  ", "¢Æ¢Æ", "¡Ü", "|", "¡Ø", "--", "¡Ü" };
	int _mov = 0;
	int _push = 0;
	int _score = 0;
	int _mapnum = 1;
	int _time = 0;
public :
	void xyputstr(int x, int y, const char str[]);
	void setScore(int score);
	void setMapNum(int mapnum);
	void setMove(int mov);
	void setPush(int push);
	void setMap(int x, int y, int i);
	void setTime(int time);
	int getMap(int x, int y);
	void drawCell(int col, int row);
	void drawMap();
	void drawCharacter(int x, int y);
	void drawStart();
	void drawMenu();
	void drawFunction();
	void drawStageEnd();
};
#endif