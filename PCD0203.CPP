#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
	char symbol;
	struct node *left;
	struct node *right;
};
typedef struct node node;
struct stack
{
	char op;
	node *op_pointer;
};
typedef struct stack stack;
int TOS=-1;
stack s[10];
/* This is the operator precedence table stored as it is in the
form of matrix and operators are assigned values as follows:
NULL = 0, Equal (=) = 1, less than (<) = 2, greater than (>) = 3. */
//			   +,*,(,),<>,-,/,^
int m[8][8]={ {3,2,2,3,3,3,2,2},        //+
	      {3,3,2,3,3,3,2,2},        //*
	      {2,2,2,1,0,2,2,2},        //(
	      {3,3,0,3,3,3,3,3},        //)
	      {2,2,2,0,1,2,2,2},        //><
	      {3,2,2,3,3,3,2,2},        //-
	      {3,3,3,3,3,3,3,2},        ///
	      {3,3,3,3,3,3,3,2}};       //^

void main(){
	clrscr();
	int comp(char);
	void push(char);
	void pop();
	void display(node *);
	node *temp;

	char* str;
	int i=0;
	cout<<"Enter the string : ";
	cin>>str;
	push('<');
	i++;
	while(str[i]!='\0'){
		if((str[i]>='a'&&str[i]<='z')){
			temp = new node;
			temp->symbol=str[i];
			temp->left=NULL;
			temp->right=NULL;
			s[TOS].op_pointer = temp;
		}
		else{
			int p_index,q_index;
			p_index = comp(s[TOS].op);
			q_index = comp(str[i]);
			while(m[p_index][q_index]==3){
				temp = new node;
				temp->symbol=s[TOS].op;
				temp->left=s[TOS-1].op_pointer;
				temp->right=s[TOS].op_pointer;
				pop();
				s[TOS].op_pointer=temp;
				p_index = comp(s[TOS].op);
				q_index = comp(str[i]);
			}
			if(m[p_index][q_index]==2){
				push(str[i]);
			}
			if(m[p_index][q_index]==1){
				if(comp(s[TOS].op)==4)
					break;
				if(comp(s[TOS].op)==2){
					temp=s[TOS].op_pointer;
					pop();
					s[TOS].op_pointer=temp;
				}
			}
			if(m[p_index][q_index]==0){
				cout << "Invalid string.";
				getch();
				exit(1);
			}
		}
		i++;
	}
	display(s[TOS].op_pointer);
	getch();
}
// function to get the index of the operator that comes in the TOS
// and also for the current operator that come in the string.
int comp(char x){
	int y;
	switch(x){
		case '+': y=0;
			  break;
		case '*': y=1;
			  break;
		case '(': y=2;
			  break;
		case ')': y=3;
			  break;
		case '>':
		case '<': y=4;
			  break;
		case '-': y=5;
			  break;
		case '/': y=6;
			  break;
		case '^': y=7;
		break;
	}
	return y;
}

void push(char x){
	TOS++;
	s[TOS].op=x;
}

void pop(){
	TOS--;
}

void display(node *s){
	if(s==NULL)
		return;
	if(s->left!=NULL)
		display(s->left);
	if(s->right!=NULL)
		display(s->right);
	cout << s->symbol;
}



