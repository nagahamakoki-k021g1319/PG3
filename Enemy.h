#pragma once
#include <stdio.h>
#include <stdlib.h>

class Enemy
{
public:
	//自作メンバ関数
	void Func1();
	void Func2();
	void Func3();

	//死ぬ?生きる?
	void Update();

	//リセット
	void Reset();

private:

	//メンバ関数ポインタのテーブル
	static void (Enemy::* Action[])();


private:
	int phase_ = 0;
};

