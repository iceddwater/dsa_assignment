This program consists of three components: 

1. **Stack** operation 
    Consists of push peek and pop functions
2. **Precedence** as the main function which determines the operator precedence 
 i. ^ : 3
 ii. *, / : 2
 iii. +, - : 1
3. **converter**: Manages shunting logic and iterates the loop over infix string

**Example**
Infix: a+b*(c^d-e)
Postfix: abcd^e-*+

This program follows Shunting-Yard Algorithm:

1. Operands (numbers/letters) are sent directly to the output.

2. Left Parentheses are pushed onto the operator stack.

3. Operators are pushed onto the stack after popping any existing operators with higher or equal precedence

4. Right Parentheses trigger a "flush" of the stack back to the output until a matching left parenthesis is found(program went on infinite loop without flush)

Limitation: Currently charater limited to **single** digit. 

Usage: **gcc prog_2.c -o prog_2**
Execution: **.\prog_2** 
