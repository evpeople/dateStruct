#include"myStack.h"
#include"getIn.h"
#include"reverse.h"

#include "print.h"

nodeOfStack *changedString;
int indexOfString;

int main()
{

    //printf("wsdsaad");
    while (1)
    {
        changedString = getInArray();
        //printf("%c", A[1].ch);
        //system("pause");
        //printf("wsdsaad");
        double answer = reverse(changedString);
        printf("%lf\n", answer);
        indexOfString = 0;
        printf("whxNB ljrNB wzNB");
    }
    
    nodeOfStack *A = getInArray();
    if (A == NULL)printf("�����룺\n");
    double theAnswer = reverse(A);
    printAns(theAnswer);
    printf("<<<<<====-------------------------====>>>>>");
    getchar();
    getchar();
    getchar();
    return 0;
}