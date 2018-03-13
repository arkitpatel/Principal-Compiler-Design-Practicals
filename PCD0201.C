/*
Building Recursively Decent Parser on the following grammar

E -> iF
F -> +iE / null

*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

char* input;
int current=0;
int flag=0;
void F();
void E();
void match(char ch){
	if(input[current] == ch){
		current++;
		printf("%c matched\n", ch);
	}
	else{
		flag=1;
		printf("Error\n");
	}

}

void E(){

	if(input[current] == 'i' && flag==0){
		match('i');
		F();
	}

}
void F(){

	if(input[current] == '+' && flag==0){
		match('+');
		match('i');
		F();
	}

}

void main(){
	clrscr();
	printf("Enter the string to check for grammar\nE -> iF\nF -> +iE/null\n");
	gets(input);
	E();
	if(input[current] == '\0'){
		printf("Parsing done");
	}
	getch();
}
