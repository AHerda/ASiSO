#include <iostream>

int size_global;
int counter_if = 0, counter_swap = 0;

void print_tab(int* tab, int size, int start = 0);
void quick_sort(int* tab, int lewy, int prawy);

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

    quick_sort(tab, 0, size_global - 1);

    if(size_global < 40) {
        print_tab(tab, size_global);
    }

    for(int i = 0; i + 1 < size_global; i++) {
        if(tab[i] > tab[i + 1]) return 0;
    }

    std::cout << std::endl << "n | # Prównań kluczy | # Podmian kluczy " << std::endl;
    std::cout << std::endl << size_global << " " << counter_if << " " << counter_swap << std::endl;

    return 1;
}


void print_tab(int* tab, int size, int start) {
    for (int i = start; i < size; i++)
        std::cout << tab[i] << " ";
    std::cout << std::endl;
}

void quick_sort(int* tab, int lewy, int prawy) {
	if(prawy <= lewy) return;
	
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
            int temp;
			temp = tab[j];
            tab[j] = tab[i];
            tab[i] = temp;

            counter_swap++;
        }
		else {
            break;
        }
	}

    if(size_global < 40) {
        print_tab(tab, prawy + 1, lewy);
    }
    
	
	if(j > lewy)
		quick_sort(tab, lewy, j);
	if(i < prawy)
		quick_sort(tab, i, prawy);
}
