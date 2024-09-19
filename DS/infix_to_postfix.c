#include <stdio.h>
#define max 100

int getPrecedence (char a){
	switch (a){
		case '+' :
		case '-' :
			return 1;
			break;
		case '*' :
		case '/' :
			return 2;
			break;
		case '^' :
			return 3;
			break;
		case '(' :
			return 4;
			break;
		case ')' :
			return -1;
			break;
		default :
			return 0;
		
		
	}
}

char pop(char arr[], int* top){
	if ((*top) == -1){
		printf ("Underflow");
		return 'x';
	}
	return arr[(*top)--];
}

void push (char arr[], int* top, char a){
	arr[++(*top)] = a;
}


int main(){
	char infix[max];
	printf ("Enter an infix expression : ");
	scanf ("%s",infix);
	char stack[max];
	int stack_top = -1;
	char postfix[max];
	int post_top = -1;
	for (int i = 0; infix[i] != '\0' ;i++){
		switch (getPrecedence(infix[i])){
			case 4 :
				push(stack, &stack_top, infix[i]);
				break;
			case -1 :
				while (stack[stack_top] != '('){
					push (postfix,&post_top,pop(stack,&stack_top));
				}
				pop (stack,&stack_top);
				break;
			case 0 :
				push(postfix, &post_top, infix[i]);
				break;
			default :
				while ( stack_top != -1 && getPrecedence(infix[i]) <= getPrecedence (stack[stack_top] && stack[stack_top]!= '(')){
					push (postfix,&post_top,pop (stack,&stack_top));
				}
				push(stack, &stack_top, infix[i]);
				break;
								
		}
		
	}
	while ( stack_top != -1 ){
		push (postfix,&post_top,pop (stack,&stack_top));
	}
	postfix[++post_top] = '\0';
	printf ("The infix expression is : %s\n",infix );
	printf ("The postfix expression is : %s",postfix );
			
}