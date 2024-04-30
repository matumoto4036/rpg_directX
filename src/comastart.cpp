#include "DxLib.h"
#include "system.h"
#include <iostream>
#include <string>
#include "mojidraw.h"
#include "comascreen.h"


void comastart() {
	comascreen(4, 4, 24, 14);
	//12:7(0-84X初期値（4で1マス）,0-0-60Y初期値,比率一文字比率2(サイズ2で）,)
	std::string str1 = "25,20,18,";//はなす
	mojidraw(str1, 2, 8, 6);//(,,X初期値（4で1マス）,)
	str1 = "1F,03,0E,13,03,";//どうぐ
	mojidraw(str1, 2, 8, 10);
	str1 = "1D,31,16,";//つよさ
	mojidraw(str1, 2, 8, 14);
	str1 = "17,03,41,2E,39,";//じゅもん
	mojidraw(str1, 2, 18, 6);
	str1 = "17,32,28,03,34,";//しらべる
	mojidraw(str1, 2, 18, 10);
	str1 = "16,13,19,39,";//さくせん
	mojidraw(str1, 2, 18, 14);
}