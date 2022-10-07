#include "MapChoose.h"

void MapChoose::setMapChoose(int num) {
	MapNum = num;
}

void MapChoose::mapchoose(Draw* draw) {
	if (MapNum == 1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				draw->setMap(j, i, mapData1[i][j]);
			}
		}
	}
	else if (MapNum == 2) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				draw->setMap(j, i, mapData2[i][j]);
			}
		}
	}
	else if (MapNum == 3) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				draw->setMap(j, i, mapData3[i][j]);
			}
		}
	}
	else if (MapNum == 4) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				draw->setMap(j, i, mapData4[i][j]);
			}
		}
	}
	else if (MapNum == 5) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				draw->setMap(j, i, mapData5[i][j]);
			}
		}
	}
}