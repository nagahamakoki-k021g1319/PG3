#include "Enemy.h"

bool Enemy::isAlive;

void Enemy::Juge()
{

	if (isAlive == true) {
		printf("敵はまだ生きている\n");
	}
	else if (isAlive == false) {
		printf("敵は全滅した\n");
	}
}
