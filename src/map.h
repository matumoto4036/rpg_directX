#pragma once
#ifndef MAP_H
#define MAP_H

#define MAP_NUM     4
#define MAP_WIDTH_MAX	100			// マップの幅
#define MAP_HEIGHT_MAX	100			// マップの縦長さ
struct MAP
{
    char mapname[10];
	int width;
	int height;
    int mapdata[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];
	int roopflag;//ルプガナは2
	int shipstartX, shipstartY,shiprulaX,shiprulaY;
	int dim[10][3];// 引数は10以上のマップ配置から10引いたもの 値は前から移動先マップ番号、移動先の座標
};

__declspec(selectany) MAP map[MAP_NUM] = {
	{	"arefguld",
		20,16,
		{
			{ 1, 1, 2, 2, 2, 2, 2, 2, 2, 2 ,  2, 3, 3, 3, 3, 3, 3, 3, 3, 3 } ,
			{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2 ,  2, 2, 2, 3, 3, 3, 3, 3, 3, 3 } ,
			{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2 ,  2, 2, 2, 2, 2, 2, 3, 3, 3, 3 } ,
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 ,  2, 2, 2, 2, 2, 2, 2, 1, 1, 3 } ,
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 ,  2, 2, 2, 2, 2, 2, 1, 1, 1, 1 } ,
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 ,  2, 2, 1, 1, 1, 1, 1, 1, 1, 1 } ,
			{ 2, 2, 2, 2, 2, 2, 2, 2, 1, 1 ,  1, 1, 1,11, 1, 1, 0, 0, 0, 0 } ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1,10 ,  1, 1, 1, 1, 1, 0, 0, 0, 0, 0 } ,
										  
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,  1, 1, 1, 1, 0, 0, 0, 0, 0, 0 } ,
			{ 1, 1, 1, 1, 1, 1, 1, 1,12, 1 ,  1, 1, 1, 0, 0, 0, 0, 0, 0, 0 } ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,  1, 1, 0, 0, 0, 0, 0, 0, 4, 4 } ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 ,  0, 0, 0, 0, 0, 0, 4, 4, 4, 4 } ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 ,  0, 0, 0, 5, 5, 5, 4, 4, 4, 4 } ,
			{ 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 ,  0, 0, 4, 5,13, 5, 4, 4, 4, 4 } ,
			{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 4, 4, 5, 5, 5, 6, 6, 6, 6 } ,
			{ 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 ,  4, 4, 4, 4, 4, 4, 4, 4, 4, 4 }
		},
		1,/*roop*/11,11,0,0,
		{
			{1,4,6},
			{2,1,3},
			{3,1,3},
			{},
			{},
			{},
			{},
			{},
			{},
			{}
		}
	},
	{
	   "radacas",
		10,8,
		{
			{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 } ,
			{ 1, 1, 0, 0, 1, 1, 1, 1, 1, 0 } ,
			{ 1, 1, 0, 1, 1, 1, 1, 1, 1, 0 } ,
			{ 1, 0, 0, 1, 1, 1, 1, 1, 1, 0 } ,
			{ 1, 0, 0, 1, 1, 0, 1, 1, 1, 0 } ,
			{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0 } ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
			{10,10,10,10,10,10,10,10,10,10 } ,
		},
		0,0,0,11,11,
		{
			{0,9,8},
			{},
			{},
			{},
			{},
			{},
			{},
			{},
			{},
			{}
		}
	},
	{
	   "radatom",
		10,8,
		{
			{10, 0, 0, 0, 1, 0, 0, 0, 0, 0 } ,
			{10, 1, 0, 0, 1, 1, 1, 1, 1, 0 } ,
			{10, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
			{10, 0, 0, 1, 1, 1, 1, 1, 1, 0 } ,
			{10, 0, 0, 1, 1, 0, 1, 1, 1, 0 } ,
			{10, 0, 1, 1, 1, 0, 1, 1, 1, 0 } ,
			{10, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
			{10, 0, 0, 0, 0, 0, 0, 1, 0, 0 } ,
		},
		0,0,0,13,11,
		{
			{0,13,7},
			{},
			{},
			{},
			{},
			{},
			{},
			{},
			{},
			{}
		}
	},
	{
	   "rupgana",
		10,8,
		{
			{10, 0, 0, 0, 1, 0, 0, 0, 0, 0 } ,
			{10, 1, 0, 0, 1, 1, 1, 1, 1, 0 } ,
			{10, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
			{10, 1, 0, 1, 1, 1, 1, 1, 1, 0 } ,
			{11, 0, 0, 1, 1, 0, 1, 1, 1, 0 } ,
			{11, 0, 1, 1, 1, 0, 1, 1, 1, 0 } ,
			{10, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
			{10, 0, 0, 0, 0, 0, 0, 1, 0, 0 } ,
		},
		2,1,4,8,12,
		{
			{0,8,10},
			{0,8,12},
			{},
			{},
			{},
			{},
			{},
			{},
			{},
			{}
		}
	}
};
#endif