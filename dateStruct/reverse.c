#include "myStack.h"
int isLower(nodeOfStack A, nodeOfStack B); //有问题，没写运算先后顺序的判断，
//这两个还没有实现，留给梁家瑞好了
double mathOfOpr(double, double, char);
double mathOfFun(double, char);
void specialPush(STACK, nodeOfStack);
double reverse(nodeOfStack[]);
void printNode(nodeOfStack temp);
char opr[5] = {'+', '-', '*', '/', '^'};
char bra[6] = {'[', ']', '{', '}', '(', ')'};
char func[26][6] = {"sin", "cos", "ln", "tan", "log", "!"};
int main()
{
}
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
        nodeOfStack temp;
        switch (A.flag)
        {
        case Num:
            push(AB, A);
            //printf("%lf", A.num);
            break;
        case Bra:
            if (A.ch == '(')
            {
                i++;
                push(BA, A);
            }
            else
            {
                i--;
                temp = topAndPop(BA);
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
        case Ope:
        case Fun: //A是新建的节点
            if (isLower(top(BA), A) || top(BA).flag == Bra || isEmpty(BA))
            {
                push(BA, A);
            }
            else
            {
                temp = topAndPop(BA);
                while (!isLower(temp, A))
                {
                    //通过函数实现
                    specialPush(AB, temp);
                    temp = topAndPop(BA);
                }
                push(BA, A);
                //printNode(temp);
            }
        default: //读入等号
            while (!isEmpty(BA))
            {
                temp = topAndPop(BA);
                specialPush(AB, temp);
            }
            break;
        }

        printf("编译成功");
        getchar();
    }
    return topAndPop(AB).num;
}