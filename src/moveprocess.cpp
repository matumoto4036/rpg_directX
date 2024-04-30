
#include "DxLib.h"
#include "map.h"
#include "system.h"
#include <iostream>
#include <string>
#include <tuple>


std::pair<int,int> moveprocess(int MoveX,int MoveY) {
	int scrollx = 0;
	int scrolly = 0;
	p.MoveCounter++;
	if (p.MoveCounter == MOVE_FRAME)
	{
		p.Move = 0;

		// �v���C���[�̈ʒu��ύX����
		p.PlayerX += MoveX;
		p.PlayerY += MoveY;

		// ��~���͉�ʂ̃X�N���[���͍s��Ȃ�
		scrollx = 0;
		scrolly = 0;
		if (p.shipmoving == 1) {
			p.shipmoving = 0;
			p.shipon = 1;
		}
	}
	else
	{
		// �o�ߎ��Ԃ���X�N���[���ʂ��Z�o����
		scrollx = -(MoveX * MAP_SIZE * p.MoveCounter / MOVE_FRAME);
		scrolly = -(MoveY * MAP_SIZE * p.MoveCounter / MOVE_FRAME);
	}
	return std::make_pair(scrollx,scrolly);
}