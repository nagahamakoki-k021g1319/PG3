#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include"SceneManager.h"

int main() {
    //�C���X�^���X���擾���Ă����g�p
    SceneManager* sceneManager = SceneManager::GetInstance();

    int num = 0;
	

	while (true) {

		sceneManager->SceneNo(num);

		if (num >= 4) {

			num = 0;
		}
		else {

			num++;
		}

		Sleep(1 * 1000);

	}


    system("pause");
    return 0;
}