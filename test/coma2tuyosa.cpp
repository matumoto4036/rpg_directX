#include "mojidraw.h"
#include "comascreen.h"
#include "system.h"
#include "charapara.h"
#include "numdraw.h"


void coma2tuyosa() {
	comascreen(2, 12, 14, 26);
	//12:7(0-84X�����l�i4��1�}�X�j,0-0-60Y�����l,�䗦�ꕶ���䗦2(�T�C�Y2�Łj,)
	for (int i = 0;i < 4;i++) {
		mojidraw(cp[i].name, 2, 6, 18 + i * 4);//(,,X�����l�i4��1�}�X�j,)
	}
	mojidraw("1D,31,16,", 2, 6, 14);//�悳
	mojidraw("C0,08,08,08,08,08,C1,", 2, 2, 16);//�_
	mojidraw("19,03,39,0D,39,", 2, 6, 34);//���񂢂�
	mojidraw("01,", 2, 4, 18 + 4 * p.comalog[1]);
	comascreen(16, 4, 22, 22);//���O�Ƃ�
	comascreen(16, 26, 22, 22);//����
	comascreen(38, 4, 20, 6);//G
	comascreen(38, 10, 24, 42);//�X�e

	if (p.comalog[1] != 4) {
		//���O�Ƃ�
		mojidraw(cp[p.comalog[1]].name, 2, 24, 6);//���O
		mojidraw("C0,08,08,08,08,08,08,08,08,08,C1,", 2, 16, 8);//�_
		mojidraw("2C,17,42,13,", 2, 24, 10);//�E
		mojidraw("1B,27,11,03,0D,", 2, 24, 14);//���i
		mojidraw("19,0D,28,03,1D,05,10,1F,15,", 2, 18, 18);//��
		mojidraw("6C,5F,03,6B,05,", 2, 18, 22);//���x��
		numdraw(cp[p.comalog[1]].level, 2, 28, 22);//lv
		//����
		//G
		numdraw(p.gold, 2, 40, 6);
		mojidraw("97,", 2, 54, 6);//G
		//�X�e
		mojidraw("1C,11,32,", 2, 40, 12);//������
		mojidraw("18,25,03,2F,16,", 2, 40, 16);//���΂₳
		mojidraw("1B,0D,33,42,13,", 2, 40, 20);//������傭
		mojidraw("11,17,15,16,", 2, 40, 24);//��������
		mojidraw("0E,39,24,31,16,", 2, 40, 28);//����̂悳
		mojidraw("16,0D,1B,03,0D,98,A0,", 2, 40, 32);//�ő�hp
		mojidraw("16,0D,1B,03,0D,9D,A0,", 2, 40, 36);//�ő�mp
		mojidraw("15,0E,14,03,12,48,", 2, 40, 40);//��������
		mojidraw("17,41,26,03,48,", 2, 40, 44);//�����
		mojidraw("06,05,", 2, 40, 48);//exp
		for (int i = 0;i < 9;i++) {
			mojidraw("05,", 2, 52, 12 + i * 4);//exp
		}
		numdraw(cp[p.comalog[1]].power, 2, 54, 12);//������
		numdraw(cp[p.comalog[1]].speed, 2, 54, 16);//���΂₳
		numdraw(cp[p.comalog[1]].HP, 2, 54, 20);//������傭
		//
		numdraw(cp[p.comalog[1]].HP, 2, 54, 32);//�ő�hp
		numdraw(cp[p.comalog[1]].MP, 2, 54, 36);//�ő�mp
		numdraw(cp[p.comalog[1]].power, 2, 54, 40);//��������
		numdraw(cp[p.comalog[1]].defense, 2, 54, 44);//�����

	}
	if (p.comalog[1] == 4 && p.comalay == 2) {
		comascreen(18, 8, 42, 42);
		mojidraw("C0,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,C1,", 2, 18, 12);//�_

		for (int i = 0;i < 4;i++) {

			mojidraw("98,", 2, 20 + 10 * i, 14);//H
			mojidraw("08,08,08,", 2, 22 + 10 * i, 16);
			mojidraw("9D,", 2, 20 + 10 * i, 22);//M
			mojidraw("08,08,08,", 2, 22 + 10 * i, 24);
			mojidraw("15,0E,14,03,12,", 2, 20 + 10 * i, 30);//��������
			mojidraw("17,41,26,03,", 2, 20 + 10 * i, 38);//�����
			mojidraw("05,", 2, 22 + 10 * i, 46);//:
			mojidraw("07,", 2, 20 + 10 * i, 46);//lv

			mojidraw(cp[i].name, 2, 20 + 10 * i, 10);//���O
			numdraw(cp[i].HP, 2, 22 + 10 * i, 14);//H
			numdraw(cp[i].HP, 2, 22 + 10 * i, 18);//H
			numdraw(cp[i].MP, 2, 22 + 10 * i, 22);//M
			numdraw(cp[i].MP, 2, 22 + 10 * i, 26);//M
			numdraw(cp[i].power, 2, 22 + 10 * i, 33);//A
			numdraw(cp[i].defense, 2, 22 + 10 * i, 41);//B
			numdraw(cp[i].level, 2, 24 + 10 * i, 46);//lv

		}
	}
}