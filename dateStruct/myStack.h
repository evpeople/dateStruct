#define _CRT_SECURE_NO_WARNINGS
#ifndef BASE
#define BASE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENOFSTACK sizeof(struct data) * 2000

enum flager
{
	Num = 0,
	Fun,
	Ope,
	Bra,
	Cstn,
	Eql,
	Not
};
struct data
{
	enum flager flag; //1--ch, 0--num,
	char ch;
	double num;
};

struct STACKER
{
	int i;		   //用于判断是字符还是数字还是空栈
	int flagOfTop; //用于计算栈的个数
	struct data dataInStack[LENOFSTACK];
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