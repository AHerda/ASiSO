#include <iostream>
#include <climits>
#include <random>
#include "utils.hpp"

std::mt19937 mt(std::random_device{}()); 

int main(int argc, char** argv) {
    int* tab;
    int k;

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
    }
    else {
        size_global = argc - 2;
        tab = new int[size_global];

        for(int i = 1; i < argc - 1; i++) {
            sscanf(argv[i], "%d", &(tab[i - 1]));
        }

        sscanf(argv[argc - 1], "%d", &k);
    }

    
    if(size_global <= 50) print_tab(tab, size_global);
    int x = rand_select(tab, 0, size_global - 1, k);
    if(size_global <= 50) {
        print_tab(tab, size_global);
        std::cout << x << std::endl;

        quick_sort(tab, 0, size_global - 1);
        print_tab(tab, size_global);

        std::cout << std::endl << "n | # Prównań kluczy | # Podmian kluczy " << std::endl;
    }
    std::cout << size_global << " " << counter_if << " " << counter_swap << std::endl;

    return 1;
}

int rand_select(int tab[], int l, int r, int k) {
    if(size_global <= 50) {
        print_tab(tab, r - l + 1, l);
    }

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
    std::cout << k << " większe niż tablica\n";
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