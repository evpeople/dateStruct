#include "reverse.h"
#include "getIn.h"
#include "myStack.h"
#include <math.h>
int isLower(nodeOfStack A, nodeOfStack B); //有问题，没写运算先后顺序的判断，
double mathOfOpr(double, double, char);
double mathOfFun(double, char);
void specialPush(STACK, nodeOfStack);
double reverse(nodeOfStack[],int);
void printNode(nodeOfStack temp);
void dealWithBra(nodeOfStack, STACK, STACK, int *);
void dealWithFun(nodeOfStack, STACK, STACK);

double mathOfOpr(double a, double b, char c)
{
    double result; //保存单目运算结果
    if (c == '+')
    {
        result = a + b;
    }
    else if (c == '-')
    {
        result = a - b;
    }
    else if (c == '*')
    {
        result = a * b;
    }
    else if (c == '/')
    {
        result = a / b;
    }
    else if (c == '^')
    {
        result = pow(a, b);
    }
    return result;
}

double mathOfFun(double a, char b)
{
    double result; //保存函数运算结果
    int tempjc;    //运算阶乘使用的int类型数
    if (b == 'A')
    {
        result = sin(a);
    }
    else if (b == 'B')
    {
        result = log(a);
    }
    else if (b == 'C')
    {
        result = tan(a);
    }
    else if (b == 'D')
    {
        result = cos(a);
    }
    else if (b == 'E')
    {
        result = log10(a);
    }
    else if (b == 'F')
    {
        tempjc = (int)a;
        result = 1;
        while (tempjc > 1)
        {
            result = result * tempjc;
            tempjc--;
        }
    }
    return result;
}
void specialPush(STACK opdStack, nodeOfStack temp)
{
    if (temp.flag == Ope)
    {
        double a = topAndPop(opdStack).num;
        double b = topAndPop(opdStack).num;
        nodeOfStack ans = makeNode(mathOfOpr(a, b, temp.ch), '@');
        push(opdStack, ans);
    }
    else
    {
        double a = topAndPop(opdStack).num;
        nodeOfStack ans = makeNode(mathOfFun(a, temp.ch), '@');
        push(opdStack, ans);
    }
}
void printNode(nodeOfStack temp)
{
    if (temp.flag == Num)
    {
        printf("%lf", temp.num);
    }
    else if (temp.flag == Ope || temp.flag == Fun)
    {
        printf("%c", temp.ch);
    }
}
int isLower(nodeOfStack A, nodeOfStack B)
{
    return A.ch <= B.ch;
}
void dealWithBra(nodeOfStack A, STACK oprStack, STACK opdStack, int *i)
{
    if (A.ch == '(')
    {
        (*i)++;
        push(oprStack, A);
    }
    else
    {
        (*i)--;
        nodeOfStack temp = top(oprStack);
        while (temp.ch != '(') //TODO:
        {
            temp = top(oprStack);
            if (temp.flag != Bra)
            {
                specialPush(opdStack, temp);
                //printNode(temp);
            }
            else
            {
                pop(oprStack);
            }
            pop(oprStack);
            temp = top(oprStack);
        }
    }
}
void dealWithFun(nodeOfStack A, STACK oprStack, STACK opdStack)
{
    if (isLower(top(oprStack), A) || top(oprStack).flag == Bra || isEmpty(oprStack))
    {
        push(oprStack, A);
    }
    else
    {
        nodeOfStack temp = topAndPop(oprStack);
        while (!isLower(temp, A))
        {
            //通过函数实现
            specialPush(opdStack, temp);
            temp = topAndPop(oprStack);
        }
        push(oprStack, A);
        //printNode(temp);
    }
}
void dealWithDefault(STACK opdStack, STACK oprStack)
{
    while (!isEmpty(oprStack))
    {
        nodeOfStack temp = topAndPop(oprStack);
        specialPush(opdStack, temp);
    }
}
double reverse(nodeOfStack first[],int index)
{
    //int numOfNode = sizeof(first) / sizeof(nodeOfStack);
    int i = 0;
    int index = 0;
    STACK oprStack = createStack(); //内，暂存操作符(operatorStack操作符栈)
    STACK opdStack = createStack(); //内，暂存操作数(operandStack操作数栈)
    push(oprStack, makeNode(0, '+'));
    push(opdStack, makeNode(0, '@'));
    do
    {
        nodeOfStack A = first[index];
        index++;
        switch (A.flag)
        {
        case Num:
            push(opdStack, A); //printf("%lf", A.num);
            break;
        case Bra:
            dealWithBra(A, oprStack, opdStack, &i);
            break;
        case Ope:
            dealWithFun(A, oprStack, opdStack);
            break;
        case Fun: //A是新建的节点
            double tempNum=reverse(first,index,'@');
            nodeOfStack tempNode=makeNode(tempNum,'@');
            dealWithFun(tempNode,oprStack,opdStack);
        default: //读入等号
            dealWithDefault(opdStack, oprStack);
            break;
        }
    } while (i);
    return topAndPop(opdStack).num;
}