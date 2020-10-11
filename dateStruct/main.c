#include"myStack.h"
#include"getIn.h"
#include"reverse.h"

int main()
{

    //printf("wsdsaad");
    while (1)
    {
        nodeOfStack *A = getInArray();
        //printf("%c", A[1].ch);
        //system("pause");
        //printf("wsdsaad");
        double answer = reverse(A);
        printf("%lf\n", answer);
        printf("whxNB ljrNB wzNB");
    }
    
    nodeOfStack *A = getInArray();
    double answer = reverse(A);
    printf("%lf\n", answer);
    printf("whxNB ljrNB wzNB");
    getchar();
    getchar();
    getchar();
    return 0;
}