#include <stdio.h>

#include "linked_list.h"

int ll_node_print (ll_node* p, void (*f)(void*)) {
    if (p == NULL)
        return -1;
    int ret = 0;
    ll_node* next = p;
    while (next != NULL) {
        printf (" %d ->", next->id);
        if (f != NULL) 
            f(next->sp);
        next = (ll_node*)next->next;
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
        next = (ll_node*)next->next;
    }
    next->next = (struct ll_node*)second;
    return ret;
}

int ll_node_remove (ll_node* first, ll_node* n) {
    if (first == NULL)
        return -1;
    int ret = 0;
    ll_node* current = first;
    while ((struct ll_node*)current->next != (struct ll_node*)n && current != NULL) {
        current = (ll_node*)(current->next);        
    }
    if (current == NULL)
        return -1;
    // ll_node* next = current->next->next;
    ll_node* next = (ll_node*)current->next;
    next = (ll_node*)next->next;
    // current->next->next = NULL;
    ll_node* temp = (ll_node*)current->next;
    temp->next = NULL;
    current->next = (struct ll_node*)next;
    return ret;
}


int ll_node_count_elements (ll_node* first, unsigned int* output) {
    if (first == NULL || (*output) != 0)
        return -1;    
    int ret = 0;
    ll_node* current = first;
    while (current != NULL) {
        current = (ll_node*)current->next;
        (*output)++;
    }
    return ret;
}