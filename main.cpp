#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

typedef void (*PFunc)(int*);

void Result(int* s) {
    printf("%d•bŠÔ‘Ò‹@\n", *s);
}

void setTimerout(PFunc p, int second) {
    p(&second);

    Sleep(second* 1000);
}

int main() {

    srand(time(nullptr));
    int dice = rand();
    int player = 0;
    
    printf("0‚©1‚ð“ü—Í‚µ‚Ä‚Ë\n");
    scanf_s("%d", &player);

    dice = dice % 2;

    PFunc p;
    p = Result;

    setTimerout(p, 3);

    if (player == 0) {
        if (dice == 0) {
            printf("“–‚½‚è");
        }
        else {
            printf("‚Í‚¸‚ê");
        }
    }
    else if (player == 1) {
        if (dice == 1) {
            printf("“–‚½‚è");
        }
        else {
            printf("‚Í‚¸‚ê");
        }
    }

    return 0;
}