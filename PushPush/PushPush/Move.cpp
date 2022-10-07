#include "Move.h"

int Move::getkey() {
	int key = _getch();
	return (key == 0xe0) ? (0xe000 | _getch()) : key;
}

void Move::setPosx(int posx1) {
	posx = posx1;
}

void Move::setPosy(int posy1) {
	posy = posy1;
}

void Move::setMove(int mov1) {
	mov = mov1;
}

void Move::setPush(int push1) {
	push = push1;
}

void Move::setGoal(int goal1) {
	goal = goal1;
}

void Move::firstStage(Draw* draw, MapChoose* mapchoose, UnDo* undo) {
	system("cls");
	undo->deleteUndo();
	begin = clock();
	goal = 0;
	posx = 7;
	posy = 5;
	mapnum = 1;
	stagegoal = 1;
	mov = 0;
	push = 0;
	mapchoose->setMapChoose(mapnum);
	mapchoose->mapchoose(draw);
	draw->setMapNum(mapnum);
	draw->drawMap();
	draw->drawMenu();
	draw->setMove(mov);
	draw->setPush(push);
	draw->setScore(stage1);
	draw->drawFunction();
	draw->drawCharacter(posx, posy);
}

void Move::secondStage(Draw* draw, MapChoose* mapchoose, UnDo* undo) {
	system("cls");
	undo->deleteUndo();
	begin = clock();
	goal = 0;
	posx = 1;
	posy = 1;
	mapnum = 2;
	stagegoal = 1;
	mov = 0;
	push = 0;
	mapchoose->setMapChoose(mapnum);
	mapchoose->mapchoose(draw);
	draw->setMapNum(mapnum);
	draw->drawMap();
	draw->drawMenu();
	draw->setMove(mov);
	draw->setPush(push);
	draw->setScore(stage2);
	draw->drawFunction();
	draw->drawCharacter(posx, posy);
}

void Move::thirdStage(Draw* draw, MapChoose* mapchoose, UnDo* undo) {
	system("cls");
	undo->deleteUndo();
	begin = clock();
	goal = 0;
	posx = 3;
	posy = 5;
	mapnum = 3;
	stagegoal = 2;
	mov = 0;
	push = 0;
	mapchoose->setMapChoose(mapnum);
	mapchoose->mapchoose(draw);
	draw->setMapNum(mapnum);
	draw->drawMap();
	draw->drawMenu();
	draw->setMove(mov);
	draw->setPush(push);
	draw->setScore(stage3);
	draw->drawFunction();
	draw->drawCharacter(posx, posy);
}

void Move::fourthStage(Draw* draw, MapChoose* mapchoose, UnDo* undo) {
	system("cls");
	undo->deleteUndo();
	begin = clock();
	goal = 0;
	posx = 2;
	posy = 2;
	mapnum = 4;
	stagegoal = 3;
	mov = 0;
	push = 0;
	mapchoose->setMapChoose(mapnum);
	mapchoose->mapchoose(draw);
	draw->setMapNum(mapnum);
	draw->drawMap();
	draw->drawMenu();
	draw->setMove(mov);
	draw->setPush(push);
	draw->setScore(stage4);
	draw->drawFunction();
	draw->drawCharacter(posx, posy);
}

void Move::fifthStage(Draw* draw, MapChoose* mapchoose, UnDo* undo) {
	system("cls");
	undo->deleteUndo();
	begin = clock();
	goal = 0;
	posx = 2;
	posy = 2;
	mapnum = 5;
	stagegoal = 3;
	mov = 0;
	push = 0;
	mapchoose->setMapChoose(mapnum);
	mapchoose->mapchoose(draw);
	draw->setMapNum(mapnum);
	draw->drawMap();
	draw->drawMenu();
	draw->setMove(mov);
	draw->setPush(push);
	draw->setScore(stage5);
	draw->drawFunction();
	draw->drawCharacter(posx, posy);
}

