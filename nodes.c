#include <stdio.h>
#include <stdlib.h>

// define a linked list node structure
struct Node {
    int data;
    struct Node *next;
};

// function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// function to insert a node at the beginning of the list
void insertAtBeginning(struct Node **head_ref, int new_data) {
    // create a new node
    struct Node *new_node = newNode(new_data);

    // update head pointer
    new_node->next = *head_ref;
    *head_ref = new_node;
}


}

// function to delete a node at a specific position in the list
void deleteAtPosition(struct Node **head_ref, int position) {
    // traverse the list to the position before the deletion point
    struct Node *prev_node = *head_ref;
    for (int i = 1; i < position - 1 && prev_node != NULL; i++) {
        prev_node = prev_node->next;
    }

    // if position is valid, delete node
    if (prev_node != NULL && prev_node->next != NULL) {
        struct Node *temp = prev_node->next;
        prev_node->next = temp->next;
        free(temp);
    } else {
        printf("Invalid position.\n");
    }
}

// function to print the linked list
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    // insert nodes at beginning of list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // print the linked list
    printf("Linked list: ");
    printList(head);

    // insert node at position 2
    insertAtPosition(&head, 4, 2);
    printf("Linked list after insertion: ");
    printList(head);

    // delete node at position 3
    deleteAtPosition(&head, 3);
    printf("Linked list after deletion: ");
    printList(head);

    return 0;
}
