#pragma once
#include <stdio.h>
#include <stdlib.h>

class Enemy
{
public:
	//���상���o�֐�
	void Func1();
	void Func2();
	void Func3();

	//����?������?
	void Update();

	//���Z�b�g
	void Reset();

private:

	//�����o�֐��|�C���^�̃e�[�u��
	static void (Enemy::* Action[])();


private:
	int phase_ = 0;
};

