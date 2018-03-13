#include<stdio.h>
#include<conio.h>
#include<string.h>

char* input;
int current=0;
void F();
void E();
void match(char ch){
	if(input[current] == ch){
		current++;
		printf("%c matched\n", ch);
	}
	else{
		printf("Error\n");
	}

}

void E(){

	if(input[current] == 'i'){
		match('i');
		F();
	}

}
void F(){

	if(input[current] == '+'){
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