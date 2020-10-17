#ifndef GETIN
#define GETIN

#include<string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define NUMofFUN 6
#define NUMofCstn 2
#define NUMofOpe 5
#define NUMofBra 6
#define NUMofMax 26
#define NUMofFUN 6//如果添加1个函数此数需要加1

#define MaxInput 2000

#define M_E        2.71828182845904523536   // e
#define M_PI       3.14159265358979323846   // pi
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

extern int findNumLen(const char *);//配合atof函数使用，前者使用的字符数目为它的返回值（对科学计数法适用*）
extern char findChar(const char*,enum flager *);//根据读入字符返回int（枚举）类型，用以分辨操作符、括号、常数或函数并返回相应字符
extern struct data myAtof(const char *, int *);//根据字符串读入元素（操作符、操作数、括号或函数）
extern int TestInput();//用于测试输入函数是否正确（已停用）
extern nodeOfStack *changedString;
#endif // !GETIN

