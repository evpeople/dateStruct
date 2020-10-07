#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
union data
{
    int num;
    char operator;
};
struct STACK
{
    int i;         //用于判断是字符还是数字还是空栈
    int flagOfTop; //用于计算栈的个数
    union data dataInStack[sizeof(int)*1000];
};

enum SIGN
{
    ZERO,
    CHAR,
    NUMBER
};
typedef struct STACK *STACK;
int isEmpty(STACK);
void makeEmpty(STACK);
void push(STACK, union data);
union data top(STACK);
void pop(STACK, union data);
union data topAndPop(STACK);
STACK createStack(STACK);

int main()
{

    return 0;
}
int isEmpty(STACK A)
{
    if (A->flagOfTop==0)
    {
        return 1;
    }
}
void makeEmpty(STACK A)
{
    memset(A->dataInStack, 0, sizeof(int) * 1000);
    A->flagOfTop = 0;
}
void push(STACK A, union data i)
{
    A->flagOfTop+=1;
    if (i.operator>='A'&&i.operator<='Z')
    {
        A->dataInStack[A->flagOfTop].operator = i.operator;
    }else
    {
        A->dataInStack[A->flagOfTop].num = i.num;    
    }
}
union data top(STACK A)
{
    return A->dataInStack[A->flagOfTop];
}
void pop(STACK A)
{
    A->flagOfTop--;
}
union data topAndPop(STACK  A)
{
    union data temp=top(A);
    pop(A);
    return temp;
}
STACK createStack(STACK A)
{
    A[]
}