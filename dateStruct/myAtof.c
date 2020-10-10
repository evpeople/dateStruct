#include "myAtof.h"
#include "myStack.h"

// int main() {
// 	TestInput();
// 	return 0;
// }
int TestInput()
{
	struct data *array = getInArray();
	if (array == NULL)
		printf("wrong\n");
	else
		for (int i = 0;; i++)
		{
			if (array[i].flag == Not)
			{
				printf("shit\n");
				break;
			}
			if (array[i].flag != Num)
			{
				printf("%c	 ", array[i].ch, array[i].flag);
			}
			if (array[i].flag == Num)
				printf("%lf		", array[i].num);
			if (array[i].flag == Eql)
			{
				printf("out by Eql.");
				break;
			}
		}
}

char findChar(const char *str, int *flag)
{
	for (int i = 0; i < NUMofMax; i++)
	{
		if (i < NUMofFUN && !strncmp(str, func[i], strlen(func[i])))
		{
			*flag = Fun;
			return 'A' + i;
		}
		else if (i < NUMofOpe && *(str) == opr[i])
		{
			*flag = Ope;
			return opr[i];
		}
		else if (i < NUMofBra && *(str) == bra[i])
		{
			*flag = Bra;
			return bra[i % 2];
		}
		else if (i < NUMofCstn && !strncmp(str, cstn[i], strlen(cstn[i])))
		{
			*flag = Cstn;
			return 'a' + i;
		}
	}
	return 0;
}

int findNumLen(const char *str)
{

	int eFlag = 0;	   //标志科学计数法e是否已经出现过
	int i = 0;		   //number长度
	int pointFlag = 0; //标志小数点是否已经出现过
	for (i = 0; str[i] != '\0'; i++)
	{

		if (!isdigit(str[i]))
		{
			if ((0 == i && '-' == str[i] && '+' == str[i]) && (isdigit(str[i + 1]) || str[i] == '.'))
			{
				if (str[i] == '.')
					pointFlag = 1;
				continue;
			}
			else if (!pointFlag && str[i] == '.' && isdigit(str[i + 1]))
			{
				pointFlag = 1;
				continue;
			}
			else if (!eFlag && (str[i] == 'e' || str[i] == 'E'))
			{
				eFlag = 1;
				if ((str[i + 1] == '-' || str[i + 1] == '+') && isdigit(str[i + 2]))
				{
					i++;
					continue;
				}
				else if (isdigit(str[i + 1]))
					continue;
			}
			else
				break;
		}
	}
	return i;
}

struct data myAtof(const char *str, int *len)
{
	int over = 0;
	*len = 0;
	struct data aData;
	aData.flag = Not;

	while (*str == ' ' || *str == '\n' || *str == '\t')
	{
		str++;
		(*len)++;
	}
	if (*str == '\0')
		over = 1;

	if (*str == '=')
	{
		aData.flag = Eql;
		aData.ch = '=';
		(*len)++;
		over = 1;
	}
	char x = 0;
	if (!over && (x = findChar(str, &aData.flag)))
	{
		switch (aData.flag)
		{
		case Bra:
			aData.ch = x;
			(*len) += 1;
			break;
		case Ope:
			aData.ch = x;
			(*len) += 1;
			break;
		case Cstn:
			x = x - 'a';
			aData.num = cstnDouble[x];
			aData.flag = Num;
			(*len) += strlen(cstn[x]);
			break;
		case Fun:
			aData.ch = x;
			aData.flag = Fun;
			(*len) += strlen(func[x - 'A']);
			break;
		}
		over = 1;
	}

	if (!over && findNumLen(str))
	{

		(*len) += findNumLen(str);
		aData.num = atof(str);
		aData.flag = Num;
		over = 1; //printf("%d@double--\n", over);
	}

	//printf("%d--%d\n", over,*len);
	return aData;
}

struct data *getInArray()
{
	struct data *Array = (struct data *)malloc(LENOFSTACK);
	Array[0] = makeNode(0, '(');
	int ArrayNum = 1;
	char inputStr[MaxInput];
	int j = 0;
	do
	{
		inputStr[j] = getchar();
		j++;
	} while (inputStr[j - 1] != '=');

	for (int i = 0; i < MaxInput - 1;)
	{

		if (*(inputStr + i) == '\0')
		{
			printf("ERROR ! The Input is without a '=' .\n");
			Array = NULL;
			break;
		}
		struct data now;
		int number = 0;
		now = myAtof(inputStr + i, &number);
		if (!number)
		{
			printf("Your input '%c' is invalid !\n", *(inputStr + i));
			i++;
			printf("Press 'y' to continue or the process will break.\n");
			getchar();
			if (getchar() != 'y')
			{
				Array = NULL;
				break;
			}
		}
		else if (now.flag != Num && now.flag != Not)
		{
			//printf("Get a char %c %d\n", now.ch, number);
			if (now.flag == Eql)
			{
				Array[ArrayNum] = makeNode(0, ')');
				ArrayNum++;
			}
			Array[ArrayNum] = now;
			ArrayNum++;
			i += number;
			if (now.flag == Eql)
				break;
		}
		else if (now.flag == Num)
		{
			//printf("Get a double %lf %d\n", now.num, number);
			Array[ArrayNum] = now;
			ArrayNum++;
			i += number;
		}
		else
			Array = NULL;
	}
	if (Array != NULL)
	{
	}
	return Array;
}