#include "Enemy.h"

bool Enemy::isAlive = true;

void Enemy::Juge()
{

	if (isAlive == true) {
		printf("“G‚Í‚Ü‚¾¶‚«‚Ä‚¢‚é\n");
	}
	else if (isAlive == false) {
		printf("“G‚Í‘S–Å‚µ‚½\n");
	}
}
