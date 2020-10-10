#include"myStack.h"
#include"myAtof.h"
#include"reverse.h"
char opr[LenOpr] = {'+', '-', '*', '/', '^'};
char bra[LenBra] = {'(', ')', '[', ']', '{', '}'};
char func[LenFunc][LenUnit] = {"sin", "ln", "tan", "cos", "log", "!"};
char cstn[LenCstn][LenUnit] = {"pi", "e"};
double cstnDouble[LenCstn] = {M_PI, M_E};


int main()
{
    nodeOfStack * A = getInArray();
    double answer = reverse(A);
    printf("%lf",&answer);
    return 0;
}