#include<stdio.h>
#include<conio.h>
#include<ctype.h>

#define MAX 200
// stack
char stack[MAX];
int top = -1;

void push(char item){
    if(top >= MAX - 1)
    return;
    stack[++top] = item;
}
char pop(){
    if(top == -1){
        return -1;
    }
    return stack[top--];
}
char peek(){
    if(top == -1)
    return -1;
    return stack[top];
}

// function for operator precedence
int precedence(char symbol){
    switch(symbol){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char item, x;
    for(i=0; infix[i] != '\0'; i++){
        item = infix[i];

        //if the item is operand, add to output
        if(isalnum(item)){
            postfix[j++] = item;
        }
        //if '(' , push to stack
        else if(item == '('){
            push(item);
        }
        else if(item == ')'){
            while ((x = pop()) != '('){
                postfix[j++] = x;
            }
        }
        // in case of operator
        else{
            while (top != -1 && precedence(peek()) >= precedence(item)){
                postfix[j++] = pop();
            }
            push(item);
        }
    }
    // pop remaining operators from stack
    while(top != -1){
        postfix[j++] =  pop();
    }
    postfix[j] = '\0';
}

int main()
{
    printf("program is working");
    char infix[MAX] = "a+b*(c^d-e)";
    char postfix[200];
    infixToPostfix(infix, postfix);

    printf("infix: %s\n", infix);
    printf("postfix:  %s\n", postfix);
    fflush(stdout);
    return 0;
}