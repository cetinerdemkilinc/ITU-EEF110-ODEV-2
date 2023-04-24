//***************************************
//** DO NOT SUBMIT THIS FILE
//***************************************
#include <stdio.h>
#include <math.h>

void print();
void print_polar();
void push(float,float);
void pop();
void sort();
void sort_polar();

int main()
{
    push(5,2);
    push(4,4);
    push(4,3);
    push(7,6);
    push(2,2);
    push(1,1);
    push(1,-1);
    
    print_polar();
    sort_polar();
    print_polar();

    pop();
    pop();

    print();
    sort();
    print();
    return 0;
}
