#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct cell {
    int val;
    struct cell* prev;
    struct cell* next;
} CELL;

CELL* getInsertCellAddress(CELL* endCELL, int iterator) {
    for (int i = 0; i < iterator; i++){
        if (endCELL->next) {
            endCELL = endCELL->next;
        }
        else{
            break;
        }
    }
    return endCELL;
}


void create(CELL* currentCell, int val) {
    CELL* newCell;
    newCell = (CELL*)malloc(sizeof(CELL));
    newCell->val = val;
    newCell->prev = currentCell;
    newCell->next = currentCell->next;

    if (currentCell->next) {
        CELL* nextCell = currentCell->next;
        nextCell->prev = newCell;
    }

    currentCell->next = newCell;
}

void index(CELL* endCell) {
    int no = 1;
    while (endCell->next != nullptr){
        endCell = endCell->next;
        printf("%d", no);
        printf("%p", endCell->prev);
        printf("%5d", endCell->val);
        printf("(%p)", endCell);
        printf("%p\n", endCell->next);
        no++;
    }
}


int main() {
    
    int itetator;
    int inputValue;
    CELL* insertCell;
    //�擪�̃Z����錾
    CELL head;
    head.next = nullptr;
    head.prev = nullptr;


    while (1)
    {
        printf("���Ԗڂ̃Z���̌��ɑ}�����܂���?\n");
        scanf_s("%d", &itetator);

        printf("�}������l����͂��Ă�������\n");
        scanf_s("%d", &inputValue);

        insertCell = getInsertCellAddress(&head, itetator);
        create(insertCell, inputValue);

        index(&head);
    }

    system("pause");
    return 0;
}
