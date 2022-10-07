#include "Draw.h"

void Draw::xyputstr(int x, int y, const char str[]) {
	gotoxy(x, y);
	cout << str;
}

void Draw::setScore(int score) {
	_score = score;
}

void Draw::setMapNum(int mapnum) {
	_mapnum = mapnum;
}

void Draw::setMove(int mov) {
	_mov = mov;
}

void Draw::setPush(int push) {
	_push = push;
}

void Draw::setMap(int x, int y, int i) {
	mapData[y][x] = i;
}

void Draw::setTime(int time) {
	_time = time;
}

int Draw::getMap(int x, int y) {
	return mapData[y][x];
}

void Draw::drawCell(int col, int row) {
	int cell = mapData[row][col];
	textbackground((cell == 1) ? DARKGRAY : BLACK);
	if (cell == 2) textcolor(YELLOW);
	else if (cell == 4 || cell == 6) textcolor(CYAN);
	else textcolor(WHITE);
	gotoxy((MAP_X1 + col + 1) * 2, MAP_Y1 + row + 1);
	puts(cellSymbol[cell]);
}

void Draw::drawMap() {
	for (int row = 0; row < MAP_HEIGHT; row++)
		for (int col = 0; col < MAP_WIDTH; col++)
			drawCell(col, row);
}

void Draw::drawCharacter(int x, int y) {
	textcolor(RED);
	textbackground(BLACK);
	xyputstr((MAP_X1 + 1 + x) * 2, MAP_Y1 + 1 + y, "♣");
}

void Draw::drawStart() {
	textbackground(BLACK);
	textcolor(WHITE);
	for (int i = 5; i < 23; i++) {	// 왼쪽 세로줄
		gotoxy(18, i);
		puts(cellSymbol[3]);
	}
	for (int i = 19; i < 64; i++) {	// 밑쪽 가로줄
		gotoxy(i, 23);
		puts(cellSymbol[5]);
	}
	for (int i = 5; i < 23; i++) {	// 오른쪽 세로줄
		gotoxy(65, i);
		puts(cellSymbol[3]);
	}
	for (int i = 19; i < 64; i++) {	// 위쪽 가로줄
		gotoxy(i, 4);
		puts(cellSymbol[5]);
	}
	gotoxy(27, 8);
	cout << " ###    #   #     ####   #   #" << endl;
	gotoxy(27, 9);
	cout << "#   #   #   #    #       #   #" << endl;
	gotoxy(27, 10);
	cout << "####    #   #     ###    #####" << endl;
	gotoxy(27, 11);
	cout << "#       #   #        #   #   #" << endl;
	gotoxy(27, 12);
	cout << "#        ###     ####    #   #" << endl;
	
	gotoxy(35, 20);
	cout << "PRESS ANY KEY";

	while (1) {	
		if (_getch() != NULL) break;
	}
}

void Draw::drawMenu() {
	textbackground(BLACK);
	textcolor(WHITE);
	for (int i = 5; i < 23; i++) {	// 왼쪽 세로줄
		gotoxy(18, i);
		puts(cellSymbol[3]);
	}
	for (int i = 19; i < 64; i++) {	// 밑쪽 가로줄
		gotoxy(i, 23);
		puts(cellSymbol[5]);
	}
	for (int i = 9; i < 23; i++) {	// 중앙 세로줄
		gotoxy(45, i);
		puts(cellSymbol[3]);
	}
	for (int i = 19; i < 64; i++) {	// 중앙 가로줄
		gotoxy(i, 8);
		puts(cellSymbol[5]);
	}
	for (int i = 5; i < 23; i++) {	// 오른쪽 세로줄
		gotoxy(65, i);
		puts(cellSymbol[3]);
	}
	for (int i = 19; i < 64; i++) {	// 위쪽 가로줄
		gotoxy(i, 4);
		puts(cellSymbol[5]);
	}
	for (int i = 46; i < 64; i++) {	// 오른쪽 가로줄
		gotoxy(i, 15);
		puts(cellSymbol[5]);
	}
	gotoxy(47, 17);
	cout << "q : quit";
	gotoxy(47, 18);
	cout << "r : restart";
	gotoxy(47, 19);
	cout << "←↑→↓ : move";
	gotoxy(47, 20);
	cout << "backspace : undo";
	gotoxy(47, 21);
	cout << "1,2,3,4,5 : stage";
}

void Draw::drawFunction() {
	textcolor(WHITE);
	gotoxy(38, 6);
	cout << "STAGE " << _mapnum;
	gotoxy(47, 10);
	cout << "           ";
	gotoxy(47, 10);
	cout << "MOVE : " << _mov;
	gotoxy(47, 13);
	cout << "           ";
	gotoxy(47, 13);
	cout << "PUSH : " << _push;
	textcolor(YELLOW);
	gotoxy(30, 6);
	for (int i = 0; i < _score; i++)
		cout << "★";
}

void Draw::drawStageEnd() {
	for (int i = 25; i < 57; i++) {	// 가운데 초기화
		for (int j = 11; j < 21; j++) {
			gotoxy(i, j);
			puts(" ");
		}
	}
	textcolor(YELLOW);
	for (int i = 26; i < 56; i++) {	// 위쪽 가로줄
		gotoxy(i, 11);
		puts(cellSymbol[5]);
	}
	for (int i = 26; i < 56; i++) {	// 밑쪽 가로줄
		gotoxy(i, 20);
		puts(cellSymbol[5]);
	}
	for (int i = 12; i < 20; i++) {	// 왼쪽 세로줄
		gotoxy(25, i);
		puts(cellSymbol[3]);
	}
	for (int i = 12; i < 20; i++) {	// 오른쪽 세로줄
		gotoxy(57, i);
		puts(cellSymbol[3]);
	}
	textcolor(WHITE);
	gotoxy(35, 13);
	cout << "STAGE " << _mapnum << " CLEAR";
	textcolor(YELLOW);
	gotoxy(36, 15);
	for (int i = 0; i < _score; i++)
		cout << "★  ";
	for (int i = 0; i < 3 - _score; i++)
		cout << "☆  ";
	
	textcolor(WHITE);
	gotoxy(35, 17);
	cout << "PLAY TIME : " << _time;

	if (_mapnum == 5) {
		gotoxy(31, 19);
		cout << "FINISH GAME? (Y / N)";
	}
	else {
		gotoxy(30, 19);
		cout << "PLAY NEXT STAGE? (Y / N)";
	}

}



