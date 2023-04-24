//***************************************
//** SUBMIT ONLY THIS FILE
//** ONLY PUT THE IMPLEMENTATION
//***************************************
#include <stdio.h>
#include <math.h>

#define PI		3.14159265358979323846

#define SORT_NORMAL 0
#define SORT_POLAR 1

#define MAX 10
float mem[2*MAX];
int count=0;

void swap(float *elem1, float *elem2){ // swap 2 elements
    float temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

void convertToPolar(int memInd, float *to){
    to[0] = sqrt(pow(mem[memInd], 2) + pow(mem[memInd+1], 2)); // convert to polar and push to polar memory
    to[1] = atan2f(mem[memInd+1], mem[memInd]) * 180 / PI;
}

void sortMemory(float *memory, int type){ // bubble sort with pairs

    for(int i=0;i<count-1;i++){
        for(int j=0;j<count-1;j++){
            float first[2], second[2];
            if(type == SORT_POLAR){
                convertToPolar(j*2, first);
                convertToPolar((j+1)*2, second);
            }
            else if(type == SORT_NORMAL){
                first[0] = mem[j*2];
                first[1] = mem[j*2+1];

                second[0] = mem[(j+1)*2];
                second[1] = mem[(j+1)*2+1];
            }
            if(first[0] >= second[0]){
                if(first[0] == second[0] && first[1] <= second[1])
                    continue;
                swap(&memory[(j+1)*2], &memory[j*2]);
                swap(&memory[(j+1)*2+1], &memory[j*2+1]);
            }
        }
    }
}

void print()
{
    printf("Print memory:\n");
    for(int i=0;i<count;i++){
        printf("%d: %g + %gi\n", i, mem[i*2], mem[i*2+1]);
    }
    printf("\n");
}

void print_polar()
{
    printf("Print polar memory:\n");
    for(int i=0;i<count;i++){
        float polarTemp[2];
        convertToPolar(i*2, polarTemp);
        printf("%d: %g[%gdeg]\n", i, polarTemp[0], polarTemp[1]);
    }
    printf("\n");
}

void push(float re,float im)
{
    if(count >= MAX){
        printf("There is no enough space. Could not push.\n\n");
        return;
    }
    mem[count*2] = re;
    mem[count*2+1] = im;

    count++;
    printf("Push successful.\n\n");
}

void pop()
{
    if(count <= 0){
        printf("There is no element in memory. Could not pop.\n\n");
        return;
    }
    count--;
    
    mem[count*2] = 0;
    mem[count*2+1] = 0;

    printf("Pop successful.\n\n");
}

void sort()
{
    sortMemory(mem, SORT_NORMAL);
    printf("Memory is now sorted.\n\n");
}

void sort_polar()
{
    sortMemory(mem, SORT_POLAR);
    printf("Polar memory is now sorted.\n\n");
}
