#include "myStack.h"
#include "getIn.h"
#include "reverse.h"

#include "print.h"

nodeOfStack *changedString;
int indexOfString;
int numOfRecursion;
int flagOfRecursion;
int main()
{
    printf("You can change the output of answer mod by type in 'mod='\n");

    while (1)
    {
        printf("please type in\n");
        changedString = getInArray();
        if (changedString == NULL) {
            printf("please type in\n");
            continue;
        }
        double theAnswer = reverse(changedString);
        printAns(theAnswer);
        indexOfString = 0;
        numOfRecursion = 0;
        flagOfRecursion = 0;
        printf("\n<<<<<====-------------------------====>>>>>\n");
        //printf("whxNB ljrNB wzNB\n");
    }
    return 0;
}
//(-2)*3+(-4)*5+(-1)*7*9=