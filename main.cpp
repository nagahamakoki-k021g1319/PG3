#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

typedef void (*PFunc)(int*);

void DispResult(int* s) {
    printf("%d•bŠÔ‘Ò‹@\n", *s);
}

void setTimerout(PFunc p, int second) {
    p(&second);

    Sleep(second* 1000);
}

int main() {

    srand(time(nullptr));
    int getRand = rand();
    int player = 0;
    scanf_s("%d", &player);

    getRand = getRand % 2;

    PFunc p;
    p = DispResult;

    setTimerout(p, 3);

    if (player == 0) {
        if (getRand == 0) {
            printf("‘å“–‚½‚è");
        }
        else {
            printf("c”OA‚Í‚¸‚ê");
        }
    }
    else if (player == 1) {
        if (getRand == 1) {
            printf("‘å“–‚½‚è");
        }
        else {
            printf("c”OA‚Í‚¸‚ê");
        }
    }

    return 0;
}