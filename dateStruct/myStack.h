#define _CRT_SECURE_NO_WARNINGS
#ifndef BASE
#define BASE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENOFSTACK sizeof(struct data) * 2000

enum flager //枚举类型（增加可读性*）
{
    Num = 0,
    Fun,
    Ope,
    Bra,
    Cstn,
    Eql,
    Mod,
    Not
};
struct data
{
    enum flager flag; //1--ch, 0--num,
    char ch;          //存放字符（若flag为1）
    double num;       //存放数字（若flag为0）
};

struct STACKER
{
    int i;                               //用于判断是字符、数字或空栈
    int flagOfTop;                       //用于计算栈的个数
    struct data dataInStack[LENOFSTACK]; //存储用栈
};

typedef struct STACKER *STACK;
typedef struct data nodeOfStack;
int isEmpty(STACK);
void makeEmpty(STACK);
void push(STACK, struct data);
struct data top(STACK);
void pop(STACK);
struct data topAndPop(STACK);
STACK createStack();
struct data makeNode(double a, char b); //若为数字，则b默认为@
void printStack(STACK);
struct data *getInArray();
#endif