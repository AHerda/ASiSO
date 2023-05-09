#include <climits>


int select_5(int tab[], int l, int r, int k, int partitions) {
    int n = r - l + 1;
    if (n == 1 && k == 0) return tab[0];

    int m = (n + partitions - 1) / partitions;
    int *medians = new int[m];

    for (int i = 0; i < m; i++) {
        if (partitions * i + partitions - 1 < n) {
            int *w = tab + partitions * i;

            for (int j0 = 0; j0 < partitions - 2; j0++) {
                int jmin = j0;
                for (int j = j0 + 1; j < partitions; j++) {
                    counter_if++;
                    if(w[j] < w[jmin]) jmin = j;
                }
                swap(&w[j0], &w[jmin], &counter_swap);
            }
            medians[i] = w[partitions / 2];
        }
        else {
            medians[i] = tab[partitions * i];
        }
    }

    int pivot = select_5(medians, 0, m - 1, m / 2, partitions);
    delete [] medians;

    for (int i = 0; i < n; i++) {
        counter_if++;
        if (tab[i] == pivot) {
            swap(&tab[i], &tab[n - 1], &counter_swap);
            break;
        }
    }

    int store = 0;
    for (int i = 0; i < n - 1; i++) {
        counter_if++;
        if (tab[i] < pivot) {
            swap(&tab[i], &tab[store++], &counter_swap);
        }
    }
    swap(&tab[store], &tab[n - 1], &counter_swap);

    if (store == k) {
        return pivot;
    }
    else if (store > k) {
        return select_5(tab, 0, store - 1, k, partitions);
    }
    else {
        return select_5(tab + store + 1, 0, n - store - 2, k - store - 1, partitions);
    }
}