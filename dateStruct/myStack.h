#define  _CRT_SECURE_NO_WARNINGS
#ifndef BASE 
#define BASE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMofFUN 6
#define NUMofCstn 2
#define NUMofOpe 5
#define NUMofBra 6
#define NUMofMax 26

#define MaxInput 2000
#define LENOFSTACK sizeof(struct data) * 2000
#define LenOpr 5
#define LenBra 6
#define LenFunc 26
#define LenFunc2 6
#define LenUnit 6
#define LenCstn 26
extern char opr[LenOpr];
extern char bra[LenBra];
extern char func[LenFunc][LenFunc2];
extern char cstn[LenCstn][LenUnit];
extern double cstnDouble[LenCstn];
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
struct data * getInArray();
#endif