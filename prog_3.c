#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Simple recursion to print backwards
void printBackwards(struct Node* head) {
    if (head == NULL) return;

    printBackwards(head->next);
    printf("%d ", head->data);
}

int main() {
    // Manually setting up nodes (very common student approach)
    struct Node* n1 = malloc(sizeof(struct Node));
    struct Node* n2 = malloc(sizeof(struct Node));
    struct Node* n3 = malloc(sizeof(struct Node));

    n1->data = 10;
    n1->next = n2;

    n2->data = 20;
    n2->next = n3;

    n3->data = 30;
    n3->next = NULL;

    printf("List in reverse: ");
    printBackwards(n1);
    printf("\n");

    // Clean up
    free(n1); free(n2); free(n3);
    
    return 0;
}

 
