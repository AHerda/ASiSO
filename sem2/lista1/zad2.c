#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node* next;
} node;

node* create(int value)
{
    node* new = (node*) malloc(sizeof(node));
    new->data = value;
    new->next = NULL;

    return new;
}

void add(node* head, int variable)
{
    if(!head)
        return;

    node* new = (node *)malloc(sizeof(node));
    if(!new)
        return;
    new->data = variable;
    new->next = NULL;

    node* current = head;
    while(current->next != NULL)
        current = current->next;

    current->next = new;
}

int get(node* head, int n)
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

void show_all(node* head)
{
    if(!head)
        return;

    node* current = head;

    do
    {
        printf("%d, ", current->data);
        current = current->next;
    } while(current != NULL);
}

void delete_first(node* head, int variable)
{
    if(!head)
        return;

    node* current = head;
    while(current->next != NULL && current->next->data != variable)
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
    while(current->next != NULL)
        current = current->next;

    current->next = addition;
}


int main()
{
    srand(time(NULL));
    node* head = create(rand());

    for(int i = 0; i < 10000; i += 1)
        add(head, rand());

    double sum = 0;
    for(int i = 0; i < 1000; i += 1)
    {
        clock_t time;

        time = clock();
        get(head, 1000);
        time = clock() - time;
        sum += ((double) time) / CLOCKS_PER_SEC;
    }
    
    printf("sredni czas dostepu do 1000 elementu: %f skeund\n", sum);
    
    sum = 0;
    for(int i = 0; i < 1000; i += 1)
    {
        clock_t time;

        time = clock();
        get(head, 7543);
        time = clock() - time;
        sum += ((double) time) / CLOCKS_PER_SEC;
    }
    
    printf("sredni czas dostepu do 7543 elementu: %f skeund\n", sum);
    
    sum = 0;
    for(int i = 0; i < 1000; i += 1)
    {
        clock_t time;

        int t = rand() % 10000;

        time = clock();
        get(head, t);
        time = clock() - time;
        sum += ((double) time) / CLOCKS_PER_SEC;
    }
    
    printf("sredni czas dostepu do losowego elementu: %f skeund\n", sum);
    
    node* list1 = (node*) malloc(sizeof(node));
    list1->data = -1;
    list1->next = NULL;
    node* list2 = (node*) malloc(sizeof(node));
    list2->data = 0;
    list2->next = NULL;

    add(list1, 1);
    add(list1, 3);
    add(list1, 5);
    add(list1, 7);
    add(list2, 2);
    add(list2, 4);
    add(list2, 6);
    add(list2, 8);

    merge(list1, list2);
    show_all(list1);

    return 0; 
}
