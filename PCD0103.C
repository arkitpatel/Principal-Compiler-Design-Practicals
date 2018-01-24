#include<stdio.h>
#include<conio.h>
#include<string.h>

void main(){
	char* email = "abc@xyz.com";
	char* password = "Qwerty";
	char* user_email;
	char* user_password;
	int i=0, flag_email = 0, flag_password = 0;
	clrscr();
	printf("Enter your email : ");
	gets(user_email);
	printf("Enter your password : ");
	gets(user_password);
	for(i=0;i<strlen(user_email);i++){
		if(user_email[i] == email[i]){
			flag_email++;
		}
	}
	for(i=0;i<strlen(user_password);i++){
		if(user_password[i] == password[i]){
			flag_password++;
		}
	}
	if(flag_email == strlen(user_email)){
		if(flag_password == strlen(user_password)){
			printf("User Authenticated");
		}
		else{
			printf("Password is wrong");
		}
	}
	else if(flag_password == strlen(user_password)){
		printf("Wrong email");
	}
	else{
		printf("Email and Password both are wrong");
	}




	getch();
}