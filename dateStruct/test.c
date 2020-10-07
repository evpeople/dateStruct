#include <stdio.h>
#include <stdlib.h>
#include <string.h>
union data
{
    int num;
    char operator;
};
int main()
{
    union data i;
    i.num = 65;
    if (i.operator>= 'A')
    {
        printf("whx is sb");
    }
    getchar();
}