#pragma once
#include <string>
#ifndef SYSTEM_H
#define SYSTEM_H
struct pl {
	int MapNo;
	int PlayerX, PlayerY;
	int Move;//�ړ��t���O
	int MoveCounter;//�ړ��t���[��
	int comacounter;
	int shipflag,shipmoving,shipon,shipX,shipY;//�D���W
	int gold;
	int comalog[4];
	int comalay;
	int waitflag;
	int comaX, comaY;
	int comaflag;
	int txtmp;
	int txcount;
};

#define MAP_SIZE	32			// �}�b�v�`�b�v��̃h�b�g�T�C�Y
#define MOVE_FRAME	8	
#define COMA_FRAME	8
#define TXT_FRAME	3
#define TXT_SCROLL  4

__declspec(selectany)  pl p = {
	0,
	10,8,
	0,
	0,
	0,
	1,0,0,11,11,
	7082,
	{0,0,0,0},0,
	0,//wait
	0,0,0,
	0,0
};
//void sysup(int a, int b,int c,int d,int e) {};
#endif