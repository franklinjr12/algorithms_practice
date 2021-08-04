/*
 * Simple linked list with loose end (final node points to NULL).
 * Todo:
 * Add node to list (OK)
 * Print list (OK)
 * Remove node from list (OK)
 * Count number of elements (OK)
 * Sort list by id ()
 */

#include <stdio.h>

#include "linked_list.h"

typedef struct {
    int a;
    int b;
}bla;

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