#include<functional>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

typedef void (*PFunc)(int*);

void DispResult(int* s) {
    printf("%d�b�ԑҋ@\n", *s);
}

int main() {

    srand(time(nullptr));
    int getRand = rand();
    int player = 0;
    printf("���Ȃ�1,���Ȃ�2\n");
    scanf_s("%d", &player);

    std::function<int(PFunc, int, int)>fx = [](PFunc p, int x, int second) {
        p(&second);
        Sleep(second * 1000);

        return x % 2;
    };

    getRand = fx(DispResult, getRand, 3);


    //�������Ă邩�ǂ���
    std::function<void(int, int)>fortune = [](int playerSelect, int random) {

        playerSelect == random ? printf("������") : printf("�͂���");
    };

    fortune(player, getRand);


    return 0;
}
