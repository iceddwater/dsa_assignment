#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top < MAX - 1) {
        stack[++top] = item;
    }
}
char pop() {
    if (top == -1) {
        return '\0'; // Stack underflow
    }
    return stack[top--];
}
bool isMatchingPair(char left, char right) 
{
    if (left == '(' && right == ')') return true;
    if (left == '{' && right == '}') return true;
    if (left == '[' && right == ']') return true;
    return false;
}
bool areParenthesesBalanced(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        // push opening brackets
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } 
        // check closing brackets
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) {
                return false; //  closing bracket with no opening
            }

else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
    if (top == -1) return false; 
    
    char lastOpened = pop(); 
    if (!isMatchingPair(lastOpened, exp[i])) {
        return false; 
    }
}
          //  char popped = pop();
            if (!isMatchingPair(pop(), exp[i])) {
                return false; // Mismatched ']'
            }
        }
    }
    return top == -1; // if top=-1, everything matched
}
int main() {
    char expression[MAX];
    printf("Enter an expression: ");

    if(fgets(expression, MAX, stdin)){
    expression[strcspn(expression, "\n")] = '\0'; // Remove newline character

    if (areParenthesesBalanced(expression)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }
}
    return 0;
}