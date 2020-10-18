#include "reverse.h"
#include "getIn.h"
#include "myStack.h"
#include <math.h>
int isLower(nodeOfStack A, nodeOfStack B); //判断运算符优先级
double mathOfOpr(double, double, char);//实现二元运算符运算
double mathOfFun(double, char);//实现函数运算
void specialPush(STACK, nodeOfStack);//判断操作符为一元或二元（后者为存储操作符的栈）
double reverse(nodeOfStack[]);//主要计算函数
//void printNode(nodeOfStack temp);
void dealWithBra(nodeOfStack, STACK, STACK, int *);//处理括号（前括号入栈，后括号弹出数据）
void dealWithFun(nodeOfStack, STACK, STACK);//处理所有运算符（遇到二元弹出给mathOfFun处理）
int indexOfString = 0;//标记reverse数组下标
int numOfRecursion = 0;//递归次数
int flagOfRecursion = 0;//递归状态标记
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
    default: result = a;
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
    if (temp.flag == Ope)//双目加减乘除和乘方
    {
        double a = topAndPop(opdStack).num;
        double b = topAndPop(opdStack).num;
        nodeOfStack ans = makeNode(mathOfOpr(b, a, temp.ch), '@');
        push(opdStack, ans);
    }
    else//单目函数
    {
        double a = topAndPop(opdStack).num;
        nodeOfStack ans = makeNode(mathOfFun(a, temp.ch), '@');
        push(opdStack, ans);
    }
}

int startlevel(){  
    for (int i = 0; i < 256;i++){
        switch(i){
            case '+' :case '-':
                level[i] = 2; break;
            case '*':case'/':case '%':
                level[i] = 3; break;
            case '^':
                level[i] = 4; break;
        }
    }
    return 0;
}
int isLower(nodeOfStack A, nodeOfStack B)//A栈内B栈外    B优先时 返回1pushA
{
    int flag = 0;                                          //默认返回1
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
            if(level[B.ch]>level[A.ch])
                flag = 1;
        }  if (A.flag == Bra&&A.ch=='(')
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

        numOfRecursion++;//递归次数加一
        push(opdStack, makeNode(reverse(changedString), '@'));//递归求出左右括号内的值并创建栈元素点并压入栈中
        
    }
    else//右括号
    {
        (*i)--;//配平括号指数减小
        nodeOfStack temp = top(oprStack);//获取栈顶元素
        while (temp.ch != '(') //查看获取元素是否为匹配的左括号
        {
            temp = top(oprStack);
            if (temp.flag != Bra)
            {
                specialPush(opdStack, temp);
                //printNode(temp);
            }
            else
            {
                pop(oprStack);//弹出左括号
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
    if ( isEmpty(oprStack)|| top(oprStack).flag == Bra || isLower(top(oprStack), A))//操作符栈空&操作符栈栈顶元素为bra&操作符栈栈顶元素优先级低）
    {
        push(oprStack, A);//元素压入栈
    }
    else//元素优先级高
    {
        nodeOfStack temp = topAndPop(oprStack);
        while (!isLower(temp, A))//优先级高进行循环，直到优先级变低
        {
            //通过函数实现
            specialPush(opdStack, temp);
            temp = topAndPop(oprStack);
        }
        push(oprStack, A);//入栈
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
    int i = 0;//用于括号配平的计数器
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