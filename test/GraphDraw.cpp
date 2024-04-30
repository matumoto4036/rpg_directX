
#include "DxLib.h"
#include "map.h"
#include "system.h"
#include "charagra.h"
#include "objectgra.h"

void GraphDraw(int ScrollX, int ScrollY, int PlayerX, int PlayerY, int MapNo)
{
	int j, i,k,m;
	int MapDrawPointX, MapDrawPointY;		// 描画するマップ座標値
	int DrawMapChipNumX, DrawMapChipNumY;	// 描画するマップチップの数
	int tmp;
	// 描画するマップチップの数をセット
	DrawMapChipNumX = 640 / MAP_SIZE + 2;//22
	DrawMapChipNumY = 480 / MAP_SIZE + 2;//17

	// 画面左上に描画するマップ座標をセット 基準となる座標
	MapDrawPointX = PlayerX - (DrawMapChipNumX / 2 - 1);//-10
	MapDrawPointY = PlayerY - (DrawMapChipNumY / 2 - 1);//-7.5

	//カラーパレット//0海1草原2林3山4黒山5沼6砂10らだとむ11街12竜王
	int col[15][3] = {
		{0,0,255} ,//海
		{0,255,0} ,//草原
		{0,150,0},//林
		{134,74,43},//山
		{50,50,50},//黒山
		{128,0,128},//沼
		{254,220,189},//砂
		{255,255,255},//プレイヤー
		{175,223,228},//8船
		{},
		{255,255,255},
		{255,255,255},
		{},
		{},
		{}
	};

	//マップを描く
	//フラグでループするかループしないか決める
	if (map[MapNo].roopflag == 0) {
		for (i = -1; i < DrawMapChipNumY; i++)
		{
			for (j = -1; j < DrawMapChipNumX; j++)
			{

				// 画面からはみ出た位置なら描画しない
				if (j + MapDrawPointX < 0 || i + MapDrawPointY < 0 ||
					j + MapDrawPointX >= map[MapNo].width || i + MapDrawPointY >= map[MapNo].height) continue;

				tmp = map[MapNo].mapdata[i + MapDrawPointY][j + MapDrawPointX];
				/*DrawBox(j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,
					j * MAP_SIZE + MAP_SIZE + ScrollX, i * MAP_SIZE + MAP_SIZE + ScrollY,
					GetColor(col[tmp][0], col[tmp][1], col[tmp][2]), TRUE);*/
				for (k = 0; k < OBJECT_SIZE; k++) {
					for (m = 0; m < OBJECT_SIZE; m++) {
						DrawBox(j * MAP_SIZE + ScrollX + m * MAP_SIZE / OBJECT_SIZE,
							i * MAP_SIZE + ScrollY + k * MAP_SIZE / OBJECT_SIZE,
							j * MAP_SIZE + ScrollX + (m + 1) * MAP_SIZE / OBJECT_SIZE,
							i * MAP_SIZE + ScrollY + (k + 1) * MAP_SIZE / OBJECT_SIZE,
							GetColor(objegra[tmp].color[objegra[tmp].dot[k][m]][0],
								objegra[tmp].color[objegra[tmp].dot[k][m]][1],
								objegra[tmp].color[objegra[tmp].dot[k][m]][2]), TRUE);
					}
				}

			}
		}
	}
	else if (map[MapNo].roopflag == 2) {
		for (i = -1; i < DrawMapChipNumY; i++)
		{
			for (j = -1; j < DrawMapChipNumX; j++)
			{

				// 画面からはみ出た位置なら描画しない
				if (j + MapDrawPointX < 0 || i + MapDrawPointY < 0 ||
					j + MapDrawPointX >= map[MapNo].width || i + MapDrawPointY >= map[MapNo].height) continue;

				tmp = map[MapNo].mapdata[i + MapDrawPointY][j + MapDrawPointX];
				/*DrawBox(j * MAP_SIZE + ScrollX, i * MAP_SIZE + ScrollY,
					j * MAP_SIZE + MAP_SIZE + ScrollX, i * MAP_SIZE + MAP_SIZE + ScrollY,
					GetColor(col[tmp][0], col[tmp][1], col[tmp][2]), TRUE);*/
				for (k = 0; k < OBJECT_SIZE; k++) {
					for (m = 0; m < OBJECT_SIZE; m++) {
						DrawBox(j * MAP_SIZE + ScrollX + m * MAP_SIZE / OBJECT_SIZE,
							i * MAP_SIZE + ScrollY + k * MAP_SIZE / OBJECT_SIZE,
							j * MAP_SIZE + ScrollX + (m + 1) * MAP_SIZE / OBJECT_SIZE,
							i * MAP_SIZE + ScrollY + (k + 1) * MAP_SIZE / OBJECT_SIZE,
							GetColor(objegra[tmp].color[objegra[tmp].dot[k][m]][0],
								objegra[tmp].color[objegra[tmp].dot[k][m]][1],
								objegra[tmp].color[objegra[tmp].dot[k][m]][2]), TRUE);
					}
				}

			}
		}
		if (p.shipon == 0) {
			DrawBox((p.shipX - MapDrawPointX) * MAP_SIZE + ScrollX, (p.shipY - MapDrawPointY) * MAP_SIZE + ScrollY,
				(p.shipX - MapDrawPointX + 1) * MAP_SIZE + ScrollX, (p.shipY - MapDrawPointY + 1) * MAP_SIZE + ScrollY,
				GetColor(col[8][0], col[8][1], col[8][2]), TRUE);
		}
	}
	else if (map[MapNo].roopflag == 1) {
		for (i = -1; i < DrawMapChipNumY; i++)
		{
			for (j = -1; j < DrawMapChipNumX; j++)
			{
				tmp = map[MapNo].mapdata[((i + MapDrawPointY) % map[MapNo].height + map[MapNo].height) % map[MapNo].height]
					[((j + MapDrawPointX) % map[MapNo].width + map[MapNo].width) % map[MapNo].width];
				if (tmp >= 10) { continue; }
				for (k = 0; k < OBJECT_SIZE; k++) {
					for (m = 0; m < OBJECT_SIZE; m++) {
						DrawBox(j * MAP_SIZE + ScrollX+ m * MAP_SIZE / OBJECT_SIZE,
							i * MAP_SIZE + ScrollY + k * MAP_SIZE / OBJECT_SIZE,
							j * MAP_SIZE + ScrollX+(m+1) * MAP_SIZE / OBJECT_SIZE,
							i * MAP_SIZE + ScrollY+(k+1) * MAP_SIZE / OBJECT_SIZE,
							GetColor(objegra[tmp].color[objegra[tmp].dot[k][m]][0],
								objegra[tmp].color[objegra[tmp].dot[k][m]][1],
								objegra[tmp].color[objegra[tmp].dot[k][m]][2]), TRUE);
					}
				}
				/*
				DrawBox(j* MAP_SIZE + ScrollX, i* MAP_SIZE + ScrollY,
					j* MAP_SIZE + MAP_SIZE + ScrollX, i* MAP_SIZE + MAP_SIZE + ScrollY,
					GetColor(col[tmp][0], col[tmp][1], col[tmp][2]), TRUE);*/
				
			}
		}
		if (p.shipflag == 1 && p.shipon == 0) {
			DrawBox((p.shipX - MapDrawPointX) * MAP_SIZE + ScrollX, (p.shipY - MapDrawPointY) * MAP_SIZE + ScrollY,
				(p.shipX - MapDrawPointX + 1) * MAP_SIZE + ScrollX, (p.shipY - MapDrawPointY + 1) * MAP_SIZE + ScrollY,
				GetColor(col[8][0], col[8][1], col[8][2]), TRUE);
		}
	}
	//街とかの2マス以上の描画
	if (p.shipon==0) {
		// プレイヤーの描画
		for (i = 0; i < CHARA_HEIGHT_MAX; i++)
		{
			for (j = 0; j < CHARA_WIDTH_MAX; j++) {
				//tmp=chagra[0].color[chagra[0].dot[i][j]][]
				if (chagra[0].dot[i][j]==0) { continue; }
				DrawBox((PlayerX - MapDrawPointX) * MAP_SIZE+j*MAP_SIZE/CHARA_SIZE, 
					(PlayerY - MapDrawPointY) * MAP_SIZE-(MAP_SIZE / CHARA_SIZE*CHARA_HEIGHT_MAX-MAP_SIZE)+ i * MAP_SIZE / CHARA_SIZE,
					(PlayerX - MapDrawPointX) * MAP_SIZE+(j+1) * MAP_SIZE / CHARA_SIZE, 
					(PlayerY - MapDrawPointY) * MAP_SIZE-(MAP_SIZE / CHARA_SIZE*CHARA_HEIGHT_MAX - MAP_SIZE) +(i+1) * MAP_SIZE / CHARA_SIZE,
					GetColor(chagra[0].color[chagra[0].dot[i][j]][0], 
						chagra[0].color[chagra[0].dot[i][j]][1], 
						chagra[0].color[chagra[0].dot[i][j]][2]), TRUE);
				
			}//色とドット座標を打ち込む
			
		}
		
	}
	else {
		DrawBox((PlayerX - MapDrawPointX) * MAP_SIZE, (PlayerY - MapDrawPointY) * MAP_SIZE,
			(PlayerX - MapDrawPointX + 1) * MAP_SIZE, (PlayerY - MapDrawPointY + 1) * MAP_SIZE,
			GetColor(col[8][0], col[8][1], col[8][2]), TRUE);
	}
}