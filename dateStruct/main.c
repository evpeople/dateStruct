#include "myAtof.h"
#include "myStack.h"
#include "reverse.h"
char opr[LenOpr] = {'+', '-', '*', '/', '^'};
char bra[LenBra] = {'(', ')', '[', ']', '{', '}'};
char func[LenFunc][LenUnit] = {"sin", "ln", "tan", "cos", "log", "!"};
char cstn[LenCstn][LenUnit] = {"pi", "e"};
double cstnDouble[LenCstn] = {M_PI, M_E};

int main()
{
    printf("wsdsaad");
    nodeOfStack *A = getInArray();
    printf("%c", A[1].ch);
    //system("pause");
    printf("wsdsaad");
    double answer = reverse(A);
    printf("%lf", &answer);
    printf("whxNB ljrNB wzNB");
    getchar();
    getchar();
    getchar();
    return 0;
}