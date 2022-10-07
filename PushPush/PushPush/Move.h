#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include "Consola.h"
#include "KeyCode.h"
#include "Draw.h"
#include "MapChoose.h"
#include "UnDo.h"


class MapChoose;
class UnDo;
class Move
{
	int posx = 7, posy = 5; 
	int nposx = 0, nposy = 0;
	int deltax = 0, deltay = 0;
	int mapnum = 1;		
	int goal = 0;		// �������� �� ���� ����
	int stagegoal = 1;	// ������������ ���� ���ǿ� �´� goal�� ����
	int mov = 0;	// ���� ������ Ƚ�� 
	int push = 0;	// ���� �� Ƚ��
	int stage1 = 0;		// stage1�� ����
	int stage2 = 0;		// stage2�� ����
	int stage3 = 0;		// stage3�� ����
	int stage4 = 0;		// stage4�� ����
	int stage5 = 0;		// stage5�� ����
	clock_t begin = 0, end = 0;
public :
	int getkey();
	void setPosx(int posx1);
	void setPosy(int posy1);
	void setMove(int mov1);
	void setPush(int push1);
	void setGoal(int goal1);
	void firstStage(Draw* draw, MapChoose* mapchoose, UnDo* undo);
	void secondStage(Draw* draw, MapChoose* mapchoose, UnDo* undo);
	void thirdStage(Draw* draw, MapChoose* mapchoose, UnDo* undo);
	void fourthStage(Draw* draw, MapChoose* mapchoose, UnDo* undo);
	void fifthStage(Draw* draw, MapChoose* mapchoose, UnDo* undo);
	void move(Draw* draw, MapChoose* mapchoose, UnDo* undo, Move* move);
	
};
#endif
