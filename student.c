//***************************************
//** SUBMIT ONLY THIS FILE
//** ONLY PUT THE IMPLEMENTATION
//***************************************
#include <stdio.h>
#include <math.h>

#define PI		3.14159265358979323846

#define MAX 10
float mem[2*MAX];
int count=0;

float polarMem[2*MAX];

void swap(float *elem1, float *elem2){ // swap 2 elements
    float temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

void sortMemory(float *memory){ // bubble sort with pairs
    for(int i=0;i<count-1;i++){
        for(int j=0;j<count-1;j++){
            if(memory[j*2] >= memory[(j+1)*2]){
                if(memory[j*2] == memory[(j+1)*2] && memory[j*2+1] <= memory[(j+1)*2+1])
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
        printf("%d: %g[%gdeg]\n", i, polarMem[i*2], polarMem[i*2+1]);
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

    polarMem[count*2] = sqrt(pow(mem[count*2], 2) + pow(mem[count*2+1], 2)); // convert to polar and push to polar memory
    polarMem[count*2+1] = atan2f(mem[count*2+1], mem[count*2]) * 180 / PI;

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

    polarMem[count*2] = 0;
    polarMem[count*2+1] = 0;
    printf("Pop successful.\n\n");
}

void sort()
{
    sortMemory(mem);
    printf("Memory is now sorted.\n\n");
}

void sort_polar()
{
    sortMemory(polarMem);
    printf("Polar memory is now sorted.\n\n");
}
