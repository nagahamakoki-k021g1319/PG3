#include "Enemy.h"

bool Enemy::isAlive;

void Enemy::Juge()
{

	if (isAlive == true) {
		printf("�G�͂܂������Ă���\n");
	}
	else if (isAlive == false) {
		printf("�G�͑S�ł���\n");
	}
}
