#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <random>
#include <Windows.h>

typedef void (*PFunc)(int*, int*);

void setTimerout(PFunc p, int second, int number) {
	//コールバック関数を呼び出す
	Sleep(second * 1000);

	p(&second, &number);
}

//コールバック関数
void DispResult(int* second, int* number) {
	//ランダム
	srand(time(nullptr));

	printf("3秒待って実行されたよ\n");

	int getRand = rand();
	getRand = getRand % 2;
	
	//奇数の場合
	if (*number == 1) {
		if (getRand % 2 == 1) {
			printf("アタリ\n%dが抽選で選ばれました\n", getRand);
		}
		else {
			printf("ハズレ\n%dが抽選で選ばれました\n", getRand);
		}
	}

	//偶数の場合
	else if (*number == 2) {
		if (getRand % 2 == 0) {
			printf("アタリ\n%dが抽選で選ばれました\n", getRand);
		}
		else {
			printf("ハズレ\n%dが抽選で選ばれました\n", getRand);
		}
	}
}

int main() {

	int number = 0;
	//数字の入力
	printf("1か2を入力してください\n");
	scanf_s("%d", &number);

	PFunc p;

	p = DispResult;

	setTimerout(p, 3, number);

	system("pause");
	return 0;
}