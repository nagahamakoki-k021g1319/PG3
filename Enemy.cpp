#include "Enemy.h"

void Enemy::Func1()
{
	printf("‹ßÚ\n");
}

void Enemy::Func2()
{
	printf("ŽËŒ‚\n");
}

void Enemy::Func3()
{
	printf("—£’E\n");
}

void Enemy::Update()
{
	(this->*Action[phase_])();
	phase_++;
	if (phase_ > 2) {
		phase_ = 0;
	}

}

void Enemy::Reset()
{
	phase_ = 0;
}


void (Enemy::* Enemy::Action[])() = {
		&Enemy::Func1,
		&Enemy::Func2,
		&Enemy::Func3
};