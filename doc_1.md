



**The Logic**
1. Scan the expression from left to right.

2. If you see an opening bracket ((, [, or {), push it onto the stack.

3. If you see a closing bracket (), ], or }):

i.  If the stack is empty, it means we have a closing bracket without an opening one (Unbalanced).

ii. If the stack isn't empty, pop the top element. If the popped element doesn't match the type of the closing bracket (e.g., we see ] but popped (), it's unbalanced.

4. At the end, if the stack is empty, the expression is balanced. If something is left in the stack, an opening bracket was never closed.

   Program Workflow:
   
1. The program allocates char[100] and fgets reads the imput.
  Also used strcspn to trim \n from end of the string.

2. areParenthesesBalanced() function used to start a loop to traverse every character of string one by one.
  i. when encountered an open bracket, pushes it to stack and saves for later.
  ii. when encountered a closing bracket, first, checks if stack is empty and says "Not Balanced",  if brackets match, pops the item from stack and compares it to closing     bracket using isMatchingPair.

3. If stack is empty at the end, the program returns True(Balanced).
Else, False(Not Balanced)

Output: 
Enter an expression: (a+b)*(b
The parentheses are not balanced.


