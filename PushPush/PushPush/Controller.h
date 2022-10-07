#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Draw.h"
#include "Move.h"
#include "MapChoose.h"
#include "UnDo.h"

class Controller {
	Draw* _draw;
	Move* _move;
	MapChoose* _mapchoose;
	UnDo* _undo;
public :
	Controller() {
		_draw = new Draw;
		_move = new Move;
		_mapchoose = new MapChoose;
		_undo = new UnDo;
	}
	~Controller() {
		delete _draw;
		delete _move;
		delete _mapchoose;
		delete _undo;
	}
	void start() {
		_move->move(_draw, _mapchoose, _undo, _move);
	}
};
#endif