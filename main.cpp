#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include"Enemy.h"
using namespace std;



int main() {
 


	Enemy* enemy = new Enemy;

	enemy->Reset();

	while (true) {

		enemy->Update();

		// Œ‹‰Ê‚ðŒ©‚â‚·‚­‚·‚é‚½‚ß
		Sleep(1 * 1000);

	}

	delete enemy;

    system("pause");
    return 0;
}