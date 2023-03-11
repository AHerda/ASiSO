#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* previous;
} node;

void add(node* start, int value)
{
    if(!start)
        return;

    node* new = (node*)malloc(sizeof(node));
    if(!new)
        return;

    new->next = start;
    new->previous = start->previous;
    new->data = value;

    start->previous->next = new;
    start->previous = new;
}

int show(node* start, int n)
{
    if(!start)
        return (int)NULL;
    
    node* current = start;
    for(int i = 0; i < n; i += 1)
        current = current->next;
    return current->data;
}

void delete_first(node* start, int value)
{
    if(!start)
        return;

    node* current = start->next;
    while(current != start && current->data != value)
        current = current->next;
//start not checked
    if(start->data == value)
    {
        current = start;
        start = start->next;
    }

    current->next->previous = current->previous;
    current->previous->next = current->next;
    free(current);
}

void merge(node* first, node* second)
{
    if(!first || !second)
        return;

    second->previous->next = first->next;
    first->next->previous = second->previous;
    first->next = second;
    second->previous = first;
}
