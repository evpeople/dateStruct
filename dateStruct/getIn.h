#ifndef GETIN
#define GETIN

#include<string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define NUMofFUN 5
#define NUMofCstn 2
#define NUMofOpe 5
#define NUMofBra 6
#define NUMofMax 26
#define NUMofMod 1

#define MaxInput 2000

#define M_E        2.71828182845904523536   // e
#define M_PI       3.14159265358979323846   // pi
#define LenOpr 5
#define LenBra 6
#define LenFunc 26
#define LenUnit 6
#define LenCstn 26
#define LenMod 5
extern char mod[LenMod][LenUnit];
extern char opr[LenOpr];
extern char bra[LenBra];
extern char func[LenFunc][LenUnit];
extern char cstn[LenCstn][LenUnit];
extern double cstnDouble[LenCstn];
#endif // !GETIN
