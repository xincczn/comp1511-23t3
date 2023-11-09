// Xing He
// Program to do various linked list exercises

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct node {
	int data;		// data item at this node
	struct node *next;		// pointer to the next node
};

// ---------- PRESCRIBED FUNCTIONS ----------
// Append to a linked list
struct node *add_last(struct node *head, int data);

// Prints the data of a linked list
void print_list(struct node *head);

// Returns a copy of the linked list and frees the original list.
struct node *copy(struct node *head);

// Returns a new linked list where it is the second appended to the first
struct node *list_append(struct node *first_list, struct node *second_list);

// Returns 1 if the two lists are identical, otherwise returns 0
int identical(struct node *first_list, struct node *second_list);

// Given two lists in strictly increasing order, perform the set operation: intersection.
// Return a new linked list (in strictly increasing order) of the elements in both set1 and set2
struct node *set_intersection(struct node *first_list, struct node *second_list);

// ---------- REVISION FUNCTIONS ----------
// Deletes the last node of the given linked list and returns the head of
// the linked list
struct node *delete_last(struct node *head);

// Returns 1 if list is in strictly increasing order, otherwise returns 0
int ordered(struct node *head);

// Given two linked lists in strictly increasing order, perform the set operation: union.
// Return a new linked list (in strictly increasing order) of the elements in either set1 or set2
// which has no duplicates (only include them once)
struct node *set_union(struct node *first_list, struct node *second_list);

// Frees all the elements in a linked list
void free_list(struct node *head);

// Return the number of items in the linked list
int num_items(struct node *head);

int main(void) {
    
    /** TEST YOUR FUNCTIONS **/


    // Here we test the union function
    struct node *new_list_1 = NULL;
    for (int i = 1; i <= 7; i++) {
        new_list_1 = add_last(new_list_1, i);
    }

    struct node *new_list_2 = NULL;
    for (int i = 3; i <= 10; i++) {
        new_list_2 = add_last(new_list_2, i);
    }

    printf("List 1: ");
    print_list(new_list_1);
    printf("List 2: ");
    print_list(new_list_2);

    struct node *union_list = set_union(new_list_1, new_list_2);

    printf("Unionised List: ");
    print_list(union_list);

    return 0;
}

/** REVISION FUNCTIONS **/

struct node *delete_last(struct node *head) {
    // Thought process: If we want to delete the last node (tail)
    //                  We will have to get access to the node pointing
    //                  to the tail. 

    // Empty list
    // Base case, if there are no nodes, we can't delete anything
    if (head == NULL) {
        return NULL;
    }

    // Single node list
    // When there is only one node, it is both the head and tail
    // As such, we must ensure that we update the head (return NULL)
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // At least two nodes list
    // Now we need to find the node pointing to the tail
    // We will use the two pointer approach 
    // We set `previous` to be that node we are trying to find
    // And set `current` to be the tail that will be deleted
    struct node *previous = head;
    struct node *current = head->next;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    // The loop ends when current->next is NULL and therefore current is the tail
    // Ensure after freeing, we set previous to be the new tail
    free(current);
    previous->next = NULL;
    return head;
}

int ordered(struct node *head) {
    // Thought process: We can simply check if the current node is strictly
    //                  smaller than the previous for all nodes

    // Empty list
    // Base case, if there are no nodes, then the list is ordered by default
    if (head == NULL) {
        return TRUE;
    }

    // Single node list
    // Likewise, when there is only one node, the list is ordered by default
    if (head->next == NULL) {
        return TRUE;
    }

    // At least two nodes
    // We do the comparison for each node
    struct node *previous = head;
    struct node *current = head->next;
    while (current != NULL) {
        // If at least one pair of previous and current node isn't in
        // ascending order, then the list is not ordered
        if (current->data >= previous->data) {
            return FALSE;
        }

        previous = current;
        current = current->next;
    }

    // If we finish iterating the list without triggering the if statement
    // Then the list must be ordered
    return TRUE;
}

struct node *set_union(struct node *first_list, struct node *second_list) {
    // Thought process: The hint to solving this question is the fact that
    //                  both list are ordered.
    //                  We can simply just "bite" through both lists at the same
    //                  time to go through each number, adding unique ones to
    //                  the list

    // Keeps track of last number we added (avoid duplicates)
    int last_added = 0;
    
    // New list
    struct node *new_list = NULL;

    // Step 1: Bite at the same time
    struct node *remaining_first = first_list;
    struct node *remaining_second = second_list;
    
    // This condition might look scary but it simply states, if either list is 
    // empty, exit the loop
    while (remaining_first != NULL && remaining_second != NULL) {

        // We create a current pointer for the next node that we should
        // consider appending, "biting" it off that list
        struct node *current = NULL;
        if (remaining_first->data < remaining_second->data) {
            current = remaining_first;
            remaining_first = remaining_first->next;
        } else {
            current = remaining_second;
            remaining_second = remaining_second->next;
        }

        // Check if not duplicate, add to `new_list`
        if (current->data > last_added) {
            last_added = current->data;
            new_list = add_last(new_list, current->data);
        }
    }

    // Once we have exited the loop
    // Either or both of the two lists will be empty
    // We simply add the remaining "bites" to the `new_list`
    struct node *current = NULL;
    if (remaining_first == NULL) {
        current = remaining_second;
    } else {
        current = remaining_first;
    }

    while (current != NULL) {
        // Check that the current node isn't a duplicate
        if (current->data > last_added) {
            last_added = current->data;
            new_list = add_last(new_list, current->data);
        }

        current = current->next;
    }

    // Finally all nodes have been removed, we can return new list
    return new_list;
}


void free_list(struct node *head) {
    // Refer to delete_list.c
}

int num_items(struct node *head) {
    // Thought process: We simple need to count the amount of nodes
    //                  Same process as counting the length of a string
    int length = 0;
    struct node *current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}

/** PRESCRIBED FUNCTIONS **/

struct node *add_last(struct node *head, int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    // Return new if linked list is initially empty
    if (head == NULL) {
        return new;
    }

    // Otherwise, loop to end of list and add node.
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new;

    // We are inserting at the end --> head will not change
    return head;
}

void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}

struct node *copy(struct node *list) {
    return NULL;
}

struct node *list_append(struct node *first_list, struct node *second_list) {
    return NULL;
}

int identical(struct node *first_list, struct node *second_list) {
    return 5841;
}

struct node *set_intersection(
    struct node *first_list,
    struct node *second_list
) {
    return NULL;
}