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
    printf("0か1の番号の入力\n");
    scanf_s("%d", &result);
    
    int dice = rand();
    dice = dice % 2;

    Sleep(time* 1000);
    
    if (result == 0) {
        if (dice == 0) {
            printf("当たり\n");
        }
        else {
            printf("はずれ\n");
        }
    }
    else if (result == 1) {
        if (dice == 1) {
            printf("当たり\n");
        }
        else {
            printf("はずれ\n");
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