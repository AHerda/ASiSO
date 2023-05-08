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
    if(size_global <= 50) {
        print_tab(tab, r - l + 1, l);
    }

    if(k > 0 && k <= r - l + 1) {
        int i = partition_5(tab, l, r, partitions);

        if(i - l + 1 == k) {
            return tab[i];
        }
        else if(i - l + 1 > k) {
            return select(tab, l, i - 1, k, partitions);
        }
        else return select(tab, i + 1, r, k - i + l - 1, partitions);
    }
    std::cout << k << " większe niż tablica\n";
    return INT_MAX;
}

int partition_5(int tab[], int l, int r, int partitions) {
    int* pivot = find_median(tab, l, r, partitions);

    int i = l;

    for(int j = l; j < r; j++) {
        counter_if++;
        if(tab[j] <= *pivot) {
            swap(&tab[i], &tab[j], &counter_swap);
            i++;
        }
    }
    swap(&tab[i], &tab[r], &counter_swap);

    return i;
}

int* find_median(int tab[], int l, int r, int k) {
    int partitions = ((r - l + 1) % k) ? (r - l + 1) / k + 1 : (r - l + 1) / k;
    int* medians = new int[partitions];

    for(int i = 0; i < partitions; i++) {
        int len = (((r - l + 1) % k) && i + 1 == partitions) ? ((r - l + 1) % k) : k;
        int* temp = new int[len];
        for(int j = 0; j <= len; j++) {
            temp[j] = tab[i * k + l + j];
        }

        insertion_sort(temp, 0, len - 1);

        medians[i] = temp[len / 2];
    }

    select(medians, 0, partitions - 1, partitions / 2 + 1, k);
    return &medians[partitions / 2 + 1];
}

// Zapasowe implementacje

void insertion_sort(int tab[], int l, int r) {
	for(int i = 1; i <= r - l; i++) {
		int key = tab[i];
		int j = i - 1;

        counter_if++;
		while(j >= 0 && tab[j] > key) {
			tab[j + 1] = tab[j];
			j -= 1;

            counter_if++;
		}
		
		tab[j + 1] = key;
	}
}

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