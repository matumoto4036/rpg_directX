#include "system.h"
#include "DxLib.h"
void comamove() {


	p.comaX = 0;p.comaY = 0;
	if (CheckHitKey(KEY_INPUT_LEFT) == 1) {//•Â‚¶‚é
		p.comaflag = 0;
		p.waitflag = 1;
	} 
	else if (CheckHitKey(KEY_INPUT_DOWN) == 1) {//–ß‚é
		if (p.comalay == 0) { p.comaflag = 0; }
		else {
			for (int i = p.comalay;0 < i && i < 3;i++) {
				p.comalog[i] = 0;
			}
			p.comalay--;
		}
		p.waitflag = 1;

	}
	else if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {//Œˆ’è
		if (p.comalay > 0) {
			if (p.comalog[0] == 0|| p.comalog[0] == 4) {
				p.txtmp++;
				p.txcount = 0;
			}
		}
		p.waitflag = 1;
		p.comalay++;
	}
	else if (CheckHitKey(KEY_INPUT_A) == 1)//ƒRƒ}ƒ“ƒh‚¢‚Ç‚¤
	{
		p.comaX = -1;
		p.waitflag = 1;
	}
	else if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		p.comaX = 1;
		p.waitflag = 1;
	}
	else if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		p.comaY = -1;
		p.waitflag = 1;
	}
	else if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		p.comaY = 1;
		p.waitflag = 1;
	}
}