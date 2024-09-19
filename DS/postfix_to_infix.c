#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20

struct exp{
    char arr[max];
};

void ifNotOperand(struct exp cap[], char a[], int *top){
    char temp[30];
    strcpy(temp,"(");
    strcat(temp,cap[(*top)-1].arr);
    strcat(temp,a);
    strcat(temp,cap[*top].arr);
    strcat(temp,")");
    *top = *top-2;
    strcpy(cap[++(*top)].arr,temp);

}

int isOperand(char a){
    if ((a >= 'A' && a <='Z') || (a >= 'a' && a <='z')){
        return 1;
    }
    else
        return 0;
}


int main()
{
    char postfix[max];
    printf ("Enter an postfix expression : ");
    scanf("%s",postfix);
    struct exp *stack = malloc(max*sizeof(struct exp));             // making space for 20 structues. idk why i used malloc tho lol
    int stack_top = -1;
    for (int i = 0; postfix[i]!='\0';i++){                          // traversing till the string ends i.e \0
        char temp_string[] = {postfix[i] , '\0'};                   // making the char into a string
        if (isOperand(postfix[i])){
            strcpy(stack[++stack_top].arr,temp_string);             // just adding the operand in our stack of structures
        }
        else{
            ifNotOperand(stack,temp_string,&stack_top);             // This fucntion basically con-catenates three things
        }                                                           // i.e second highest element + operator + highest element
    }                                                               // and saves it in stack where second highest element used to be. 
    

    printf("The postfix expression is : %s\n",postfix);
    printf("The infix expression is : %s\n",stack[0].arr);          // only printing stack[0] because sab hone ke baad poora expression wahi rahega.
                                                                    //Good work soham Bhai _/\_
    return 0;
}