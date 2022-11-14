#include<functional>
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

    std::function<int(PFunc, int, int)>fx = [](PFunc p, int x, int second) {
        p(&second);
        Sleep(second * 1000);

        return x % 2;
    };

    getRand = fx(DispResult, getRand, 3);


    //“–‚½‚Á‚Ä‚é‚©‚Ç‚¤‚©
    std::function<void(int, int)>fortune = [](int playerSelect, int random) {

        playerSelect == random ? printf("‘å“–‚½‚è") : printf("c”OA‚Í‚¸‚ê");
    };

    fortune(player, getRand);


    return 0;
}
