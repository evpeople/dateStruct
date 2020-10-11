#include "myStack.h"
int isLower(nodeOfStack A, nodeOfStack B); //有问题，没写运算先后顺序的判断，
double mathOfOpr(double, double, char);
double mathOfFun(double, char);
void specialPush(STACK, nodeOfStack);
double reverse(nodeOfStack[],int);
void printNode(nodeOfStack);
void dealWithBra(nodeOfStack, STACK, STACK, int *);
void dealWithFun(nodeOfStack, STACK, STACK);