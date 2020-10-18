#define _CRT_SECURE_NO_WARNINGS
#include "print.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
static char printLen = '6';
static int modFlag = 0;

char end[MaxOfFlag][MaxOfPrint] = {"lf\n", "e\n"};

void SetPrintMod();
void SetPrintLen();
void printIntroduction();
void printAns(double answer)
{
    char toBePrint[MaxOfPrint] = "The Answer Is %.";
    char pLen[MaxOfPrint] = {printLen};
    strncat(toBePrint, pLen, MaxOfPrint);
    strncat(toBePrint, end[modFlag], MaxOfPrint);
    printf(toBePrint, answer);
}
void printIntroduction()
{
    printf("To type in: \n l :Adjust the number of decimal places.\n m :Adjust output mode\n");
    return;
};
void SetPrintLen()
{
    printf("Only supports entering numbers from 0 to 9\n");
    char len = getchar();
    while (len == ' ' || len == '\n')
        len = getchar();
    if (!isdigit(len))
    {
        printf("Wrong Len !!\n");
        return;
    }
    else
        printLen = len;
}

void printMod()
{
    printIntroduction();
    char tmp = getchar();
    while (tmp == ' ' || tmp == '\n')
        tmp = getchar();
    switch (tmp)
    {
    case 'l':
        SetPrintLen();
        break;
    case 'm':
        SetPrintMod();
        break;
    default:
        printf("Wrong Input !!\n");
        return;
    }
    printf("To modify again, please type mod= command again\n");
    return;
}

void SetPrintMod()
{
    printf("e: change the output to scientific notation\nf: change the output to decimal mode\n");
    char mod = getchar();
    while (mod == ' ' || mod == '\n')
        mod = getchar();
    switch (mod)
    {
    case 'e':
        modFlag = 1;
        break;
    case 'f':
        modFlag = 0;
        break;
    default:
        printf("Wrong Mod !!\n");
        break;
    }
    return;
};