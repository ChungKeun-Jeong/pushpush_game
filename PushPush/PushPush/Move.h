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
	int goal = 0;		// 목적지에 들어간 짐의 개수
	int stagegoal = 1;	// 스테이지별로 종료 조건에 맞는 goal의 개수
	int mov = 0;	// ♣이 움직인 횟수 
	int push = 0;	// 짐을 민 횟수
	int stage1 = 0;		// stage1의 점수
	int stage2 = 0;		// stage2의 점수
	int stage3 = 0;		// stage3의 점수
	int stage4 = 0;		// stage4의 점수
	int stage5 = 0;		// stage5의 점수
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
