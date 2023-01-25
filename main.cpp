#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include"Enemy.h"
using namespace std;



int main() {
 

	Enemy* enemy = new Enemy;
	Enemy* enemy2 = new Enemy;
	Enemy* enemy3 = new Enemy;


	int isExtin = 0;

	while (true) {

		printf("1‚Å“|‚· 2‚Å¶‚©‚·\n");
		scanf_s("%d", &isExtin);

		switch (isExtin)
		{
		case 1:// sine
			Enemy::isAlive = false;
			break;
		case 2:// ikikiru
			Enemy::isAlive = true;
			break;
		}

		if (isExtin == 1 || isExtin == 2) {
			enemy->Juge();
			enemy2->Juge();
			enemy3->Juge();
		}

		Sleep(1 * 1000);

	}

	delete enemy;
	delete enemy2;
	delete enemy3;


    system("pause");
    return 0;
}