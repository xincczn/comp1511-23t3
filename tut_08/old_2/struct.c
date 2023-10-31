#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    double count;
    struct node *next;
};

struct node *create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->count = 0.0;
    new_node->next = NULL;

    return new_node;
}

struct

int main() {

    struct node *node_1 = create_node(0);
    struct node *node_2 = create_node(1);
    struct node *node_3 = create_node(2);

    node_1->next = node_2;
    node_2->next = node_3;



    struct node *current = node_1;
    while (current != NULL) {
        printf("%d -> ", current->data);

        current = current->next;
    }

    printf("X\n");
}