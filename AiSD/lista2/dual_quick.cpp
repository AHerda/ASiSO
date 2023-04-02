#include <iostream>
#include "sorts.hpp"

int size_global;
int counter_if = 0, counter_swap = 0;

int main(int argc, char** argv) {
    int* tab;

    if(argc == 1) {
        setbuf(stdin, NULL);
        scanf("%d", &size_global);

        tab = new int[size_global];

        for(int i = 0; i < size_global; i++) {
            scanf("%d", &(tab[i]));
        }
    }
    else {
        size_global = argc - 1;
        tab = new int[size_global];

        for(int i = 1; i < argc; i++) {
            sscanf(argv[i], "%d", &(tab[i - 1]));
        }
    }

    if(size_global < 40) {
        print_tab(tab, size_global);
    }

    //dual_pivot_quick_sort(tab, 0, size_global - 1);
    sort(tab, 0, size_global - 1);

    if(size_global < 40) {
        print_tab(tab, size_global);
    }

    for(int i = 0; i + 1 < size_global; i++) {
        if(tab[i] > tab[i + 1]) return 0;
    }

    if(size_global < 40) { std::cout << std::endl << "n | # Prównań kluczy | # Podmian kluczy " << std::endl; }
    std::cout << size_global << " " << counter_if << " " << counter_swap << std::endl;

    return 1;
}


void print_tab(int* tab, int size, int start) {
    for (int i = start; i < size; i++)
        std::cout << tab[i] << " ";
    std::cout << std::endl;
}

void sort(int* A, int left, int right) {
    if (right > left) {
        // Choose outermost elements as pivots
        counter_if++;
        if (A[left] > A[right]) swap2(A, left, right);
        int p = A[left], q = A[right];

        // Partition A according to invariant below
        int l = left + 1, g = right - 1, k = l;
        while (k <= g) {
            if (A[k] < p) {
                swap2(A, k, l);

                ++l;
                counter_if++;
            }
            else if (A[k] >= q) {
                while (A[g] > q && k < g) --g;
                swap2(A, k, g);
                --g;
                if (A[k] < p) {
                    swap2(A, k, l);

                    ++l;
                    counter_if += 2;
                }
            }
            ++k;
        }
        --l; ++g;

        // Swap pivots to final place
        swap2(A, left, l);
        swap2(A, right, g);

        if(size_global < 40) print_tab(A, right + 1, left);

        // Recursively sort partitions
        sort(A, left, l - 1);
        sort(A, l + 1, g - 1);
        sort(A, g + 1, right);
    }
}

void swap2(int* A, int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
    counter_swap++;
}

void dual_pivot_quick_sort(int* tab, int low, int high) {
    if(high <= low) return;
    
    int left_pivot, right_pivot;

    partition(tab, low, high, &left_pivot, &right_pivot);

    dual_pivot_quick_sort(tab, low, left_pivot - 1);
    dual_pivot_quick_sort(tab, left_pivot + 1, right_pivot - 1);
    dual_pivot_quick_sort(tab, right_pivot + 1, high);
}

void partition(int* tab, int low, int high, int* left_pivot, int* right_pivot) {
    counter_if++;
    if(tab[low] > tab[high]) swap(&tab[low], &tab[high]);

    int i = low + 1;        //left index
    int j = high - 1;       //rught index
    int* p = &tab[low];     //left pivot p <= q
    int* q = &tab[high];    //right pivot q >= p
    int small = 0;          // # of items to the left of left_pivot
    int large = 0;          // # of items to the righ of right_pivot

    while(i <= j) {
        if(small >= large) {
            counter_if++;
            if (tab[i] <= *p) {
                swap(&tab[i], p);

                i++;
                small++;
            }
            else if(tab[i] > *q) {
                swap(&tab[i], q);

                i++;
                counter_if++;
                large++;
            }
            else {
                i++;
                counter_if++;
            }
        }
        else {
            counter_if++;
            if(tab[i] > *q) {
                swap(&tab[i], q);

                i++;
                large++;
            }
            else if (tab[i] <= *p) {
                swap(&tab[i], p);

                i++;
                counter_if++;
                small++;
            }
            else {
                i++;
                counter_if++;
            }
        }
    }

    *left_pivot = *p;
    *right_pivot = *q;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    counter_swap++;
}