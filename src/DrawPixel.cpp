//目標　別マップに移動できる　メニューを開ける
//サブ目標　主人公のパラメータを設定する　敵と遭遇する

#include "DxLib.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <tuple>
#include "map.h"
#include "GraphDraw.h"
#include "system.h"
#include "movemap.h"
#include "moveprocess.h"
#include "unmovable.h"
#include "movechara.h"
#include "comascreen.h"
#include "moji.h"
#include "mojidraw.h"
#include "comastart.h"
#include "charapara.h"
#include "numdraw.h"
#include "comamove.h"
#include "coma2tuyosa.h"


// 各方向に移動する量

int MoveX, MoveY;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	int ScrollX=0, ScrollY=0;

	ChangeWindowMode(TRUE);
	//SetWindowSizeExtendRate(1.5);
	if (DxLib_Init() == -1){return -1;}

	SetDrawScreen(DX_SCREEN_BACK);
	
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		/////////////////////////////////////////////////////////////////////////
		movemap();
		if (p.waitflag==0) {
			//移動
			if (p.comaflag == 0) {
				if (p.Move == 0)
				{
					if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
						p.comaflag = 1;
						p.waitflag = 1;
						p.comaX = 0;p.comaY = 0;
						p.comalay = 0;
						for (int i = 0;i < 3;i++) {
							p.comalog[i] = 0;
						}
					}
					else if (CheckHitKey(KEY_INPUT_UP) == 1) {
						p.shipflag = (p.shipflag + 1) % 2;
						p.waitflag = 1;
					}
					else {
						std::tie(MoveX, MoveY) = movechara(MoveX, MoveY);
					}

					if (p.Move == 1)
					{
						unmovable(MoveX, MoveY);
					}
					ScrollX = 0;
					ScrollY = 0;
				}
				// 移動中の場合は移動処理を行う
				if (p.Move == 1)
				{
					std::tie(ScrollX, ScrollY) = moveprocess(MoveX, MoveY);
				}
			}
			//コマンド
			if (p.comaflag == 1&&p.waitflag==0) {
				comamove();
			}
		}
		else if (p.waitflag == 1) {
			p.comacounter++;
			if (p.comacounter == COMA_FRAME) {
				p.waitflag = 0;
				p.comacounter = 0;
			}
		}
		

		////////////////////////////////////////////////////////////////////////
		
		GraphDraw(ScrollX, ScrollY, p.PlayerX, p.PlayerY, p.MapNo);
		//ここにコマンド作る
		
		if (p.comaflag == 1) {//comalogに保存
			if (p.comalay == 0) {
				p.comalog[p.comalay] = ((p.comalog[p.comalay]+p.comaY+3)%3+(p.comalog[p.comalay]/3)*3+p.comaX*3+6)%6;//
				p.comaX = 0;p.comaY = 0;
			}
			else if(p.comalay >0) {
				if (p.comalog[0] == 0) {
					
				}
				else if (p.comalog[0] == 1) {

				}
				else if(p.comalog[0]==2){
					if (p.comalay == 1) {
						p.comalog[p.comalay] = (p.comalog[p.comalay]+p.comaY + 5) % 5;
						p.comaX = 0;p.comaY = 0;
					}
					else if (p.comalog[1]!=4&&p.comalay > 1) { p.comalay = 1; }//comalayの制御
					if(p.comalog[1] == 4&&p.comalay > 2) { p.comalay = 2; }
				}
				else if (p.comalog[0] == 3) {
					if (p.comalay == 1) {
						p.comalog[p.comalay] = (p.comalog[p.comalay] + p.comaY + 4) % 4;
						p.comaX = 0;p.comaY = 0;
					}
					if (p.comalay == 2) {
						int spellcount=0;
						for (int i = 0;i < 20;i++) {
							if (cp[p.comalog[p.comalay]].spell[i] == 1) {
								spellcount++;
							}
						}
						if (spellcount == 0) { p.comalay = 1; }
						else if (p.comaX == 1 || p.comaX == -1) {
							p.comalog[p.comalay] = min(spellcount - 1, 
								(p.comalog[p.comalay] + p.comaX * 8 + (spellcount + 7) / 8 * 8) % (spellcount + 7) / 8 * 8);
						}
						else if (p.comaY == 1 || p.comaY == -1) {
							p.comalog[p.comalay] = min(spellcount - 1, 
								p.comalog[p.comalay]/8*8 + (p.comalog[p.comalay]+p.comaY+8)%8);
						}
						p.comaX = 0;p.comaY = 0;
					}
					if (p.comalay == 3) {
						int spellcount = 0;
						for (int i = 0;i < 20;i++) {
							if (cp[p.comalog[p.comalay]].spell[i] == 1) {
								spellcount++;
								if (p.comalog[2] == spellcount-1) {
									break;
								}
							}
						}
						//spelleffect(i);//たぶん違う

					}
					if(p.comalay > 4) { p.comalay = 4; }
				}
				else if (p.comalog[0] == 4) {

				}
				else if (p.comalog[0] == 5) {

				}
			}
			if (!(p.comalay>0&&(p.comalog[0]==0|| p.comalog[0]==4))) {
				comastart();
				mojidraw("01,", 2, 6 + 10 * (p.comalog[0] / 3), 6 + 4 * (p.comalog[0] % 3));
			}
			
			if (p.comalay >0) {
				if (p.comalog[0] == 0) {
					p.txcount++;
					p.waitflag = 1;
					std::string str1 = "25,20,18,25,20,18,25,20,18,25,20,18,25,20,18,25,20,18,";
					if (p.txcount> (int)str1.length()/3 * TXT_FRAME) { p.txcount = (int)str1.length()/3*TXT_FRAME; p.waitflag = 0; }
					comascreen(4, 40, 72, 20);
					mojidraw(str1.substr(0,p.txcount/TXT_FRAME*3), 3, 8, 42);
					

					if (p.txtmp==1) {
						p.txtmp = 0;
						p.txcount = 0;
						p.comaflag = 0;
						p.waitflag = 1;
					}
				}
				if(p.comalog[0] == 2) {
					coma2tuyosa();
				}
				if (p.comalog[0] == 3) {
					comascreen(2, 12, 14, 26);
					//12:7(0-84X初期値（4で1マス）,0-0-60Y初期値,比率一文字比率2(サイズ2で）,)
					for (int i = 0;i < 4;i++) {
						mojidraw(cp[i].name, 2, 6, 18 + i * 4);//(,,X初期値（4で1マス）,)
					}
					mojidraw("C0,08,08,08,08,08,C1,", 2, 2, 16);//棒
					mojidraw("01,", 2, 4, 18 + 4 * p.comalog[1]);
					comascreen(16, 4, 22, 22);
				}
				if (p.comalog[0] == 4) {
					comascreen(4, 40, 72, 20);
					p.txcount++;
					p.waitflag = 1;
					//文字表示部分　一文目
					std::string str1[2][3] = {  { "25,20,18,25,20,18,25,20,18,25,20,18,25,20,18,25,20,18,","20,18,25,","25,20,18," },
												{ "20,18,20,18,20,18,25,20,18,","25,20,18,25,",""}};
					if (p.txtmp < sizeof(str1) / sizeof(str1[0])) {
						//if (p.txtmp == 0) {
							int k[3] = { 0,
								(int)str1[p.txtmp][0].length(),
								(int)str1[p.txtmp][0].length() + (int)str1[p.txtmp][1].length() };
							int a = k[2] + (int)str1[p.txtmp][2].length();
							if (p.txcount > a / 3 * TXT_FRAME) {
								p.txcount = a / 3 * TXT_FRAME; p.waitflag = 0;
								if (p.txtmp < sizeof(str1) / sizeof(str1[0]) - 1) {
									mojidraw("01,", 3, 40, 56);
								}
							}
							for (int i = 0;i < 3;i++) {
								int s = min(max(0, p.txcount / TXT_FRAME * 3 - k[i]), (int)str1[p.txtmp][i].length());
								s = s / 3 * 3;
								mojidraw(str1[p.txtmp][i].substr(0, s), 3, 8, 42 + i * 6);
							}
						/* }
						else {
							if (str1[p.txtmp - 1][1] == "") {//一行
								int j[3] = { 0,
									(int)str1[p.txtmp - 1][0].length(),
									(int)str1[p.txtmp - 1][0].length() + (int)str1[p.txtmp][1].length() };
								int k[3] = { 0,
									(int)str1[p.txtmp][0].length(),
									(int)str1[p.txtmp][0].length() + (int)str1[p.txtmp][1].length() };
								int a = k[2] + (int)str1[p.txtmp][2].length();
								if (p.txcount > a / 3 * TXT_FRAME) {
									p.txcount = a / 3 * TXT_FRAME; p.waitflag = 0;
									if (p.txtmp < sizeof(str1) / sizeof(str1[0]) - 1) {
										mojidraw("01,", 3, 40, 56);
									}
								}
								for (int i = 0;i < 3;i++) {
									int s = min(max(0, p.txcount / TXT_FRAME * 3 - k[i]), (int)str1[p.txtmp][i].length());
									s = s / 3 * 3;
									mojidraw(str1[p.txtmp][i].substr(0, s), 3, 8, 42 + i * 6);
								}
							}
							else if(str1[p.txtmp - 1][2] == ""){//二行
								
							}
							else {//三行

							}

						}*/
					}
					//文字改行部分
					//さらに文字表示部分
					//終了部分
					if (p.txtmp == sizeof(str1) / sizeof(str1[0])) {
						p.txtmp = 0;
						p.txcount = 0;
						p.comaflag = 0;
						p.waitflag = 1;
					}
				}
				if (p.comalog[0] == 5) {}
			}
			

		}
		
		
		//////////////////////////////////////////////////////////////////////////////////
		//DrawString(0,0, char* String,GetColor(255, 255, 255))
		ScreenFlip();
	}

	DxLib_End();

	return 0;
}