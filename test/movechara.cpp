#include "DxLib.h"
#include "map.h"
#include "system.h"
#include <iostream>
#include <string>
#include <tuple>


std::pair<int, int> movechara(int MoveX, int MoveY) {
	// キー入力に応じてプレイヤーの座標を移動
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		p.Move = 1;
		MoveX = -1;
		MoveY = 0;
	}
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		p.Move = 1;
		MoveX = 1;
		MoveY = 0;
	}
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		p.Move = 1;
		MoveX = 0;
		MoveY = -1;
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		p.Move = 1;
		MoveX = 0;
		MoveY = 1;
	}
	return std::make_pair(MoveX, MoveY);
}