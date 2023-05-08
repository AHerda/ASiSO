#include <iostream>
#include <chrono>
#include <climits>
#include "utils.hpp"

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
    if(size_global <= 50) print_tab(tab, size_global);

    auto start = std::chrono::high_resolution_clock::now();

    dual_pivot_quick_sort(tab, 0, size_global - 1);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    if(size_global <= 50) {
        print_tab(tab, size_global);

        std::cout << std::endl << "n | # Porównań kluczy | Czas wykonywania" << std::endl;
    }
    std::cout << size_global << " " << counter_if << " " << duration.count() << std::endl;

    for(int i = 0; i + 1 < size_global; i++) {
        if(tab[i] > tab[i + 1]) return 0;
    }
    return 1;
}

void dual_pivot_quick_sort(int* tab, int low, int high) {
    if(high <= low) return;
    
    int left_pivot, right_pivot;

    partition_old(tab, low, high, &left_pivot, &right_pivot);

    dual_pivot_quick_sort(tab, low, left_pivot - 1);
    dual_pivot_quick_sort(tab, left_pivot + 1, right_pivot - 1);
    dual_pivot_quick_sort(tab, right_pivot + 1, high);
}

void partition(int* tab, int low, int high, int* left_pivot, int* right_pivot) {
    counter_if++;
    if(tab[low] > tab[high]) {
        swap(&tab[low], &tab[high]);
    }

    int i = low + 1;
    int j = high - 1;
    int k = i;

    *left_pivot = select(tab, low, high, (high - low + 1) / 3);
    *right_pivot = select(tab, low, high, ((high - low + 1) * 2) / 3);

    int small = 0;          // # of items to the left of left_pivot
    int large = 0;          // # of items to the righ of right_pivot

    while(k <= j) {
        if(small <= large) {
            if (tab[k] <= *left_pivot) {
                swap(&tab[i], &tab[k]);

                i++;

                counter_if++;
                small++;
            }
            else if(tab[k] > *right_pivot) {
                counter_if++;
                while(tab[j] > *right_pivot && k < j) {
                    --j;
                    counter_if++;
                }

                swap(&tab[k], &tab[j]);
                --j;

                counter_if++;
                if(tab[k] <= *left_pivot) {
                    swap(&tab[k], &tab[i]);
                    ++i;
                    small++;
                }

                counter_if += 2;
                large++;
            }
            else {
                counter_if += 2;
            }
        }
        else {
            if (tab[k] > *right_pivot) {
                swap(&tab[j], &tab[k]);

                --j;

                counter_if++;
                large++;
            }
            else if(tab[k] <= *left_pivot) {
                counter_if++;
                while(tab[i] < *left_pivot && k > i) {
                    i++;
                    counter_if++;
                }

                swap(&tab[k], &tab[i]);
                i++;

                counter_if++;
                if(tab[k] > *right_pivot) {
                    swap(&tab[k], &tab[j]);

                    j--;

                    large++;
                }

                counter_if += 2;
                small++;
            }
            else {
                counter_if += 2;
            }
        }
        ++k;
    }
    --i;
    ++j;

    if(size_global < 40) print_tab(tab, high + 1, low);

    swap(&tab[low], &tab[i]);
    swap(&tab[high], &tab[j]);

    *left_pivot = i;
    *right_pivot = j;
}

void partition_old(int* tab, int low, int high, int* left_pivot, int* right_pivot) {
    counter_if++;
    if(tab[low] > tab[high]) {
        swap(&tab[low], &tab[high]);
    }

    int i = low + 1;
    int j = high - 1;
    int k = i;

    *left_pivot = tab[low];     //left pivot p <= q
    *right_pivot = tab[high];    //right pivot q >= p

    int small = 0;          // # of items to the left of left_pivot
    int large = 0;          // # of items to the righ of right_pivot

    while(k <= j) {
        if(small <= large) {
            if (tab[k] <= *left_pivot) {
                swap(&tab[i], &tab[k]);

                i++;

                counter_if++;
                small++;
            }
            else if(tab[k] > *right_pivot) {
                counter_if++;
                while(tab[j] > *right_pivot && k < j) {
                    --j;
                    counter_if++;
                }

                swap(&tab[k], &tab[j]);
                --j;

                counter_if++;
                if(tab[k] <= *left_pivot) {
                    swap(&tab[k], &tab[i]);
                    ++i;
                    small++;
                }

                counter_if += 2;
                large++;
            }
            else {
                counter_if += 2;
            }
        }
        else {
            if (tab[k] > *right_pivot) {
                swap(&tab[j], &tab[k]);

                --j;

                counter_if++;
                large++;
            }
            else if(tab[k] <= *left_pivot) {
                counter_if++;
                while(tab[i] < *left_pivot && k > i) {
                    i++;
                    counter_if++;
                }

                swap(&tab[k], &tab[i]);
                i++;

                counter_if++;
                if(tab[k] > *right_pivot) {
                    swap(&tab[k], &tab[j]);

                    j--;

                    large++;
                }

                counter_if += 2;
                small++;
            }
            else {
                counter_if += 2;
            }
        }
        ++k;
    }
    --i;
    ++j;

    if(size_global < 40) print_tab(tab, high + 1, low);

    swap(&tab[low], &tab[i]);
    swap(&tab[high], &tab[j]);

    *left_pivot = i;
    *right_pivot = j;
}



// Zapasowe implementacje 

int select(int tab[], int l, int r, int k) {
    if(k > 0 && k <= r - l + 1) {
        int i = partition(tab, l, r);

        if(i - l + 1 == k) {
            return tab[i];
        }
        if(i - l + 1 > k) {
            return select(tab, l, i - 1, k);
        }
        return select(tab, i + 1, r, k - i + l - 1);
    }
    return INT_MAX;
}

int partition(int tab[], int l, int r) {
    int pivot = tab[(r + l) / 2];
    int i = l;

    for(int j = l; j <= r - 1; j++) {
        counter_if++;
        if(tab[j] <= pivot) {
            swap(&tab[i], &tab[j]);
            i++;
        }
    }
    swap(&tab[i], &tab[r]);
    return i;
}