#include "getIn.h"
#include "myStack.h"
#include "reverse.h"

#include "print.h"

nodeOfStack *changedString;
int indexOfString;
int numOfRecursion;
int flagOfRecursion;
int main()
{

    startlevel();
    int i = 1;
    while (i)
    {
        printf("\n||>>>> The %3d time caculation :\n", i);
        printf("||>>You can quit or change the output of answer mod by type in 'mod='\n");
        printf("||>>please type in your instruction or expression:\n");
        changedString = getInArray();
        fflush(stdin);
        if (changedString == NULL)
        {
            continue;
        }
        else if (changedString[0].flag == Not)
            break;

        double theAnswer = reverse(changedString);
        printAns(theAnswer);
        indexOfString = 0;
        numOfRecursion = 0;
        flagOfRecursion = 0;
        i++;
    }
    return 0;
}
