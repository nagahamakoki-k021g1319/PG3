#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <random>
#include <Windows.h>

typedef int(pRand)();

int GetRand() {
    return rand();
}

int setTimerout(pRand rand, int time) {
    int result;
    printf("0��1�̔ԍ��̓���\n");
    scanf_s("%d", &result);
    
    int dice = rand();
    dice = dice % 2;

    Sleep(time* 1000);
    
    if (result == 0) {
        if (dice == 0) {
            printf("������\n");
        }
        else {
            printf("�͂���\n");
        }
    }
    else if (result == 1) {
        if (dice == 1) {
            printf("������\n");
        }
        else {
            printf("�͂���\n");
        }
    }
    return 0;
}

int main() {
    srand(time(nullptr));
    pRand *random = GetRand;
    int randTrue = setTimerout(random, 3);

    system("pause");
    return 0;
}