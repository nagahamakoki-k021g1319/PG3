#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include "Circle.h"
#include "IShape.h"
#include "Rectangle.h"
using namespace std;



int main() {
    
    IShape* iShape[] = {
        new Circle,
        new Rectangle
    };


    iShape[0]->size();
    iShape[0]->draw();

    iShape[1]->size();
    iShape[1]->draw();

    delete iShape[0];
    delete iShape[1];

    system("pause");
    return 0;
}