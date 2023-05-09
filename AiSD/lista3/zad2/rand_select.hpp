#include <climits>

int partition2(int tab[], int l, int r);

int rand_select(int tab[], int l, int r, int k) {

    if(k > 0 && k <= r - l + 1) {
        if(l == r) return tab[l];
        int i = partition2(tab, l, r);

        if(i - l + 1 == k) {
            return tab[i];
        }
        if(i - l + 1 > k) {
            return rand_select(tab, l, i - 1, k);
        }
        return rand_select(tab, i + 1, r, k - i + l - 1);
    }
    return INT_MAX;
}

int partition2(int tab[], int l, int r) {
    int index = l + (mt() % (r - l + 1));
    int pivot = tab[index];

    swap(&tab[index], &tab[r], &counter_swap);
    int i = l;

    for(int j = l; j < r; j++) {
        counter_if++;
        if(tab[j] <= pivot) {
            swap(&tab[i], &tab[j], &counter_swap);
            i++;
        }
    }
    swap(&tab[i], &tab[r], &counter_swap);

    return i;
}