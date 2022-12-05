#include <functional>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include "windows.h"


int main()
{
	int dice;//入力した数字を代入する変数
	int result = 0;
	int waitTime = 3000;//待ち時間用変数

	printf("数字を代入してください\n");
	scanf_s("%d", &dice);
	if (dice % 2 == 0)
	{
		printf("偶数\n");
	}
	else if (dice % 2 == 1)
	{
		printf("奇数\n");
	}

	//抽選関数
	std::function<int()> lottery = [&result]()
	{
		srand(time(nullptr));
		result = rand() % 2;
		return result;
	};

	//タイムアウトのセッター
	std::function<void(std::function<void()>, const int)> setTimeOut = [=](std::function<void()> fx, int time)
	{
		Sleep(time);
		fx();
	};

	//比較関数
	std::function<void(char, int)>compation = [=](char input, int output) {
		input % 2 == output ? printf("当たり\n") : printf("はずれ\n");
	};

	setTimeOut(lottery, waitTime);

	compation(dice, result);

	system("pause");
	return 0;
}



