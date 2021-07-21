/*
 * Simple linked list with loose end (final node points to NULL).
 * Todo:
 * Add node to list (OK)
 * Print list (OK)
 * Remove node from list (OK)
 * Count number of elements ()
 * Sort list by id ()
 */

#include <stdio.h>

typedef struct ll_node {
    unsigned int id;
    ll_node* next;
    void* sp;
};

typedef struct bla {
    int a;
    int b;
};

int ll_node_print (ll_node* p, void (*f)(void*)) {
    if (p == NULL)
        return -1;
    int ret = 0;
    ll_node* next = p;
    while (next != NULL) {
        printf (" %d ->", next->id);
        if (f != NULL) 
            f(next->sp);
        next = next->next;
    }
    printf("\n");
    return ret;
}

int ll_node_add (ll_node* first, ll_node* second) {
    if (first == NULL)
        return -1;
    int ret = 0;
    ll_node* next = first;
    while (next->next != NULL) {
        next = next->next;
    }
    next->next = second;
    return ret;
}

int ll_node_remove (ll_node* first, ll_node* n) {
    if (first == NULL)
        return -1;
    int ret = 0;
    ll_node* current = first;
    while (current->next != n && current != NULL) {
        current = current->next;        
    }
    if (current == NULL)
        return -1;
    ll_node* next = current->next->next;
    current->next->next = NULL;
    current->next = next;
    return ret;
}


int ll_node_count_elements (ll_node* first, unsigned int* output) {
    if (first == NULL || (*output) != 0)
        return -1;    
    int ret = 0;
    ll_node* current = first;
    while (current != NULL) {
        current = current->next;
        (*output)++;
    }
    return ret;
}

void bla_print (void* b) {
    bla* a = (bla*)b;
    printf("a=%d b=%d\n", a->a, a->b);
}

int main (void) {

    printf("Running\n");

    bla b = {
        .a = 1,
        .b = 2
    };

    unsigned int counter = 1;

    ll_node node1 = {
        .id = counter++,
        .next = NULL,
        .sp = (void*) &b
    };

   ll_node node2 = {
        .id = counter++,
        .next = NULL,
        .sp = (void*) &b
    };
    
   ll_node node3 = {
        .id = counter++,
        .next = NULL,
        .sp = (void*) &b
    };
    


    // ll_node_print(&node1, bla_print);
    ll_node_print(&node1, NULL);

    ll_node_add(&node1, &node2);
    ll_node_add(&node1, &node3);

    ll_node_print(&node1, NULL);
    unsigned int len = 0;    
    ll_node_count_elements(&node1, &len);
    printf("Number of elements: %u\n", len);

    ll_node_remove(&node1, &node2);

    ll_node_print(&node1, NULL);

    return 0;
}