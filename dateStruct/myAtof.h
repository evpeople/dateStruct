#define NUMofFUN 6
#include <ctype.h>
#include <math.h>
#define M_PI 3.1415926
#define M_E 2.71828

int findNumLen(const char *);
char findChar(const char *, int *flag);
struct data myAtof(const char *str, int *len);
int TestInput();