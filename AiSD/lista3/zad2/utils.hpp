#ifndef utils_hpp
#define utils_hpp

// All usage

int size_global;
int counter_if = 0, counter_swap = 0;

void swap(int* a, int* b, int* counter_swap = nullptr) {
    int temp = *a;
    *a = *b;
    *b = temp;

    if(counter_swap) *counter_swap += 1;
}

#endif