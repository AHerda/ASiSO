#include <iostream>
#include <climits>
#include <chrono>
#include "utils.hpp"


int main(int argc, char** argv) {
    int* tab;
    int k;
    int partitions;

    if(argc < 2) {
        return 0;
    }
    else if(argc == 2) {
        setbuf(stdin, NULL);
        scanf("%d", &size_global);

        tab = new int[size_global];

        for(int i = 0; i < size_global; i++) {
            scanf("%d", &(tab[i]));
        }

        sscanf(argv[1], "%d", &k);
        partitions = 5;

        k--;
    }
    else if(argc == 3) {
        setbuf(stdin, NULL);
        scanf("%d", &size_global);

        tab = new int[size_global];

        for(int i = 0; i < size_global; i++) {
            scanf("%d", &(tab[i]));
        }

        sscanf(argv[1], "%d", &k);
        sscanf(argv[2], "%d", &partitions);

        k--;
    }
    else {
        size_global = argc - 2;
        tab = new int[size_global];

        for(int i = 1; i < argc - 1; i++) {
            sscanf(argv[i], "%d", &(tab[i - 1]));
        }

        sscanf(argv[argc - 1], "%d", &k);
    }
    int x;
    if(size_global <= 50) print_tab(tab, size_global);

    auto start = std::chrono::high_resolution_clock::now();

    x = select(tab, 0, size_global - 1, k, partitions);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    if(size_global <= 50) {
        print_tab(tab, size_global);
        std::cout << x << std::endl;

        quick_sort(tab, 0, size_global - 1);
        print_tab(tab, size_global);

        std::cout << std::endl << "n | # Prównań kluczy | # Podmian kluczy | Czas wykonywania" << std::endl;
    }
    std::cout << size_global << " " << counter_if << " " << counter_swap << " " << duration.count() << std::endl;

    return 1;
}


int select(int tab[], int l, int r, int k, int partitions) {
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

    int pivot = select(medians, 0, m - 1, m / 2, partitions);
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
        return select(tab, 0, store - 1, k, partitions);
    }
    else {
        return select(tab + store + 1, 0, n - store - 2, k - store - 1, partitions);
    }
}

// Zapasowe implementacje

void quick_sort(int* tab, int lewy, int prawy, bool count) {
	if(prawy <= lewy) return;
	
	int i = lewy - 1;
	int j = prawy + 1;
	int pivot = tab[(lewy + prawy) / 2];
	
	while(1) {
		while(pivot > tab[++i]);

		while(pivot < tab[--j]);
		
		if(i <=  j) {
            swap(&tab[i], &tab[j]);
        }
		else {
            break;
        }
	}    
	
	if(j > lewy)
		quick_sort(tab, lewy, j);
	if(i < prawy)
		quick_sort(tab, i, prawy);
}