#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct node {
    // Node Values
    int value;

    // Next Pointer
    struct node *next;
};

// Linked List functions
struct node *create_node(int value);
struct node *append_to_head(struct node *new_node, struct node *head);
struct node *append_to_tail(struct node *new_node, struct node *head);
void print_list(struct node *head);

// Main
int main(void) {
    // New empty list
    struct node *head = NULL;

    // Created a bunch of nodes
    struct node *node1 = create_node(1);
    struct node *node2 = create_node(2);
    struct node *node3 = create_node(3);

    // Insert to head
    head = append_to_head(node1, head);
    head = append_to_head(node2, head);
    head = append_to_head(node3, head);

    // Create more nodes
    struct node *node4 = create_node(4);
    struct node *node5 = create_node(5);
    struct node *node6 = create_node(6);

    // Insert to tail
    head = append_to_tail(node4, head);
    head = append_to_tail(node5, head);
    head = append_to_tail(node6, head);

    print_list(head);

    return 0;
}

// Creates a new node
struct node *create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    // Remember to always set new node's next to null initially
    // Eliminates errors where next is uninitialised
    new_node->next = NULL;  

    return new_node;
}

// Inserts node as new head of list
struct node *append_to_head(struct node *new_node, struct node *head) {
    // Empty List Case
    if (head == NULL) {
        // Remember that single nodes are just linked list with 1 element
        return new_node;
    }

    new_node->next = head;
    return new_node;
}

// Inserts node as new tail of list
struct node *append_to_tail(struct node *new_node, struct node *head) {
    // Empty List Case
    if (head == NULL) {
        return new_node;
    }

    // Loop that positions `current` to the tail of the list
    struct node *current = head;
    // Note that this loop while fail if the base case isn't handled
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    return head;
}

// Prints list out
void print_list(struct node *head) {
    // Standard iterating structure for linked lists
    struct node *current = head;
    while (current != NULL) {
        // Prints individual node's value, formatted by an arrow 
        printf("%d -> ", current->value);
        current = current->next;
    }
    // We can't physically print NULL's value, so we print a X
    printf("X\n");  
}