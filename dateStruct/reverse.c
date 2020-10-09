#include<stdio.h>
#include<stdlib.h>
#define NUMofFUN 6
#define LENOFSTACK sizeof(struct data) * 1000
char opr[5] = {'+', '-', '*', '/', '^'};
char bra[6] = {'[', ']', '{', '}', '(', ')'};
char func[26][6] = {"sin", "cos", "ln", "tan", "log", "!"};
enum flager
{
    Num = 0,
    Fun,
    Ope,
    Bra,
    Not
};
struct data
{
    enum flager flag; //1--ch, 0--num,
    char ch;
    double num;
};

struct STACKER
{
    int i;         //用于判断是字符还是数字还是空栈
    int flagOfTop; //用于计算栈的个数
    struct data dataInStack[LENOFSTACK];
};

typedef struct STACKER *STACK;
typedef struct data nodeOfStack;
int isEmpty(STACK);
void makeEmpty(STACK);
void push(STACK, struct data);
struct data top(STACK);
void pop(STACK);
struct data topAndPop(STACK);
STACK createStack(STACK);
struct data makeNode(double a, char b); //若为数字，则b默认为@
void printStack(STACK);
void printNode(nodeOfStack);
int isLower(nodeOfStack A, nodeOfStack B);//A小于等于B返回1
int main()
{
    nodeOfStack A;
    STACK BA=createStack(BA);
    nodeOfStack temp;
    A = makeNode(12.0, '@');
    switch (A.flag)
    {
    case Num:
        printf("%lf", A.num);
        break;
    case Bra:
        if (A.ch=='(')
        {
            push(BA, A);
        }else
        {
            temp = topAndPop(BA);
            while (temp.ch!=')')
            {
                temp = top(BA);
                if (temp.flag!=Bra)
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
    case Ope:case Fun://A是新建的节点
        if (isLower(top(BA),A)||top(BA).flag==Bra)
        {
            push(BA, A);
        }else
        {
            temp = topAndPop(BA);
            while (! isLower(temp,A))
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