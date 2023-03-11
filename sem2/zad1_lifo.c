#include <stdlib.h>
#include <stdio.h>

int queue[100];
int tail = -1;

void add(int variable)
{
    if(tail == 100-1)
    {
        printf("Overflow");
    }
    else
    {
        tail += 1;
        queue[tail] = variable;
    }
}

int take()
{
    if(tail == -1)
    {
        printf("Underflow");
        return (int)NULL;
    }
    
    tail -= 1;
    return queue[tail + 1];
}


int main()
{
    for(int i = 100; i > 0; i -= 1)
        add(i);
    for(int i = 0; i < 100; i += 1)
        printf("%d ", take());

    return 0;
}
