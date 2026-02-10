Algorithm: Reverse Traversal (Recursive)

Base Case: If the current node (head) is NULL, return to the previous call.

Recursive Step: Call the traversal function recursively for the next node (head->next).

Action: Once the recursion starts unwinding (returning from the end of the list), print or process the data of the current node.

Why recursion?
Singly linked list only has next pointers so can't move backwards.
Since it can't be reverse traverse without reversing the list first, recursion is used to use the function stack to memeber the previous nodes.

program flow:
Created three nodes n1, n2, n3.
Used malloc to assign memory for the nodes.
Linked the list together; n1->n2->n3->null
then function is called to printbackwards and gives the very first node.
The function makes sure to check the number in line is not the last one before printing.

In the program, 
Node 10: Looks at its next pointer. It sees Node 20. It pauses itself and calls the function again for Node 20.

Node 20: Looks at its next pointer. It sees Node 30. It pauses itself and calls the function again for Node 30.

Node 30: Looks at its next pointer. It sees NULL (the end). It calls the function for NULL.

NULL: The function sees it's empty (if (head == NULL)), so it simply returns (closes).
Climbing back up;
Node 30 wakes up. The instruction it was waiting on is finished, so it moves to the next line: printf("%d ", head->data). It prints 30.

Node 20 wakes up now that 30 is done. It prints 20.

Node 10 wakes up last. It prints 10.

lastly, free() is used to cleanup the memory space assigned for the nodes using malloc.