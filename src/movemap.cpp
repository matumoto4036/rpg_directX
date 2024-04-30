
#include "DxLib.h"
#include "map.h"
#include "system.h"


void movemap() {
	int tmp = 0;
	if (map[p.MapNo].roopflag == 0) {
		tmp=map[p.MapNo].mapdata[p.PlayerY][p.PlayerX];
	}
	else {
		tmp = map[p.MapNo].mapdata[(p.PlayerY % map[p.MapNo].height + map[p.MapNo].height) % map[p.MapNo].height]
			[(p.PlayerX % map[p.MapNo].width + map[p.MapNo].width) % map[p.MapNo].width];
	}
	if (p.Move == 0 && tmp >= 10) {
		if (map[p.MapNo].roopflag == 2 ) {//ルプガナ出港と通常out
			p.shipX = map[p.MapNo].shiprulaX;
			p.shipY = map[p.MapNo].shiprulaY;
		}
		p.PlayerX = map[p.MapNo].dim[tmp - 10][1];
		p.PlayerY = map[p.MapNo].dim[tmp - 10][2];
		p.MapNo = map[p.MapNo].dim[tmp - 10][0];
		
		if (map[p.MapNo].roopflag == 2&&p.shipon==0) {//ルプガナin
			p.shipX = map[p.MapNo].shipstartX;
			p.shipY = map[p.MapNo].shipstartY;
		}
		
		/*
		if (map[p.MapNo].roopflag == 2 && p.shipflag == 1 && p.shipon == 0) {//ルプガナin
			p.shipX = map[p.MapNo].shipstartX;
			p.shipY = map[p.MapNo].shipstartY;
		}*/
		
	}
	
}