#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* next;
} node;

void add(node* head, int variable)
{
    if(!head)
        return;

    node* new = (node *)malloc(sizeof(node));
    if(!new)
        return;
    new->data = variable;
    new->next = NULL

    node* current = head;
    while(current->next != NULL)
        current = current->next;

    current->next = new;
}

int show(node* head, int n)
{
    if(!head)
        return (int)NULL;

    node* current = head;

    for(int i = 0; i < n; i += 1)
    {
        if(current->next == NULL)
            return (int)NULL;
        current = current->next;
    }
    return current->data;
}

void delete_first(node* head, int variable)
{
    if(!head)
        return;

    node* current = head;
    while(current->next != NULL && current->next->data != varaible)
        current = current->next;

    if(head->data == variable)
    {
        current = head;
        head = head->next;
    }
    else if(!(current->next))
        return;

    node* to_delete = current->next;
    current->next = current->next->next;
    free(to_delete);
}

void merge(node* main, node* addition)
{
    if(!main || !addition)
        return;

    node* current = main;
    while(main->next != NULL)
        current = current->next;

    current->next = addition;
}


int main()
{

}
