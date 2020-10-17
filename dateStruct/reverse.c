#include "reverse.h"
#include "getIn.h"
#include "myStack.h"
#include <math.h>
int isLower(nodeOfStack A, nodeOfStack B); //有问题，没写运算先后顺序的判断，
double mathOfOpr(double, double, char);
double mathOfFun(double, char);
void specialPush(STACK, nodeOfStack);
double reverse(nodeOfStack[]);
//void printNode(nodeOfStack temp);
void dealWithBra(nodeOfStack, STACK, STACK, int *);
void dealWithFun(nodeOfStack, STACK, STACK);
int indexOfString = 0;
int numOfRecursion = 0;
int flagOfRecursion = 0;
static int level[256];

double mathOfOpr(double a, double b, char c)
{
    double result; //保存单目运算结果
    switch (c) {
    case '+': result = a + b; break;
    case '-': result = a - b; break;
    case '*':result = a * b; break;
    case '/':result = a / b; break;
    case '^':result = pow(a, b); break;
    case '%':result = a - b * ((int)a /(int) b); break;
    defualt: result = a;
    }
    return result;
}

double mathOfFun(double a, char b)
{
    double result; //保存函数运算结果
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
    else result = a;
    return result;
}
void specialPush(STACK opdStack, nodeOfStack temp)
{
    if (temp.flag == Ope)
    {
        double a = topAndPop(opdStack).num;
        double b = topAndPop(opdStack).num;
        nodeOfStack ans = makeNode(mathOfOpr(b, a, temp.ch), '@');
        push(opdStack, ans);
    }
    else
    {
        double a = topAndPop(opdStack).num;
        nodeOfStack ans = makeNode(mathOfFun(a, temp.ch), '@');
        push(opdStack, ans);
    }
}

int startlevel(char n){
  
    for (int i = 0; i < 256;i++){
        switch(i){
            case '+' :case '-':
                level[i] = 2;
            case '*':case'/':
                level[i] = 3;
        }
    }
    return level[n];
}
int isLower(nodeOfStack A, nodeOfStack B)
{
    int flag = 0;//1 xian B, 0 xian A
    if (A.ch==B.ch)
    {
        flag = 1;
    }
    else if  (A.flag == Ope && B.flag == Fun)
        {
            flag= 1;
        }
        else if (A.flag == Ope && B.flag == Ope)
        {
            if(level(B.flag)>level(A.flag))
                flag = 1;
        }else if (A.flag==Bra)
        {
            flag = 1;
        }
        
        return flag;
}
// int isLower(nodeOfStack A, nodeOfStack B) //A 是栈顶元素 B是马上入栈的元素 A比B小，返回1
// {
//     if (A.flag == Fun && B.flag == Ope)
//     {
//         return 0;
//     }
//     else if (A.flag == Ope && B.flag == Fun)
//     {
//         return 1;
//     }
//     else if (A.flag == Ope && B.flag == Ope)
//     {
//         if (B.ch == '+' && B.ch == '-')
//         {
//             return 0;
//         }
//         else if (B.ch == '*' && B.ch == '/')
//         {
//             if (A.ch == '+' && A.ch == '-')
//             {
//                 return 1;
//             }
//             else
//             {
//                 return 0;
//             }
//         }
//     }

//     return A.ch <= B.ch;
// }
void dealWithBra(nodeOfStack A, STACK oprStack, STACK opdStack, int *i)
{
    if (A.ch == '(')
    {
        (*i)++;
        numOfRecursion++;
        push(opdStack, makeNode(reverse(changedString), '@'));
        (*i)--;
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
            if (isEmpty(oprStack))
            {
                break;
            }
            
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
double reverse(nodeOfStack first[])
{
    //int numOfNode = sizeof(first) / sizeof(nodeOfStack);
    startlevel();
    int i = 0;
    if (numOfRecursion != 0)
    {
        i = 1;
    }

    STACK oprStack = createStack(); //内，暂存操作符(operatorStack操作符栈)
    STACK opdStack = createStack(); //内，暂存操作数(operandStack操作数栈)
    if (numOfRecursion != 0)
    {
        push(oprStack, makeNode(0, '('));
    }

    push(opdStack, makeNode(0, '@'));
    do
    {
        nodeOfStack A = first[indexOfString];
        indexOfString++;
        switch (A.flag)
        {
        case Num:
            push(opdStack, A); //printf("%lf", A.num);
            break;
        case Bra:
            dealWithBra(A, oprStack, opdStack, &i);
            break;
        case Ope:
        case Fun: //A是新建的节点
            dealWithFun(A, oprStack, opdStack);
            break;
        default: //读入等号
            dealWithDefault(opdStack, oprStack);
            return topAndPop(opdStack).num;
            break;
        }
    } while (i);
    return topAndPop(opdStack).num;
}