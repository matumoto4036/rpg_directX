#include "DxLib.h"
#include "system.h"
#include <iostream>
#include <string>
#include "mojidraw.h"
#include "comascreen.h"


void comastart() {
	comascreen(4, 4, 24, 14);
	//12:7(0-84X�����l�i4��1�}�X�j,0-0-60Y�����l,�䗦�ꕶ���䗦2(�T�C�Y2�Łj,)
	std::string str1 = "25,20,18,";//�͂Ȃ�
	mojidraw(str1, 2, 8, 6);//(,,X�����l�i4��1�}�X�j,)
	str1 = "1F,03,0E,13,03,";//�ǂ���
	mojidraw(str1, 2, 8, 10);
	str1 = "1D,31,16,";//�悳
	mojidraw(str1, 2, 8, 14);
	str1 = "17,03,41,2E,39,";//�������
	mojidraw(str1, 2, 18, 6);
	str1 = "17,32,28,03,34,";//����ׂ�
	mojidraw(str1, 2, 18, 10);
	str1 = "16,13,19,39,";//��������
	mojidraw(str1, 2, 18, 14);
}