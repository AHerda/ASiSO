#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    struct Node* next;
    struct Node* previous;
    int data;
    int id;
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
    new->id = new->previous->id + 1;

    new->previous->next = new;
    start->previous = new;
}

int get(node* start, int n)
{
    if(!start)
        return (int)NULL;
    
    node* current = start;
    int len = (current->previous->id + 1);
    if(n < len / 2)
        for(int i = 0; i < n; i += 1)
            current = current->next;
    else
        for(int i = 0; i < len - n; i += 1)
            current = current->previous;

    return current->data;
}

void merge(node* first, node* second)
{
    if(!first || !second)
        return;
    
    int len = first->previous->id + second->previous->id; 

    second->previous->next = first;
    first->previous->next = second;

    node* first_end = first->previous; 

    first->previous = second->previous;
    second->previous = first_end;

    first->previous->id = len;
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
    } while(current != head);
}

node* create(int value)
{
    node* new = (node *) malloc(sizeof(node));
    new->data = value;
    new->id = 0;
    new->next = new;
    new->previous = new;

    return new;
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
        get(head, 9000);
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
    
    node* list1 = create(-1);
    node* list2 = create(0);

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
