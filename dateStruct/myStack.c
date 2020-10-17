#include "myStack.h"
#include "getIn.h"
int isEmpty(STACK A) //判断栈是否为空
{
    if (A->flagOfTop == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void makeEmpty(STACK A) //将栈清空
{
    memset(A->dataInStack, 0, sizeof(int) * 1000);
    A->flagOfTop = 1;
}
void push(STACK A, struct data i) //向栈内添加一个元素
{
    if (i.flag != Num && i.flag != Not) //字符情况
    {
        A->dataInStack[A->flagOfTop].ch = i.ch;
        A->dataInStack[A->flagOfTop].flag = i.flag;
    }
    else if (i.flag == Num) //数字情况
    {
        A->dataInStack[A->flagOfTop].flag = i.flag;
        A->dataInStack[A->flagOfTop].num = i.num;
    }
    A->flagOfTop += 1;
}
struct data top(STACK A) //查看栈顶元素
{
    return A->dataInStack[A->flagOfTop - 1];
}
void pop(STACK A) //弹出栈顶元素
{
    A->flagOfTop--;
}
struct data topAndPop(STACK A) //查看并弹出栈顶元素
{
    struct data temp = top(A);
    pop(A);
    return temp;
}
STACK createStack() //创建一个栈
{
    STACK A = (STACK)malloc(LENOFSTACK);
    A->flagOfTop = 1;
    return A;
}
struct data makeNode(double a, char b) //创建一个节点
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
        else if (b == '(' || b == ')') //也可以读取中括号，但实际当作小括号处理*
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
void printStack(STACK stack) //打印栈
{
    for (int i = 0; i < stack->flagOfTop; i++)
    {
        printf("%.3lf     ", stack->dataInStack[i].num);
    }
}