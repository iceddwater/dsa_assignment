To implement a doubly linked list using structure:

Stricture requires: data pointer to previous node and pointer to next node
 Order: prev_node <-> new_node <-> next_node

Program flow:
1. Each node has previous and next node;
When main() starts, malloc allocates a space for head resulting NULL <- 10 -> NULL

2. After insertAfter();
When insertAfter(head, 30) is called, 
i. space with 30 is created.
ii. forward: head->next which points to newNode that is 30
iii. backward: newNode->prev points to head
NULL<-10<->30->NULL
iv. insertAfter(head, 20), squeezes 20 between 10 and 30:

3. while(temp != NULL) in main() prints from head then steps to next step using temp=temp->next till NULL.

4. When we delete head->next (which is node 20):
i. looks at 20's neighbors(10 & 30)
ii. tells 10 to skip next to 30
iii. tells 30 to skip prev to 10
iv. free() is called deleting 20 from heap memory.

5. the program prints the lists
List after insertions: 10 20 30 
List after deleting 20: 10 30

 
