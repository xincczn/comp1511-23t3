#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

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
struct node *create_list(int size);

// New functions
struct node *delete_list(struct node *head);
struct node *delete_node(struct node *head, int id);

// Main
int main(void) {
    struct node *head = create_list(SIZE);
    print_list(head);

    return 0;
}

// Deletes entire list
struct node *delete_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        // Create a temp pointer to keep track of to be deleted node
        // That way `current` can remain iterating through list
        struct node *temp = current;
        current = current->next;

        // Frees memory pointed by `temp`
        free(temp);
    }
    
    // Freeing memory doesn't update pointers
    // The `head` pointer will still point to where the head used to be located
    // Returning NULL allow us to update the head afterwards
    return NULL;
}

// Removes node with value matching `id`
struct node *delete_node(struct node *head, int id) {
    // Empty list
    if (head == NULL) {
        return NULL;
    }

    // If node to be deleted is the head
    // We must update head
    if (head->value == id) {
        struct node *next = head->next;
        free(head);

        return next;
    }

    // If node to be deleted is not the head
    // We must connect the adjacent nodes
    // We will use the two pointer strategy

    // From the above if statement, we know that the head isn't our node
    struct node *previous = head;
    // So we start with current at the second node;
    struct node *current = head->next;
    while (current != NULL) {
        // Find the node which matches `id`
        if (current->value == id) {
            // Redirect adjacent nodes
            previous->next = current->next;
            free(current);

            // Return early since we have deleted the right node
            // Returns `head` as the head isn't modified during this operation
            return head;
        }

        // Step our iterators
        // ENSURE WE UPDATE `previous` before `current` (the order matters)
        previous = current;
        current = current->next;
    }

    // Reached this line, if we node wasn't found and nothing was deleted
    return head;
}


// Creates a list of nodes from 1 to size
struct node *create_list(int size) {
    struct node *head = NULL;

    int i = 0;
    while (i < size) {
        struct node *new_node = create_node(i + 1);
        head = append_to_tail(new_node, head);
        i++;
    }

    return head;
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