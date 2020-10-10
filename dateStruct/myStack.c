#include "myStack.h"
#include "getIn.h"
int isEmpty(STACK A)
{
    if (A->flagOfTop == 1)
    {
        return 1;
    }
}
void makeEmpty(STACK A)
{
    memset(A->dataInStack, 0, sizeof(int) * 1000);
    A->flagOfTop = 1;
}
void push(STACK A, struct data i)
{
    if (i.flag != Num && i.flag != Not)
    {
        A->dataInStack[A->flagOfTop].ch = i.ch;
        A->dataInStack[A->flagOfTop].flag = i.flag;
    }
    else if (i.flag == Num)
    {
        A->dataInStack[A->flagOfTop].flag = i.flag;
        A->dataInStack[A->flagOfTop].num = i.num;
    }
    A->flagOfTop += 1;
}
struct data top(STACK A)
{
    return A->dataInStack[A->flagOfTop - 1];
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
STACK createStack()
{
    STACK A = (STACK)malloc(LENOFSTACK);
    A->flagOfTop = 1;
    return A;
}
struct data makeNode(double a, char b)
{
    struct data temp;
    if (b == '@')
    {
        temp.flag = Num;
        temp.num = a;
    }
    else
    {
        temp.flag = Not;
        if (b >= 'A' && 'b' <= 'Z')
            temp.flag = Fun;
        if (b >= 'a' && b <= 'z')
            temp.flag = Cstn;
        else if (b == '(' || b == ')')
            temp.flag = Bra;
        else
        {
            int ifOpe = 0;
            for (int i = 0; i < NUMofOpe; i++)
            {
                if (b == opr[i])
                    ifOpe = 1;
            }
            if (ifOpe)
                temp.flag = Ope;
        }
        if (temp.flag == Not)
            printf("Error!--The \"makeNode by %c \" is Not a avaliable char!\n", b);
        temp.ch = b;
    }
    return temp;
}
void printStack(STACK stack)
{
    for (int i = 0; i < stack->flagOfTop; i++)
    {
        printf("%.3lf     ", stack->dataInStack[i].num);
    }
}