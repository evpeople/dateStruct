#include "myStack.h"
int isLower(nodeOfStack A, nodeOfStack B); //判断运算符优先级
double mathOfOpr(double, double, char);//实现二元运算符运算
double mathOfFun(double, char);//实现函数运算
void specialPush(STACK, nodeOfStack);//判断操作符为一元或二元（后者为存储操作符的栈）
double reverse(nodeOfStack[]);//主要计算函数
void dealWithBra(nodeOfStack, STACK, STACK, int *);//处理括号（前括号入栈，后括号弹出数据）
void dealWithFun(nodeOfStack, STACK, STACK);//处理所有运算符（遇到二元弹出给mathOfFun处理）