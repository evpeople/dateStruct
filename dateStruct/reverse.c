#include "myStack.h"

int isLower(nodeOfStack A, nodeOfStack B);
void printNode(nodeOfStack temp);
char opr[5] = {'+', '-', '*', '/', '^'};
char bra[6] = {'[', ']', '{', '}', '(', ')'};
char func[26][6] = {"sin", "cos", "ln", "tan", "log", "!"};
int main()
{
    nodeOfStack A;
    STACK BA = createStack(BA);
    nodeOfStack temp;
    A = makeNode(12.0, '@');
    switch (A.flag)
    {
    case Num:
        printf("%lf", A.num);
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
                    printNode(temp);
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
        if (isLower(top(BA), A) || top(BA).flag == Bra)
        {
            push(BA, A);
        }
        else
        {
            temp = topAndPop(BA);
            while (!isLower(temp, A))
            {
                printNode(temp);
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