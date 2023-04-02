#include <iostream>
#include <string>


void partition(int* tab, int low, int high, int* left_pivot, int* right_pivot);

std::string dual_pivot_quick_sort(int* tab, int low, int high) {
    if(high <= low) return std::to_string(high + 1 - low) + " " + std::to_string(counter_if) + " " + std::to_string(counter_swap) + "\n";
    
    int left_pivot, right_pivot;

    partition(tab, low, high, &left_pivot, &right_pivot);

    dual_pivot_quick_sort(tab, low, left_pivot - 1);
    dual_pivot_quick_sort(tab, left_pivot + 1, right_pivot - 1);
    dual_pivot_quick_sort(tab, right_pivot + 1, high);

    return std::to_string(high + 1 - low) + " " + std::to_string(counter_if) + " " + std::to_string(counter_swap) + "\n";
}

void partition(int* tab, int low, int high, int* left_pivot, int* right_pivot) {
    counter_if++;
    if(tab[low] > tab[high]) {
        swap(&tab[low], &tab[high], counter_swap);
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
                swap(&tab[i], &tab[k], counter_swap);

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

                swap(&tab[k], &tab[j], counter_swap);
                --j;

                counter_if++;
                if(tab[k] <= *left_pivot) {
                    swap(&tab[k], &tab[i], counter_swap);
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
                swap(&tab[j], &tab[k], counter_swap);

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

                swap(&tab[k], &tab[i], counter_swap);
                i++;

                counter_if++;
                if(tab[k] > *right_pivot) {
                    swap(&tab[k], &tab[j], counter_swap);

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

    swap(&tab[low], &tab[i], counter_swap);
    swap(&tab[high], &tab[j], counter_swap);

    *left_pivot = i;
    *right_pivot = j;
}