#include "myStack.h"
int isLower(nodeOfStack A, nodeOfStack B); //有问题，没写运算先后顺序的判断，
//这两个还没有实现，留给梁家瑞好了
double mathOfOpr(double, double, char);
double mathOfFun(double, char);
void specialPush(STACK, nodeOfStack);
double reverse(nodeOfStack[]);
void printNode(nodeOfStack temp);
void dealWithBra(nodeOfStack, STACK, STACK,int*);
void dealWithFun(nodeOfStack, STACK, STACK);
char opr[5] = {'+', '-', '*', '/', '^'};
char bra[6] = {'[', ']', '{', '}', '(', ')'};
char func[26][6] = {"sin", "cos", "ln", "tan", "log", "!"};



void specialPush(STACK AB, nodeOfStack temp)
{
    if (temp.flag == Ope)
    {
        double a = topAndPop(AB).num;
        double b = topAndPop(AB).num;
        nodeOfStack ans = makeNode(mathOfOpr(a, b, temp.flag), '@');
        push(AB, ans);
    }
    else
    {
        double a = topAndPop(AB).num;
        nodeOfStack ans = makeNode(mathOfFun(a, temp.flag), '@');
        push(AB, ans);
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
void dealWithBra(nodeOfStack A, STACK BA, STACK AB,int* i)
{
    if (A.ch == '(')
    {
        (*i)++;
        push(BA, A);
    }
    else
    {
        (*i)--;
        nodeOfStack temp = topAndPop(BA);
        while (temp.ch != ')')
        {
            temp = top(BA);
            if (temp.flag != Bra)
            {
                specialPush(AB, temp);
                //printNode(temp);
            }
            else
            {
                pop(BA);
            }
            pop(BA);
        }
    }
}
void dealWithFun(nodeOfStack A, STACK BA, STACK AB)
{
    if (isLower(top(BA), A) || top(BA).flag == Bra || isEmpty(BA))
    {
        push(BA, A);
    }
    else
    {
        nodeOfStack temp = topAndPop(BA);
        while (!isLower(temp, A))
        {
            //通过函数实现
            specialPush(AB, temp);
            temp = topAndPop(BA);
        }
        push(BA, A);
        //printNode(temp);
    }
}
void dealWithDefault(STACK AB,STACK BA)
{
    while (!isEmpty(BA))
    {
        nodeOfStack temp = topAndPop(BA);
        specialPush(AB, temp);
    }
}
double reverse(nodeOfStack first[])
{
    int numOfNode = sizeof(first) / sizeof(nodeOfStack);
    int i = 0;
    STACK BA = createStack(BA); //内，暂存操作符
    STACK AB = createStack(AB); //内，暂存操作数
    push(BA, makeNode(0, '+'));
    push(AB, makeNode(0, '@'));
    while (i)
    {
        nodeOfStack A = first[i];
        switch (A.flag)
        {
        case Num:
            push(AB, A);//printf("%lf", A.num);
            break;
        case Bra:
            dealWithBra(A, BA, AB, &i);
            break;
        case Ope:
        case Fun: //A是新建的节点
            dealWithFun(A, BA, AB);
            break;
        default: //读入等号
            dealWithDefault(AB, BA);
            break;
        }
        printf("编译成功");
        getchar();
    }
    return topAndPop(AB).num;
}