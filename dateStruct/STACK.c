#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data
{
    int num;
    char operator;
    int flag;
};
struct STACK
{
    int i;         //用于判断是字符还是数字还是空栈
    int flagOfTop; //用于计算栈的个数
    struct data dataInStack[sizeof(int) * 1000];
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
void push(STACK, struct data);
struct data top(STACK);
void pop(STACK);
struct data topAndPop(STACK);
STACK createStack(STACK);
struct data makeNode(int a, char b); //若为数字，则b默认为@
int main()
{
    STACK sbwhx=malloc(sizeof(STACK));
    sbwhx = createStack(sbwhx);
    struct data wofule = makeNode(3, '@');
    push(sbwhx, wofule);
    getchar();
    return 0;
}
int isEmpty(STACK A)
{
    if (A->flagOfTop == 0)
    {
        return 1;
    }
}
void makeEmpty(STACK A)
{
    memset(A->dataInStack, 0, sizeof(int) * 1000);
    A->flagOfTop = 0;
}
void push(STACK A, struct data i)
{
    if (i.flag == CHAR)
    {
        A->dataInStack[A->flagOfTop].operator= i.operator;
        A->dataInStack[A->flagOfTop].flag= i.flag;
    }
    else
    {
        A->dataInStack[A->flagOfTop].flag = i.flag;
        A->dataInStack[A->flagOfTop].num = i.num;
    }
    A->flagOfTop += 1;
}
struct data top(STACK A)
{
    return A->dataInStack[A->flagOfTop];
}
void pop(STACK A)
{
    A->flagOfTop--;
}
struct data topAndPop(STACK A)
{
    struct data temp = top(A);
    pop(A);
    return temp;
}
STACK createStack(STACK A)
{
    printf("%d", A->flagOfTop);
    A->flagOfTop = 0;
    return A;
}
struct data makeNode(int a, char b)
{
    struct data temp;
    if (b == '@')
    {
        temp.flag = NUMBER;
        temp.num = a;
    }
    else
    {
        temp.flag = CHAR;
        temp.operator= b;
    }
    return temp;
}