#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <random>
#include <Windows.h>

typedef void (*PFunc)(int*, int*);

void setTimerout(PFunc p, int second, int number) {
	//�R�[���o�b�N�֐����Ăяo��
	Sleep(second * 1000);

	p(&second, &number);
}

//�R�[���o�b�N�֐�
void DispResult(int* second, int* number) {
	//�����_��
	srand(time(nullptr));

	printf("3�b�҂��Ď��s���ꂽ��\n");

	int getRand = rand();
	getRand = getRand % 2;
	
	//��̏ꍇ
	if (*number == 1) {
		if (getRand % 2 == 1) {
			printf("�A�^��\n%d�����I�őI�΂�܂���\n", getRand);
		}
		else {
			printf("�n�Y��\n%d�����I�őI�΂�܂���\n", getRand);
		}
	}

	//�����̏ꍇ
	else if (*number == 2) {
		if (getRand % 2 == 0) {
			printf("�A�^��\n%d�����I�őI�΂�܂���\n", getRand);
		}
		else {
			printf("�n�Y��\n%d�����I�őI�΂�܂���\n", getRand);
		}
	}
}

int main() {

	int number = 0;
	//�����̓���
	printf("1��2����͂��Ă�������\n");
	scanf_s("%d", &number);

	PFunc p;

	p = DispResult;

	setTimerout(p, 3, number);

	system("pause");
	return 0;
}