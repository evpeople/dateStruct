#include"myStack.h"
#include"getIn.h"
#include"reverse.h"
#include "print.h"
int main()
{

    //printf("wsdsaad");
    while (1)
    {
        nodeOfStack *A = getInArray();
        //printf("%c", A[1].ch);
        //system("pause");
        //printf("wsdsaad");
        if (A == NULL) { 
            printf("«Î ‰»Î£∫\n"); 
            printf("<<<<<====-------------------------====>>>>>");
            continue; 
        }
        double theAnswer = reverse(A);
        printAns(theAnswer);
        printf("<<<<<====-------------------------====>>>>>");
    }
    
    nodeOfStack *A = getInArray();
    if (A == NULL)printf("«Î ‰»Î£∫\n");
    double theAnswer = reverse(A);
    printAns(theAnswer);
    printf("<<<<<====-------------------------====>>>>>");
    getchar();
    getchar();
    getchar();
    return 0;
}