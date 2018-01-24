#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

void main(){
	   char* input;
	   int i = 0;
	   clrscr();
	   printf("Enter : ");
	   gets(input);
	   if(isalpha(input[0])){
		for(i=1;i<strlen(input);i++){

			if(input[i] == '_'){
				continue;
			}
			else if(isalnum(input[i])){
				continue;
			}
			else{
				break;
			}
		}
		if(i == strlen(input)){
			printf("Valid Identifier");
		}
		else{
			printf("Identifier has invalid characters");
		}
	   }
	   else{
		printf("Identifier needs to start with alphabet");
	   }
	   getch();
}