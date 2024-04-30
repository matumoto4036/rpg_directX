#pragma once
#include <string>
#ifndef CHARAPARA_H
#define CHARAPARA_H
#define CHARA_NUM 4
struct chapara{
	std::string name;
	int level;
	int HP;
	int MP;
	int power;
	int defense;
	int speed;
	//UŒ‚—Í‚Æ–hŒä—Í@‘•”õ‚ÉŒˆ‚ß‚é
	int spell[20];
};
__declspec(selectany) chapara cp[CHARA_NUM] = {
	{
		"0C,0C,0C,0C,",
		32,100,100,654,287,20,
		{
			1,1,1,1,1,
			1,1,1,1,1,
			1,1,1,1,1,
			1,1,1,1,1
		},
	},
	{
		"0D,0D,0D,0D,",
		38,200,100,546,961,20,
		{
			1,1,0,0,0,
			0,0,0,0,0,
			0,0,0,0,0,
			0,0,0,0,0
		},
	},
	{
		"0E,0E,0E,0E,",
		31,300,100,200,207,20,
		{
			1,0,1,0,0,
			0,0,0,0,0,
			0,0,0,0,0,
			0,0,0,0,0
		},
	},
	{
		"0F,0F,0F,0F,",
		1,400,100,205,627,20,
		{
			1,0,1,1,0,
			0,0,0,0,0,
			0,0,0,0,0,
			0,0,0,0,0
		},
	}
};
#endif