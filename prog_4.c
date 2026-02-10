#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
void insertAfter(struct Node*prev_node, int value){
if(prev_node == NULL){
    printf("the given previous node cannot be NULL");
    return;
}
//newnode malloc
struct Node* new_node = malloc(sizeof(struct Node));
new_node->data = value;
// 2. Set new node's pointers
    new_node->next = prev_node->next;
    new_node->prev = prev_node;

    // 3. Link the previous node to the new node
    prev_node->next = new_node;

    // 4. Link the "next" node back to our new node (if it exists)
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }

}

void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) return;

    // If the node to be deleted is the head node
    if (*head_ref == del) {
        *head_ref = del->next;
    }

    // Change 'next' of the previous node
    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    // Change 'prev' of the next node
    if (del->next != NULL) {
        del->next->prev = del->prev;
    }

    free(del); // Give the memory back
}
int main() {
    // Start with an empty list
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 10;
    head->prev = NULL;
    head->next = NULL;

    // Add 30 after 10: [10] <-> [30]
    insertAfter(head, 30);

    // Add 20 after 10: [10] <-> [20] <-> [30]
    insertAfter(head, 20);

    printf("List after insertions: ");
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Delete the middle node (20)
    deleteNode(&head, head->next);

    printf("\nList after deleting 20: ");
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}