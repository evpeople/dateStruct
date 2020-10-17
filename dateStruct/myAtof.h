#define NUMofFUN 6
#include <ctype.h>
#include <math.h>
#define M_PI 3.1415926
#define M_E 2.71828

int findNumLen(const char *);//配合atof函数使用，前者使用的字符数目为它的返回值（对科学计数法适用*）
char findChar(const char *, int *);//根据读入字符返回int（枚举）类型，用以分辨操作符括号与函数并返回相应字符
struct data myAtof(const char *, int *);//根据字符串读入元素（操作符操作数括号和函数）的栈
int TestInput();//用于测试输入函数是否正确