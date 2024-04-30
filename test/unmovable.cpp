#include "DxLib.h"
#include "map.h"
#include "system.h"
int unmove[] = {0,4};
int unmoveship[] = { 4 };
void unmovable(int MoveX, int MoveY) {
	if (p.shipon == 0) {
		if (map[p.MapNo].roopflag == 0) {
			for (int i = 0;i < sizeof(unmove) / sizeof(int);i++) {
				if (map[p.MapNo].mapdata[p.PlayerY + MoveY][p.PlayerX + MoveX] == unmove[i])
				{
					p.Move = 0;
					break;
				}
				else
				{
					p.MoveCounter = 0;
				}
			}
		}
		else if (map[p.MapNo].roopflag == 1|| map[p.MapNo].roopflag == 2 ) {
			for (int i = 0;i < sizeof(unmove) / sizeof(int);i++) {
				if (map[p.MapNo].mapdata[(p.PlayerY % map[p.MapNo].height + map[p.MapNo].height + MoveY) % map[p.MapNo].height]
					[(p.PlayerX % map[p.MapNo].width + map[p.MapNo].width + MoveX) % map[p.MapNo].width] == unmove[i])//Œ³‚Í0
				{
					//‘DˆÚ“®‰Â”\
					if ((p.PlayerY % map[p.MapNo].height + map[p.MapNo].height + MoveY) % map[p.MapNo].height == p.shipY &&
						(p.PlayerX % map[p.MapNo].width + map[p.MapNo].width + MoveX) % map[p.MapNo].width == p.shipX) {
						p.MoveCounter = 0;
						p.shipmoving = 1;
						if(p.shipflag==0){ p.shipflag = 1; }
						break;
					}
					else {
						p.Move = 0;
					}
				}
				else
				{
					p.MoveCounter = 0;
				}
			}
		}
	}
	else {
		
		if (map[p.MapNo].mapdata[(p.PlayerY % map[p.MapNo].height + map[p.MapNo].height + MoveY) % map[p.MapNo].height]
			[(p.PlayerX % map[p.MapNo].width + map[p.MapNo].width + MoveX) % map[p.MapNo].width] !=0)//ŠC‚¶‚á‚È‚¢‚Æ‚«
		{
			if (map[p.MapNo].mapdata[(p.PlayerY % map[p.MapNo].height + map[p.MapNo].height + MoveY) % map[p.MapNo].height]
				[(p.PlayerX % map[p.MapNo].width + map[p.MapNo].width + MoveX) % map[p.MapNo].width] >=10) {
				p.MoveCounter = 0;
			}
			else {
				for (int i = 0;i < sizeof(unmoveship) / sizeof(int);i++) {
					if (map[p.MapNo].mapdata[(p.PlayerY % map[p.MapNo].height + map[p.MapNo].height + MoveY) % map[p.MapNo].height]
						[(p.PlayerX % map[p.MapNo].width + map[p.MapNo].width + MoveX) % map[p.MapNo].width] == unmoveship[i]) {
						p.Move = 0;
						break;
					}
					else {
						p.MoveCounter = 0;
						if (i == sizeof(unmoveship) / sizeof(int) - 1) {
							p.shipon = 0;
							p.shipX = p.PlayerX;
							p.shipY = p.PlayerY;
						}
					}
				}
			}
		}
		else
		{
			p.MoveCounter = 0;
		}

	}

}