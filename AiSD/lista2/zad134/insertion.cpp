#include <iostream>
#include <cstdlib>
#include <string>
#include "sorts.hpp"

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

    insertion_sort(size_global, tab);

    if(size_global < 40) {
        print_tab(tab, size_global);
    }

    if(size_global < 40) { std::cout << std::endl << "n | # Prównań kluczy | # Podmian kluczy " << std::endl; }
    std::cout << size_global << " " << counter_if << " " << counter_swap << std::endl;

    for(int i = 0; i + 1 < size_global; i++) {
        if(tab[i] > tab[i + 1]) return 0;
    }
    return 1;
}

std::string insertion_sort(int n, int* tab) {
	for(int i = 1; i < n; i++) {
		int key = tab[i];
		int j = i - 1;

        counter_if++;
		while(j >= 0 && tab[j] > key) {
			tab[j + 1] = tab[j];
			j -= 1;
            
            counter_swap++;
            counter_if++;
		}
		
		tab[j + 1] = key;
        
        if(n < 40) {
            print_tab(tab, n);
        }
	}

    return std::to_string(n) + " " + std::to_string(counter_if) + " " + std::to_string(counter_swap) + "\n";
}
