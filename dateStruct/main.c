#include"myStack.h"
#include"getIn.h"
#include"reverse.h"

#include "print.h"

nodeOfStack *changedString;
int indexOfString;
int numOfRecursion;
int flagOfRecursion;
int main()
{
    printf("输出调整请键入命令mod=\n");

    while (1)
    {
        printf("请输入\n");
        changedString = getInArray();
        if (changedString == NULL) {
            printf("请输入\n");
            continue;
        }
        double theAnswer = reverse(changedString);
        printAns(theAnswer);
        indexOfString = 0;
        numOfRecursion = 0;
        flagOfRecursion = 0;
        printf("\n<<<<<====-------------------------====>>>>>\n");
        printf("whxNB ljrNB wzNB\n");
    }
    return 0;
}