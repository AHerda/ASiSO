#include <stdlib.h>
#include <stdio.h>

int queue[100];
int tail = -1;

void add(int variable)
{
    if(tail == 99)
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
    int result = queue[0];
    for(int i = 0; i < tail; i += 1)
        queue[i] = queue[i + 1];

    tail -= 1;

    return result;
}


int main()
{
    for(int i = 100; i > 0; i -= 1)
        add(i);
    for(int i = 0; i < 100; i += 1)
        printf("%d ", take());
    
    return 0;
}
