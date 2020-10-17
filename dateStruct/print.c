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
	printf("���룺\n l :����С��λ��\n m :�������ģʽ\n");
	return;
};
void SetPrintLen() {
	printf("��֧������0��9������\n");
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
	printf("�ٴ��޸����ٴμ��� mod= ָ��\n");
	return;
}

void SetPrintMod() {
	printf("e :�����Ϊ��ѧ����\n f :�����ΪС��ģʽ\n");
	char mod = getchar();
	while (mod == ' ' || mod == '\n')mod = getchar();
	switch (mod) {
	case 'e':modFlag = 1; break;
	case'f':modFlag = 0; break;
	default: printf("Wrong Mod !!\n"); break;
	}
	return;
};