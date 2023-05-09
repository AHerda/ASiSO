#include <climits>

int partition(int tab[], int l, int r);

int select(int tab[], int l, int r, int k) {
    if(k > 0 && k <= r - l + 1) {
        int i = partition(tab, l, r);

        if(i - l + 1 == k) {
            return tab[i];
        }
        else if(i - l + 1 > k) {
            return select(tab, l, i - 1, k);
        }
        else return select(tab, i + 1, r, k - i + l - 1);
    }
    return INT_MAX;
}

int partition(int tab[], int l, int r) {
    int pivot = tab[(r + l) / 2];
    int i = l;

    swap(&tab[r], &tab[(r + l) / 2], &counter_swap);

    for(int j = l; j <= r - 1; j++) {
        counter_if++;
        if(tab[j] <= pivot) {
            swap(&tab[i], &tab[j], &counter_swap);
            i++;
        }
    }
    swap(&tab[i], &tab[r], &counter_swap);
    return i;
}