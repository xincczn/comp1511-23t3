#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};


struct node *create_node(int value);
void print_list(struct node *head);

int main() {

    struct node *node_1 = create_node(101);
    struct node *node_2 = create_node(202);
    struct node *node_3 = create_node(303);

    node_1->next = node_2;
    node_2->next = node_3;

    print_list(node_1);
}

// Creates a new node with given value
struct node *create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;

    return new_node;
}

// Print out a linked list
void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

