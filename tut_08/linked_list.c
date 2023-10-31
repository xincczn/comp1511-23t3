#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    return new_node;
}

void print_list(struct node *head) {

    struct node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;        
    }
    printf("X\n");

}

struct node *insert_head(struct node *head, struct node *new) {
    if (head == NULL) {
        return new;
    }

    new->next = head;
    return new;
}

void insert_tail(struct node *head, struct node *new) {
    if (head == NULL) {
        return new;
    }
    
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new;
}

int main() {

    struct node *node_1 = create_node(10);
    struct node *node_2 = create_node(20);
    struct node *node_3 = create_node(30);

    node_1->next = node_2;
    node_2->next = node_3;

    print_list(node_1);

    struct node *new = create_node(0);
    struct node *list = node_1;

    list = insert_head(list, new);

    struct node *new_2 = create_node(40);
    insert_tail(list, new_2);


}

