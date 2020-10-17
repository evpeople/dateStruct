#include"myStack.h"
#include"getIn.h"
#include"print.h"

char opr[LenOpr] = { '+','-','*','/','^' };//操作符//自行扩展请按照优先级后大前小的方式排列，并定义在mathOfOpr即可，并且getIn.h中宏NumOf需要加1
char bra[LenBra] = { '(',')','[',']','{','}' };//括号//保证前括号下标%2为0，后括号为1
char func[LenFunc][LenUnit] = { "sin","ln","tan","cos" ,"log" };//函数//可自行扩展，定义在mathOfFun即可，并且getIn.h中宏NumOfFunc2需要加1
char cstn[LenCstn][LenUnit] = { "pi","e" ,};//常数或模式//增加需要在cstnDouble[LenCstn]中定义，并且getin.hz中宏LenCstn需要加1
char  mod[LenMod][LenUnit] = { "mod" };
double cstnDouble[LenCstn] = {M_PI,M_E };//如果增加1个常数需要在此添加一个定义

// int  findNumLen(const char*);
// char findChar(const char*,enum flager *flag);
// struct data myAtof(const char*,int *len);
// int TestInput();
//
//int main() {
//	TestInput();
//	return 0;
//}

int TestInput() {
struct data* array=getInArray();
if (array == NULL)printf("wrong\n");
else for (int i=0;;i++) {
	if (array[i].flag == Not) { printf("wrong\n"); break; }
	if (array[i].flag != Num) {
		printf("%c	 ", array[i].ch);
	}
	if (array[i].flag == Num)printf("%lf		", array[i].num);
	if (array[i].flag == Eql) {
		printf("out by Eql."); break;
	}
	}
return 0;
}

char findChar(const char* str,enum flager *flag) {
	*flag = Not;
	for (int i = 0; i < NUMofMax; i++) {
		if (i < NUMofFUN && !strncmp(str, func[i], strlen(func[i]))) {
			*flag = Fun; return 'A' + i;//函数
		}
		else if (i<NUMofOpe&&*(str)==opr[i]) {
			*flag = Ope; return opr[i];//操作符
		}
		else if (i<NUMofBra&& *(str) == bra[i]) {
			*flag = Bra; return bra[i%2];//括号
		}
		else if (i<NUMofCstn&&!strncmp(str, cstn[i], strlen(cstn[i]))) {
			*flag = Cstn; return 'a' + i;//常数
		}
		else if (i < NUMofMod && !strncmp(str, mod[i], strlen(mod[i]))) {
			*flag = Mod; return i;
		}
	}
	return 0;
}

int findNumLen(const char* str) {

	int eFlag = 0;//标志科学计数法e是否已经出现过
	int i=0;//number长度
	int pointFlag = 0;//标志小数点是否已经出现过
	for (i = 0;str[i]!='\0';i++) {
		
		if (!isdigit(str[i])) {
			if ((0 == i && '-' == str[i]&&'+'==str[i]) && (isdigit(str[i + 1]) || str[i] == '.')) {
				if (str[i] == '.')pointFlag = 1;
				continue;
			}
			else if (!pointFlag && str[i] == '.'&&isdigit(str[i+1])) {
				pointFlag = 1; continue;
			}
			else if (!eFlag && (str[i] == 'e' || str[i] == 'E')) {
				eFlag = 1;
				if ((str[i + 1] == '-' || str[i + 1] == '+') && isdigit(str[i + 2])) { i++; continue; }
				else if (isdigit(str[i + 1]))continue;
			}
			else break;
		}
	
	}
	return i ;
}

struct data myAtof(const char* str, int* len) {
	int over = 0;//用以判断函数能否结束的标志
	*len = 0;//存储占用字符数
	struct data aData;//当前节点
	aData.flag = Not;

	while (*str == ' '||*str=='\n'||*str=='\t') { str++; (*len)++; }//跳过无效元素
	if (*str == '\0')over = 1;

	if (*str == '=') {//将当前元素设为等号
		aData.flag = Eql;
		aData.ch = '=';
		(*len)++;
		over = 1;
	}
<<<<<<< HEAD
char x = 0;
	if (!over&&((x=findChar(str,&aData.flag))||aData.flag!=Not) ){
=======
	char x = 0;
	if (!over&&(x=findChar(str,&aData.flag)) ){//若为字符类型，将当前元素设为字符
>>>>>>> 1e05e5e8963511c69e42780f331ab94f4c415332
		switch(aData.flag){
		case Bra: aData.ch = x; (*len) += 1;break;
		case Ope: aData.ch = x; (*len) += 1; break;
		case Cstn:x = x - 'a'; aData.num = cstnDouble[x]; aData.flag = Num; (*len) += strlen(cstn[x]); break;
		case Fun: aData.ch = x; aData.flag = Fun;  (*len) += strlen(func[x - 'A']); break;
		case Mod:aData.flag = Mod; (*len) += strlen(mod[x]); break;
		default: printf("Find a wrong char '%c' !\n", x); aData.flag = Not; break;
		}
		over=1;
	}

	if (!over && findNumLen(str)) {//若为数字类型，将当前元素设为数字
		
		(*len) += findNumLen(str); 
		aData.num = atof(str);
		aData.flag =Num;
		over = 1; //printf("%d@double--\n", over);
	}

	//printf("%d--%d\n", over,*len);
	return aData;

}

struct data* getInArray() {//主要读取数据函数（为以上函数的集中整合）
	struct data* Array = (struct data*)malloc(LENOFSTACK);//申请空间创建一个读取数据的数组
	Array[0] = makeNode(0, '(');//前括号作为首结点，便于后期递归
	int ArrayNum = 1;//数组Array长度
	char inputStr[MaxInput];//输入的字符串
	int j = 0;//读取用变量
	do {
		inputStr[j] = getchar(); 
		j++;
	} while (inputStr[j-1] != '=');//遇到'='读取结束

	for (int i = 0; i < MaxInput-1;) {
		
		if (*(inputStr + i) == '\0') { 
			printf("ERROR ! The Input is without a '=' .\n");
			Array = NULL;
			break; 
		}
		struct data now;//创建一个新节点代表当前元素
		int number = 0;//存储当前元素所占的字符数
		now = myAtof(inputStr + i, &number);//顺序读入字符串元素
		if (!number) {
			printf("Your input '%c' is invalid !\n", *(inputStr + i)); 
			i++;
			printf("Press 'y' to skip the '%c' and continue or the process will break.\n", *(inputStr + i));
			char temInput=getchar();
			while (temInput == ' ' || temInput == '\n')temInput=getchar();
			if (temInput != 'y') {
				Array = NULL;
				break;
			}

		}
		else if (now.flag != Num && now.flag != Not) {
			//printf("Get a char %c %d\n", now.ch, number);
			if (now.flag == Mod) {
				printMod();
				Array = NULL;
				break;
			}
			if (now.flag == Eql) {
				Array[ArrayNum] = makeNode(0, ')');
				ArrayNum++; 
			}
			Array[ArrayNum] = now;
			ArrayNum++;
			i += number;
			if (now.flag == Eql)break;
		}
		else if (now.flag == Num) {
			//printf("Get a double %lf %d\n", now.num, number);
			Array[ArrayNum] = now;
			ArrayNum++;
			i += number;
		}
		else Array = NULL;
	}
	
	return Array;
}