void Move::move(Draw* draw, MapChoose* mapchoose, UnDo* undo, Move* move) {
	_setcursortype(_NOCURSOR);
	draw->drawStart();
	firstStage(draw, mapchoose, undo);
	begin = clock();

	while (1) {
		int key = getkey();
		if (key == 'q') break;	
		if (key == 'r') {	// r 누르면 화면 초기화
			for (int i = 0; i < 10; i++) {	// 짐 삭제
				for (int j = 0; j < 10; j++) {
					if (draw->getMap(j, i) == 2) {
						draw->setMap(j, i, 0);
					}
				}
			}
			if (mapnum == 1) {
				undo->deleteUndo();
				begin = clock();
				goal = 0;
				posx = 7;
				posy = 5;
				mov = 0;
				push = 0;
				draw->setMap(2, 3, 2);	// 짐 초기 위치에 다시 생성
				draw->setMap(2, 7, 4);	// 목적지 초기 위치에 다시 생성
			}
			else if (mapnum == 2) {
				undo->deleteUndo();
				begin = clock();
				goal = 0;
				posx = 1;
				posy = 1;
				mov = 0;
				push = 0;
				draw->setMap(2, 2, 2);
				draw->setMap(8, 3, 4);
			}
			else if (mapnum == 3) {
				undo->deleteUndo();
				begin = clock();
				goal = 0;
				posx = 3;
				posy = 5;
				mov = 0;
				push = 0;
				draw->setMap(3, 3, 2);
				draw->setMap(6, 6, 2);
				draw->setMap(6, 4, 4);
				draw->setMap(5, 7, 4);
			}
			else if (mapnum == 4) {
				undo->deleteUndo();
				begin = clock();
				goal = 0;
				posx = 2;
				posy = 2;
				mov = 0;
				push = 0;
				draw->setMap(4, 2, 2);
				draw->setMap(2, 7, 2);
				draw->setMap(7, 7, 2);
				draw->setMap(4, 4, 4);
				draw->setMap(5, 4, 4);
				draw->setMap(5, 5, 4);
			}
			else if (mapnum == 5) {
				undo->deleteUndo();
				begin = clock();
				goal = 0;
				posx = 2;
				posy = 2;
				mov = 0;
				push = 0;
				draw->setMap(3, 4, 2);
				draw->setMap(2, 6, 2);
				draw->setMap(5, 5, 2);
				draw->setMap(5, 2, 4);
				draw->setMap(6, 2, 4);
				draw->setMap(7, 2, 4);
			}
			draw->drawMap();
			draw->drawCharacter(posx, posy);
			draw->drawFunction();		
		}

		if (key == '1') {	// 1번 화면
			firstStage(draw, mapchoose, undo);
		}
		if (key == '2') {	// 2번 화면
			secondStage(draw, mapchoose, undo);
		}
		if (key == '3') {	// 3번 화면
			thirdStage(draw, mapchoose, undo);
		}
		if (key == '4') {	// 4번 화면
			fourthStage(draw, mapchoose, undo);
		}
		if (key == '5') {	// 5번 화면
			fifthStage(draw, mapchoose, undo);
		}

		nposx = posx;
		nposy = posy;

		if (goal != stagegoal) {	// 게임 종료조건 만족하면 방향키 시용금지
			switch (key) {
			case M_LEFTKEY: if (posx > 0) { posx--; mov++; break; }
			case M_UPKEY: if (posy > 0) { posy--; mov++; break; }
			case M_DOWNKEY: if (posy < MAP_HEIGHT - 1) { posy++; mov++; break; }
			case M_RIGHTKEY: if (posx < MAP_WIDTH - 1) { posx++; mov++; break; }
			}
		}			

		// 벽을 만났을 때
		if (draw->getMap(posx, posy) == 1) {
			posx = nposx;
			posy = nposy;
			mov--;
			PlaySound(TEXT("wall.wav"), NULL, SND_ASYNC);
		}

		// 짐을 만났을 때 
		if (draw->getMap(posx, posy) == 2) {	
			draw->setMap(posx, posy, 0);	// 현재 짐 삭제
			if (posx < nposx) {		// 왼쪽으로 이동할 때
				deltax = -1;
				deltay = 0;
			}
			if (posx > nposx) {		// 오른쪽으로 이동할 때
				deltax = 1;
				deltay = 0;
			}
			if (posy < nposy) {		// 위로 이동할 때
				deltax = 0;
				deltay = -1;
			}
			if (posy > nposy) {		// 아래로 이동할 때
				deltax = 0;
				deltay = 1;
			}
			// 짐을 밀은 곳에 벽이나 다른 짐이 있으면 이동하지 않는다
			if (draw->getMap(posx + deltax, posy + deltay) == 1 ||
				draw->getMap(posx + deltax, posy + deltay) == 2 ||
				draw->getMap(posx + deltax, posy + deltay) == 6) {
				deltax = 0;
				deltay = 0;
				draw->setMap(posx, posy, 2);
				posx = nposx;
				posy = nposy;
				mov--;
				PlaySound(TEXT("wall.wav"), NULL, SND_ASYNC);
			}
			// 목적지에 도착하면 6으로 저장한다
			else if (draw->getMap(posx + deltax, posy + deltay) == 4) {
				goal++;
				draw->setMap(posx + deltax, posy + deltay, 6);
				push++;
			}
			else {
				draw->setMap(posx + deltax, posy + deltay, 2);			
				push++;
				
			}
		}

		// 목적지에 도착한 짐을 만났을 때
		if (draw->getMap(posx, posy) == 6) {
			draw->setMap(posx, posy, 4);
			if (posx < nposx) {		
				deltax = -1;
				deltay = 0;
			}
			if (posx > nposx) {		
				deltax = 1;
				deltay = 0;
			}
			if (posy < nposy) {		
				deltax = 0;
				deltay = -1;
			}
			if (posy > nposy) {		
				deltax = 0;
				deltay = 1;
			}
			if (draw->getMap(posx + deltax, posy + deltay) == 1 ||
				draw->getMap(posx + deltax, posy + deltay) == 2 ||
				draw->getMap(posx + deltax, posy + deltay) == 6) {
				deltax = 0;
				deltay = 0;
				draw->setMap(posx, posy, 2);
				posx = nposx;
				posy = nposy;
				mov--;
				PlaySound(TEXT("wall.wav"), NULL, SND_ASYNC);
			}
			else if (draw->getMap(posx + deltax, posy + deltay) == 4) {
				draw->setMap(posx + deltax, posy + deltay, 6);	
				push++;			
			}
			else {
				draw->setMap(posx + deltax, posy + deltay, 2);
				push++;
				goal--;
			}
		}

		if (nposx != posx || nposy != posy) {
			undo->setNposx(nposx);
			undo->setNposy(nposy);
			undo->setMove(mov);
			undo->setPush(push);
			undo->saveUndo(draw);
			draw->drawCell(nposx, nposy);
			draw->drawCell(posx + deltax, posy + deltay);
			PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
		}

		if (goal == stagegoal) {	// 게임 종료조건 만족하면
			if (mapnum == 1) {		// 전에 받은 점수가 지금 받은 점수보다 높으면 점수가 바뀌지 않음
				if (mov < 29 && push < 13) stage1 = 3;
				else if (mov < 49 && push < 23 && stage1 < 3) stage1 = 2; 
				else if (stage1 < 2) stage1 = 1;
				draw->setScore(stage1);
			}
			else if (mapnum == 2) {
				if (mov < 31 && push < 16) stage2 = 3;
				else if (mov < 51 && push < 26 && stage2 < 3) stage2 = 2;
				else if (stage2 < 2) stage2 = 1;
				draw->setScore(stage2);
			}
			else if (mapnum == 3) {
				if (mov < 62 && push < 10) stage3 = 3;
				else if (mov < 82 && push < 20 && stage3 < 3) stage3 = 2;
				else if (stage3 < 2) stage3 = 1;
				draw->setScore(stage3);
			}
			else if (mapnum == 4) {
				if (mov < 64 && push < 21) stage4 = 3;
				else if (mov < 100 && push < 40 && stage4 < 3) stage4 = 2;
				else if (stage4 < 2) stage4 = 1;
				draw->setScore(stage4);
			}
			else if (mapnum == 5) {
				if (mov < 80 && push < 30) stage5 = 3;
				else if (mov < 120 && push < 50 && stage5 < 3) stage5 = 2;
				else if (stage5 < 2) stage5 = 1;
				draw->setScore(stage5);
			}
			end = clock();
			draw->setTime((end - begin) / CLOCKS_PER_SEC);
			draw->drawStageEnd();

			if (key == 'y') {	// 다음 스테이지로 넘어갈 때
				if (mapnum == 1) secondStage(draw, mapchoose, undo);
				else if (mapnum == 2) thirdStage(draw, mapchoose, undo);
				else if (mapnum == 3) fourthStage(draw, mapchoose, undo);
				else if (mapnum == 4) fifthStage(draw, mapchoose, undo);
				else if (mapnum == 5) break;
			}
			else if (key == 'n') {	// 안 넘어갈 때
				if (mapnum == 1) firstStage(draw, mapchoose, undo);
				else if (mapnum == 2) secondStage(draw, mapchoose, undo);
				else if (mapnum == 3) thirdStage(draw, mapchoose, undo);
				else if (mapnum == 4) fourthStage(draw, mapchoose, undo);
				else if (mapnum == 5) fifthStage(draw, mapchoose, undo);
			}
		}
		else if (key == BACKSPACE) {	   // undo 
			undo->setPosx(posx);
			undo->setPosy(posy);
			undo->Undo(draw, move);
		}
		else {
			draw->drawCharacter(posx, posy);
			draw->setMove(mov);
			draw->setPush(push);
			draw->drawFunction();
		}
	}
}