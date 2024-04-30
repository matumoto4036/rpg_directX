#include "DxLib.h"
#include "system.h"
void comascreen(int X,int Y,int Xratio,int Yratio) {
	DrawBox(X*MAP_SIZE/4, Y * MAP_SIZE / 4,
		X * MAP_SIZE/4 + Xratio * MAP_SIZE/4, Y * MAP_SIZE / 4 + Yratio * MAP_SIZE/4,
		GetColor(32, 32, 32), TRUE);
	//îíê¸
	DrawBox(X * MAP_SIZE/4 + 4, Y * MAP_SIZE / 4 + 2,
		X * MAP_SIZE / 4 + Xratio * MAP_SIZE/4 - 4, Y * MAP_SIZE / 4 + 6,
		GetColor(255, 255, 255), TRUE);
	DrawBox(X * MAP_SIZE / 4 + 4, Y * MAP_SIZE / 4 + Yratio * MAP_SIZE/4 - 6,
		X * MAP_SIZE / 4 + Xratio * MAP_SIZE/4 - 4, Y * MAP_SIZE / 4 + Yratio * MAP_SIZE/4- 2,
		GetColor(255, 255, 255), TRUE);
	DrawBox(X * MAP_SIZE / 4 + 2, Y * MAP_SIZE / 4 + 4,
		X * MAP_SIZE / 4 + 6, Y * MAP_SIZE / 4 + Yratio * MAP_SIZE/4 - 4,
		GetColor(255, 255, 255), TRUE);
	DrawBox(X * MAP_SIZE / 4 + Xratio * MAP_SIZE/4 - 6,Y * MAP_SIZE / 4 + 4,
		X * MAP_SIZE / 4 + Xratio * MAP_SIZE/4 - 2,Y * MAP_SIZE / 4 + Yratio * MAP_SIZE/4 - 4,
		GetColor(255, 255, 255), TRUE);
	//É`ÉáÉ{
	DrawBox(X * MAP_SIZE / 4 + 6,Y * MAP_SIZE / 4 + 6,
		X * MAP_SIZE / 4 + 8,Y * MAP_SIZE / 4 + 8,
		GetColor(255, 255, 255), TRUE);
	DrawBox(X * MAP_SIZE / 4 + 6,Y * MAP_SIZE / 4 + Yratio * MAP_SIZE/4 - 8,
		X * MAP_SIZE / 4 + 8,Y * MAP_SIZE / 4 + Yratio * MAP_SIZE/4 - 6,
		GetColor(255, 255, 255), TRUE);
	DrawBox(X * MAP_SIZE / 4 + Xratio * MAP_SIZE/4 - 8,Y * MAP_SIZE / 4 + 6,
		X * MAP_SIZE / 4 + Xratio * MAP_SIZE/4 - 6,Y * MAP_SIZE / 4 + 8,
		GetColor(255, 255, 255), TRUE);
	DrawBox(X * MAP_SIZE / 4 + Xratio * MAP_SIZE/4 - 8,Y * MAP_SIZE / 4 + Yratio * MAP_SIZE/4 - 8,
		X * MAP_SIZE / 4 + Xratio * MAP_SIZE/4 - 6,Y * MAP_SIZE / 4 + Yratio * MAP_SIZE/4 - 6,
		GetColor(255, 255, 255), TRUE);
	//ç∂è„ÇÃç¿ïW,èké⁄
}