#include "myStack.h"
/*
考虑当作函数实现
if (temp.flag==Ope)
                    {
                        double a = topAndPop(AB).num;
                        double b = topAndPop(AB).num;
                        nodeOfStack ans=makeNode(mathOfOpr(a,b,temp.flag),'@');
                        push(AB, ans);
                    }else
                    {
                        double a = topAndPop(AB).num;
                        nodeOfStack ans = makeNode(mathOfFun(a, temp.flag),'@');
                        push(AB, ans);
                    }*/

int isLower(nodeOfStack A, nodeOfStack B);//有问题，没写运算先后顺序的判断，
double mathOfOpr(double, double, char);
double mathOfFun(double, char);
//这两个还没有实现，留给梁家瑞好了
void printNode(nodeOfStack temp);
<<<<<<< HEAD
//
//int main()
//{
//    nodeOfStack A;
//    STACK BA = createStack(&BA);
//    nodeOfStack temp;
//    A = makeNode(12.0, '@');
//    switch (A.flag)
//    {
//    case Num:
//        printf("%lf", A.num);
//        break;
//    case Bra:
//        if (A.ch == '(')
//        {
//            push(BA, A);
//        }
//        else
//        {
//            temp = topAndPop(BA);
//            while (temp.ch != ')')
//            {
//                temp = top(BA);
//                if (temp.flag != Bra)
//                {
//                    printNode(temp);
//                }
//                else
//                {
//                    pop(BA);
//                }
//                pop(BA);
//            }
//        }
//    case Ope:
//    case Fun: //A是新建的节点
//        if (isLower(top(BA), A) || top(BA).flag == Bra)
//        {
//            push(BA, A);
//        }
//        else
//        {
//            temp = topAndPop(BA);
//            while (!isLower(temp, A))
//            {
//                printNode(temp);
//                temp = topAndPop(BA);
//            }
//            push(BA, A);
//            printNode(temp);
//        }
//
//    default:
//        while (!isEmpty(BA))
//        {
//            temp = topAndPop(BA);
//            printNode(temp);
//        }
//
//        break;
//    }
//
//    printf("编译成功");
//    getchar();
//}
=======
char opr[5] = {'+', '-', '*', '/', '^'};
char bra[6] = {'[', ']', '{', '}', '(', ')'};
char func[26][6] = {"sin", "cos", "ln", "tan", "log", "!"};
int main()
{
    nodeOfStack A;
    STACK BA = createStack(BA);
    STACK AB = createStack(AB);
    nodeOfStack temp;
    A = makeNode(12.0, '@');
    switch (A.flag)
    {
    case Num:
        push(AB, A);
        //printf("%lf", A.num);
        break;
    case Bra:
        if (A.ch == '(')
        {
            push(BA, A);
        }
        else
        {
            temp = topAndPop(BA);
            while (temp.ch != ')')
            {
                temp = top(BA);
                if (temp.flag != Bra)
                {   
                    if (temp.flag==Ope)
                    {
                        double a = topAndPop(AB).num;
                        double b = topAndPop(AB).num;
                        nodeOfStack ans=makeNode(mathOfOpr(a,b,temp.flag),'@');
                        push(AB, ans);
                    }else
                    {
                        double a = topAndPop(AB).num;
                        nodeOfStack ans = makeNode(mathOfFun(a, temp.flag),'@');
                        push(AB, ans);
                    }
                    
                    
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
        if (isLower(top(BA), A) || top(BA).flag == Bra||isEmpty(BA))
        {
            push(BA, A);
        }
        else
        {
            temp = topAndPop(BA);
            while (!isLower(temp, A))
            {
                //通过函数实现
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
                //printNode(temp);
                temp = topAndPop(BA);
            }
            push(BA, A);
            printNode(temp);
        }

    default:
        while (!isEmpty(BA))
        {
            temp = topAndPop(BA);
            printNode(temp);
        }

        break;
    }

    printf("编译成功");
    getchar();
}
>>>>>>> 8649168e9cbf72a70732b4d6768dd85b2fa95a86
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