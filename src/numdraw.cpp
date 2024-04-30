#include "DxLib.h"
#include "system.h"
#include <iostream>
#include <string>
#include "mojidraw.h"
void numdraw(int num, int size, int X, int Y ) {
	std::string str1 = "";
	int tmp=0;
	do {
		tmp = num%10;
		num = num / 10;
		switch(tmp) {
			case 0:
				str1 = "87,"+str1;
				break;
			case 1:
				str1 = "88," + str1;
				break;
			case 2:
				str1 = "89," + str1;
				break;
			case 3:
				str1 = "8A," + str1;
				break;
			case 4:
				str1 = "8B," + str1;
				break;
			case 5:
				str1 = "8C," + str1;
				break;
			case 6:
				str1 = "8D," + str1;
				break;
			case 7:
				str1 = "8E," + str1;
				break;
			case 8:
				str1 = "8F," + str1;
				break;
			case 9:
				str1 = "90," + str1;
				break;
		}
	} while (num > 0);

	mojidraw(str1, size, X, Y);
};