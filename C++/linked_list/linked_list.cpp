/*
 * Simple linked list with loose end (final node points to NULL).
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
        printf ("id = %d\n", next->id);
        if (f != NULL) 
            f(next->sp);
        next = next->next;
    }
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


    // ll_node_print(&node1, bla_print);
    ll_node_print(&node1, NULL);

    ll_node_add(&node1, &node2);

    ll_node_print(&node1, NULL);

    return 0;
}