#include "myStack.h"
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
union datas
{
    int num;
    char ch;
};
int main()
{
    STACK sbwhx = createStack(sbwhx);
    for(int i=0;i<100;i++){
    struct data wofule = makeNode(1+(double)i, '@');
    push(sbwhx, wofule);
		}
    
    printStack(sbwhx); 

    union datas i;
    i.num = 65;
    if (i.ch>= 'A')
    {
        printf("whx is sb");
    }
    getchar();
}
