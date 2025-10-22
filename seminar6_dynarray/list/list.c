#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

// Error checked malloc
void* ecmalloc(size_t n)
{
    void* p = malloc(n);
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    return p;
}

List init(size_t n)
{
    List result;
    result.head = NULL;
    result.tail = NULL;
    result.size = 0;
    
    for (size_t i = 0; i < n; i++) {
        push_back(&result, 0);
    }
    
    return result;
}

void print(const List* pl)
{
    Node* current = pl->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void push_back(List* pl, int value)
{
    Node* new_node = (Node*)ecmalloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = pl->tail;
    
    if (pl->tail != NULL) {
        pl->tail->next = new_node;
    } else {
        pl->head = new_node;
    }
    
    pl->tail = new_node;
    pl->size++;
}

int pop_back(List* pl)
{
    if (pl->size == 0) {
        fprintf(stderr, "Error: Cannot pop from empty list\n");
        exit(1);
    }
    
    Node* last = pl->tail;
    int value = last->value;
    
    if (pl->tail->prev != NULL) {
        pl->tail->prev->next = NULL;
        pl->tail = pl->tail->prev;
    } else {
        pl->head = NULL;
        pl->tail = NULL;
    }
    
    free(last);
    pl->size--;
    return value;
}

void push_front(List* pl, int value)
{
    Node* new_node = (Node*)ecmalloc(sizeof(Node));
    new_node->value = value;
    new_node->next = pl->head;
    new_node->prev = NULL;
    
    if (pl->head != NULL) {
        pl->head->prev = new_node;
    } else {
        pl->tail = new_node;
    }
    
    pl->head = new_node;
    pl->size++;
}

int pop_front(List* pl)
{
    if (pl->size == 0) {
        fprintf(stderr, "Error: Cannot pop from empty list\n");
        exit(1);
    }
    
    Node* first = pl->head;
    int value = first->value;
    
    if (pl->head->next != NULL) {
        pl->head->next->prev = NULL;
        pl->head = pl->head->next;
    } else {
        pl->head = NULL;
        pl->tail = NULL;
    }
    
    free(first);
    pl->size--;
    return value;
}

Node* erase(List* pl, Node* p)
{
    if (p == NULL) return NULL;
    
    Node* next = p->next;
    
    if (p->prev != NULL) {
        p->prev->next = p->next;
    } else {
        pl->head = p->next;
    }
    
    if (p->next != NULL) {
        p->next->prev = p->prev;
    } else {
        pl->tail = p->prev;
    }
    
    free(p);
    pl->size--;
    return next;
}

void splice(List* plist, Node* p, List* pother)
{
    if (pother->size == 0) return;
    
    // Connect pother list to plist
    if (p != NULL) {
        // Insert before p
        if (p->prev != NULL) {
            p->prev->next = pother->head;
        } else {
            plist->head = pother->head;
        }
        pother->head->prev = p->prev;
        p->prev = pother->tail;
        pother->tail->next = p;
    } else {
        // Insert at the end
        if (plist->tail != NULL) {
            plist->tail->next = pother->head;
            pother->head->prev = plist->tail;
        } else {
            plist->head = pother->head;
        }
        plist->tail = pother->tail;
    }
    
    plist->size += pother->size;
    
    // Clear pother
    pother->head = NULL;
    pother->tail = NULL;
    pother->size = 0;
}

void destroy(List* pl)
{
    Node* current = pl->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    
    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
}

void advance(Node** pp, size_t n)
{
    for (size_t i = 0; i < n && *pp != NULL; i++) {
        *pp = (*pp)->next;
    }
}
