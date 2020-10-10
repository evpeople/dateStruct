#include"myStack.h"
#include"getIn.h"
#include"reverse.h"

int main()
{
    nodeOfStack * A = getInArray();
    double answer = reverse(A);
    printf("%lf",&answer);
    return 0;
}