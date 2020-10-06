#include <stdio.h>
#include <stdlib.h>
struct STACK
{
    int i;         //用于判断是字符还是数字
    int flagOfTop; //用于判断是不是栈顶
    union data
    {
        int num;
        char operator;
    };
};
union data
{
    int num;
    char operator;
};
typedef struct STACK *STACK;
int isEmpty(STACK);
int isFull(STACK);
void makeEmpty(STACK);
void push(STACK, union data);
union data top(STACK);
void pop(STACK, union data);
union data topAndPop(STACK);

STACK createStack(STACK);
