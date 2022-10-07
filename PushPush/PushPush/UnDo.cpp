#include "UnDo.h"

void UnDo::setPosx(int posx) {
	_posx = posx;
}

void UnDo::setPosy(int posy) {
	_posy = posy;
}

void UnDo::setNposx(int nposx) {
	_nposx = nposx;
}

void UnDo::setNposy(int nposy) {
	_nposy = nposy;
}

void UnDo::setMove(int mov) {
	_mov = mov;
}

void UnDo::setPush(int push) {
	_push = push;
}

void UnDo::saveUndo(Draw* draw) {
	if (undocount >= 20) {		// 저장 가능한 최대 개수인 20을 넘어가면 0번 index를 삭제함
		for (int k = 1; k < 20; k++) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					undo[k - 1].unMapData[i][j] = undo[k].unMapData[i][j];
				}
			}
			undo[k - 1].x = undo[k].x;
			undo[k - 1].y = undo[k].y;
			undo[k - 1].mov = undo[k].mov;
			undo[k - 1].push = undo[k].push;
		}
		undocount--;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			undo[undocount].unMapData[i][j] = draw->getMap(j, i);
		}
	}
	undo[undocount].x = _nposx;
	undo[undocount].y = _nposy;
	undo[undocount].mov = _mov - 1;
	undo[undocount].push = _push;
	undocount++;
}

void UnDo::deleteUndo() {
	for (int k = 0; k < undocount; k++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				undo[k].unMapData[i][j] = NULL;
			}
		}
		undo[k].x = NULL;
		undo[k].y = NULL;
		undo[k].mov = NULL;
		undo[k].push = NULL;
	}
	undocount = 0;
}

void UnDo::Undo(Draw* draw, Move* move) {
	if (undocount > 0) {
		undocount--;
		_goal = 0;
		if (undocount > 0) {
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++) {
					draw->setMap(j, i, undo[undocount - 1].unMapData[i][j]);
					if (undo[undocount - 1].unMapData[i][j] == 6) _goal++;
				}
			undo[undocount].push = undo[undocount - 1].push;
		}
		draw->drawCell(_posx, _posy);
		_posx = undo[undocount].x;
		_posy = undo[undocount].y;
		_mov = undo[undocount].mov;
		_push = undo[undocount].push;
		draw->setMove(_mov);
		draw->setPush(_push);
		draw->drawFunction();
		draw->drawMenu();
		draw->drawMap();
		draw->drawCharacter(_posx, _posy);
		move->setPosx(_posx);
		move->setPosy(_posy);
		move->setMove(_mov);
		move->setPush(_push);
		move->setGoal(_goal);
	}
}
