#include <iostream>
#include <string>


std::string quick_sort(int* tab, int lewy, int prawy) {
	if(prawy <= lewy) return std::to_string(prawy + 1 - lewy) + " " + std::to_string(counter_if) + " " + std::to_string(counter_swap) + "\n";
	
	int i = lewy - 1;
	int j = prawy + 1;
	int pivot = tab[(lewy + prawy) / 2];
	
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
            swap(&tab[i], &tab[j], counter_swap);
        }
		else {
            break;
        }
	}
	
	if(j > lewy)
		quick_sort(tab, lewy, j);
	if(i < prawy)
		quick_sort(tab, i, prawy);
    
    return std::to_string(prawy + 1 - lewy) + " " + std::to_string(counter_if) + " " + std::to_string(counter_swap) + "\n";
}