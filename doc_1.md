



**The Logic**
1. Scan the expression from left to right.

2. If you see an opening bracket ((, [, or {), push it onto the stack.

3. If you see a closing bracket (), ], or }):

i.  If the stack is empty, it means we have a closing bracket without an opening one (Unbalanced).

ii. If the stack isn't empty, pop the top element. If the popped element doesn't match the type of the closing bracket (e.g., we see ] but popped (), it's unbalanced.

4. At the end, if the stack is empty, the expression is balanced. If something is left in the stack, an opening bracket was never closed.

