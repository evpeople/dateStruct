#include"myStack.h"
#include"getIn.h"
#include"reverse.h"
<<<<<<< HEAD
#include "print.h"
=======
nodeOfStack *changedString;
int twhx;
>>>>>>> 1e05e5e8963511c69e42780f331ab94f4c415332
int main()
{

    //printf("wsdsaad");
    while (1)
    {
        changedString = getInArray();
        //printf("%c", A[1].ch);
        //system("pause");
        //printf("wsdsaad");
<<<<<<< HEAD
        if (A == NULL) { 
            printf("«Î ‰»Î£∫\n"); 
            printf("<<<<<====-------------------------====>>>>>");
            continue; 
        }
        double theAnswer = reverse(A);
        printAns(theAnswer);
        printf("<<<<<====-------------------------====>>>>>");
=======
        double answer = reverse(changedString);
        printf("%lf\n", answer);
        twhx = 0;
        printf("whxNB ljrNB wzNB");
>>>>>>> 1e05e5e8963511c69e42780f331ab94f4c415332
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