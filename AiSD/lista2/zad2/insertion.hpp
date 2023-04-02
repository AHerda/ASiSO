#include <iostream>
#include <string>

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
	}

    return std::to_string(n) + " " + std::to_string(counter_if) + " " + std::to_string(counter_swap) + "\n";
}
