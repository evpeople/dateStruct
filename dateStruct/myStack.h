#define NUMofFUN 6
#define LENOFSTACK  sizeof(struct data) * 1000
char opr[5] = { '+','-','*','/' ,'^'};
char bra[6] = { '[',']','{','}','(',')' };
char func[26][6] = { "sin","cos","ln","tan","log","!"};
enum flager {
	Num= 0,Fun,Ope,Bra,Not
};
struct data {
	enum flager flag;//1--ch, 0--num,
	char ch;
	double num;
};

struct STACKER
{
    int i;         //用于判断是字符还是数字还是空栈
    int flagOfTop; //用于计算栈的个数
    struct data dataInStack[LENOFSTACK];
};


typedef struct STACKER *STACK;
int isEmpty(STACK);
void makeEmpty(STACK);
void push(STACK, struct data);
struct data top(STACK);
void pop(STACK);
struct data topAndPop(STACK);
STACK createStack(STACK);
struct data makeNode(double a, char b); //若为数字，则b默认为@
