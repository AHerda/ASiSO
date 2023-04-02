#ifndef sorts_hpp
#define sorts_hpp

#include <iostream>
#include <vector>
#include <string>

//all usage

int counter_if = 0, counter_swap = 0;

void swap(int* a, int* b, int &counter_swap) {
    int temp = *a;
    *a = *b;
    *b = temp;

    counter_swap += 1;
}

#endif