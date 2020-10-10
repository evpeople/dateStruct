#include "myStack.h"
int isLower(nodeOfStack A, nodeOfStack B); //有问题，没写运算先后顺序的判断，
//这两个还没有实现，留给梁家瑞好了
double mathOfOpr(double, double, char);
double mathOfFun(double, char);
void specialPush(STACK, nodeOfStack);
double reverse(nodeOfStack[]);
void printNode(nodeOfStack temp);
void dealWithBra(nodeOfStack, STACK, STACK, int *);
void dealWithFun(nodeOfStack, STACK, STACK);