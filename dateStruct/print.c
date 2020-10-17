#define _CRT_SECURE_NO_WARNINGS
#include "print.h"
#include <string.h>
#include<stdio.h>
#include <ctype.h>
static  char printLen='6';
static int modFlag = 0;

char end[MaxOfFlag][MaxOfPrint] = { "lf\n" ,"e\n" };

void SetPrintMod();
void SetPrintLen();
void printIntroduction();
void printAns(double answer) {
	 char toBePrint [MaxOfPrint]= "The Answer Is %.";
	 char pLen[MaxOfPrint] = { printLen };
	strncat(toBePrint, pLen, MaxOfPrint);
	strncat(toBePrint, end[modFlag], MaxOfPrint);
	printf(toBePrint, answer);
}
void printIntroduction() {
	printf("输入：\n l :调整小数位数\n m :调整输出模式\n");
	return;
};
void SetPrintLen() {
	printf("仅支持输入0到9的数字\n");
	char  len = getchar();
	while (len == ' ' || len == '\n')len = getchar();
	if (!isdigit(len)) {
		printf("Wrong Len !!\n");
		return;
	}
	else printLen = len;
}

void printMod() {
	printIntroduction();
	char  tmp = getchar();
	while (tmp == ' ' || tmp == '\n')tmp = getchar();
	switch (tmp) {
	case 'l':SetPrintLen(); break;
	case 'm':SetPrintMod(); break;
	default:printf("Wrong Input !!\n"); return;
	}
	printf("再次修改请再次键入 mod= 指令\n");
	return;
}

void SetPrintMod() {
	printf("e :输出改为科学计数\n f :输出改为小数模式\n");
	char mod = getchar();
	while (mod == ' ' || mod == '\n')mod = getchar();
	switch (mod) {
	case 'e':modFlag = 1; break;
	case'f':modFlag = 0; break;
	default: printf("Wrong Mod !!\n"); break;
	}
	return;
};