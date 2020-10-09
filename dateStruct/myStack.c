#include"myStack.h"
#define NUMofFUN 6
#include<string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

//extern char opr[LenOpr];
//extern char bra[LenBra];
//extern char func[LenFunc][LenFunc2];
int  findNumLen(const char*);
char findFunc(const char*);
struct data myAtof(const char*,int *len);

int main() {
	char str[100];
	scanf("%s", str);
	for (int i = 0; i < 100;) {
		if (*(str + i) == '\0'||*(str+1)=='\n')break;
		struct data now;
		int number = 0;
		now=myAtof(str+i,&number);
		if (!number) {
			printf("invalid!\n");  i++;
		}
		else if (now.flag !=Num){ printf("Get a char %c %d\n", now.ch,number); i += number; }
		else if (now.flag == Num){printf("Get a double %lf %d\n", now.num,number); i += number; }
		
	}
}

char findFunc(const char* str) {
	for (int i = 0; i < NUMofFUN; i++) {
		if(!strncmp(str,func[i],strlen(func[i])))return 'A'+i;
	}
	return 0;
}

int findNumLen(const char* str) {

	int eFlag = 0;//标志科学计数法e是否已经出现过
	int i=0;//number长度
	int pointFlag = 0;//标志小数点是否已经出现过
	for (i = 0;str[i]!='\0';i++) {
		
		if (!isdigit(str[i])) {
			if ((0 == i && '-' == str[i]&&'+'==str[i]) && (isdigit(str[i + 1]) || str[i] == '.')) {
				continue;
			}
			else if (!pointFlag && str[i] == '.'&&isdigit(str[i])) {
				pointFlag = 1; continue;
			}
			else if (!eFlag && (str[i] == 'e' || str[i] == 'E')) {
				eFlag = 1;
				if ((str[i + 1] == '-' || str[i + 1] == '+') && isdigit(str[i + 2])) { i++; continue; }
				else if (isdigit(str[i + 1]))continue;
			}
			else break;
		}
	
	}
	return i ;
}

struct data myAtof(const char* str, int* len) {
	int over = 0;
	*len = 0;
	struct data aData;
	aData.flag = Not;

	while (*str == ' '||*str=='\n') { str++; (*len)++; }
	if (*str == '\0')over = 1;

	for (int i = 0; i < sizeof(bra);i++) {
		if (bra[i] == *str) { 
			aData.flag = Bra; 
			aData.ch = *str; 
			(*len) += 1; over = 1;
		}
	}	
	if(!over)
	for (int i = 0; i < sizeof(opr); i++) {
		if (opr[i] == *str) {
			aData.flag = Ope;
			aData.ch = *str;
			(*len) += 1; over = 1;
		}
	}
	
	if ((!over)&&(aData.ch = findFunc(str))) { 
		aData.flag = Fun;
		(*len) += strlen(func[aData.ch - 'A']); 
		over = 1; //printf("%d!char--\n", over);
	}
	else if (!over && 1) {
		
		(*len) += findNumLen(str); 
		aData.num = atof(str);
		aData.flag =Num;
		over = 1; //printf("%d@double--\n", over);
	}


	printf("%d--%d\n", over,*len);
	return aData;

}

