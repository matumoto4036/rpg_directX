
#include "DxLib.h"
#include "system.h"
#include <iostream>
#include <string>
#include "moji.h"

//文字列　文字サイズ(1-4-の整数　開始位置
/*void mojidraw(char str1[], int size, int X, int Y) {
	for (int i = 0;str1[i]!='\0';i+=3) {
		for (int k = 0; k < MOJI_SIZE; k++) {
			for (int m = 0; m < MOJI_SIZE; m++) {
				if (moji[strtol(std::string (str1, i, 1).c_str(), NULL, 16)]
						[strtol(std::string(str1, i+1, 1).c_str(), NULL, 16)].dot[k][m] == 0) {
					continue;
				}
				DrawBox(
					X * MAP_SIZE / 4 + m * MAP_SIZE / MOJI_SIZE / 4 * size + i * (MAP_SIZE / 4 * size),
					Y * MAP_SIZE / 4 + k * MAP_SIZE / MOJI_SIZE / 4 * size,
					X * MAP_SIZE / 4 + (m + 1) * MAP_SIZE / MOJI_SIZE / 4 * size + i * (MAP_SIZE / 4 * size),
					Y * MAP_SIZE / 4 + (k + 1) * MAP_SIZE / MOJI_SIZE / 4 * size,
					GetColor(255, 255, 255), TRUE);
			}
		}
	}
}*/

void mojidraw(std::string str1, int size, int X, int Y) {
	int daku = 0;
	int dakuflag = 0;
	for (int i = 0;!str1.substr(i, 1).empty();i+=3) {//この文があかんぽい
		if (str1.substr(i, 2) == "03" || str1.substr(i, 2) == "04") { daku++;dakuflag = 1; }
		for (int k = 0; k < MOJI_SIZE; k++) {
			for (int m = 0; m < MOJI_SIZE; m++) {
				if (moji[strtol(str1.substr(i, 1).c_str(), NULL, 16)]
						[strtol(str1.substr(i+1, 1).c_str(), NULL, 16)].dot[k][m] == 0) {
					continue;
				}
				DrawBox(
					X * MAP_SIZE / 4 + m * MAP_SIZE / MOJI_SIZE / 4 * size + (i-daku*3) * (MAP_SIZE / 4 * size) / 3,
					Y * MAP_SIZE / 4 + k * MAP_SIZE / MOJI_SIZE / 4 * size-dakuflag*(MAP_SIZE / 4 * size),
					X * MAP_SIZE / 4 + (m + 1) * MAP_SIZE / MOJI_SIZE / 4 * size + (i-daku*3) * (MAP_SIZE / 4 * size) / 3,
					Y * MAP_SIZE / 4 + (k + 1) * MAP_SIZE / MOJI_SIZE / 4 * size- dakuflag * (MAP_SIZE / 4 * size),
					GetColor(255, 255, 255), TRUE);
			}
		}
		if (str1.substr(i, 2) == "03" || str1.substr(i, 2) == "04") {dakuflag = 0; }
	}
}
/*
			void mojidraw(std::string str1[],int size, int X,int Y) {
	for (int i = 0;str1[i]!="0";i++) {
		for (int k = 0; k < MOJI_SIZE; k++) {
			for (int m = 0; m < MOJI_SIZE; m++) {
				if (moji[strtol(str1[i].substr(0, 1).c_str(), NULL, 16)]
						[strtol(str1[i].substr(1, 1).c_str(), NULL, 16)].dot[k][m] == 0) {
					continue;
				}
				DrawBox(
					X * MAP_SIZE / 4 + m * MAP_SIZE / MOJI_SIZE / 4 * size + i * (MAP_SIZE / 4 * size),
					Y * MAP_SIZE / 4 + k * MAP_SIZE / MOJI_SIZE / 4 * size,
					X * MAP_SIZE / 4 + (m + 1) * MAP_SIZE / MOJI_SIZE / 4 * size + i * (MAP_SIZE / 4 * size),
					Y * MAP_SIZE / 4 + (k + 1) * MAP_SIZE / MOJI_SIZE / 4 * size,
					GetColor(255, 255, 255), TRUE);
			}
		}
	}
}
*/