#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

void main(){

	char str[100], character;
	int i=0, digit=0, vowel=0, symbols=0, ascii;
	clrscr();
	printf("Enter the string : ");
	gets(str);
	for(i=0; i<strlen(str);i++){
		character = tolower(str[i]);
		if (character == 'a' || character == 'e' ||
			character == 'i' || character == 'o' || character == 'u')
			vowel++;
		else if(isdigit(character))
			digit++;
		else if(!(isalnum(character)) && character != ' ')
			symbols++;

	}
	printf("There are %d digits, %d vowels and %d symbols", digit, vowel, symbols);
	getch();

}