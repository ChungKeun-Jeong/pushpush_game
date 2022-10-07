#ifndef UNDO_H
#define UNDO_H
#include "Draw.h"
#include "Move.h"

class Draw;
class Move;
class UnDo
{
	int undocount = 0;
	int _posx = 0;
	int _posy = 0;
	int _nposx;
	int _nposy;
	int _mov = 0;
	int _push = 0;
	int _goal = 0;
	struct Undo {
		char unMapData[10][10];
		int x;
		int y;
		int mov;
		int push;
	}undo[20];
public :
	void setPosx(int posx);
	void setPosy(int posy);
	void setNposx(int nposx);
	void setNposy(int nposy);
	void setMove(int mov);
	void setPush(int push);
	void saveUndo(Draw* draw);
	void deleteUndo();
	void Undo(Draw* draw, Move* move);
};
#endif

