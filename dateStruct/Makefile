main: allFunOnStack.o reverse.o myAtof.o 
	gcc allFunOnStack.o reverse.o myAtof.o main.o -o main -g
main.o:main.o
	gcc -c main.c -o main.o -g
allFunOnStack.o:allFunOnStack.c
	gcc -c allFunOnStack.c -o allFunOnStack.o -g
reverse.o:reverse.c
	gcc -c reverse.c -o reverse.o -g
myAtof.o:myAtof.c
	gcc -c myAtof.c -o myAtof.o -g
clean:
	rm *.o