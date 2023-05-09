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

    quick_sort(tab, 0, size_global - 1);

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


void quick_sort(int* tab, int l, int r, bool count) {
	if(r <= l) return;
	
	int i = l - 1;
	int j = r + 1;
	int pivot = select(tab, l, r, (r - l + 1) / 2);
	
	while(1) {
        counter_if++;
		while(pivot > tab[++i]) {
            counter_if++;
        }

        counter_if++;
		while(pivot < tab[--j]) {
            counter_if++;
        }
		
		if(i <=  j) {
            swap(&tab[i], &tab[j], (count) ? &counter_swap : nullptr);
        }
		else {
            break;
        }
	}

    if(size_global < 40) {
        print_tab(tab, r + 1, l);
    }
    
	
	if(j > l)
		quick_sort(tab, l, j, count);
	if(i < r)
		quick_sort(tab, i, r, count);
}

void quick_sort_old(int* tab, int lewy, int prawy) {
	if(prawy <= lewy) return;
	
	int i = lewy - 1;
	int j = prawy + 1;
	int pivot = tab[prawy];
	
	while(1) {
        counter_if++;
		while(pivot > tab[++i]) {
            counter_if++;
        }

        counter_if++;
		while(pivot < tab[--j]) {
            counter_if++;
        }
		
		if(i <=  j) {
            swap(&tab[i], &tab[j]);
        }
		else {
            break;
        }
	}
    
	
	if(j > lewy)
		quick_sort_old(tab, lewy, j);
	if(i < prawy)
		quick_sort_old(tab, i, prawy);
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