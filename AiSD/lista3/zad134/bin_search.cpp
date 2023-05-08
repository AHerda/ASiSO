#include <iostream>
#include <chrono>
#include "utils.hpp"


int main(int argc, char** argv) {
    int* tab;
    int x;

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

        sscanf(argv[1], "%d", &x);
    }
    else {
        size_global = argc - 2;
        tab = new int[size_global];

        for(int i = 1; i < argc - 1; i++) {
            sscanf(argv[i], "%d", &(tab[i - 1]));
        }

        sscanf(argv[argc - 1], "%d", &x);
    }

    auto start = std::chrono::high_resolution_clock::now();

    int result = bin_search(tab, 0, size_global - 1, x);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    if(size_global <= 50) {
        print_tab(tab, size_global);

        std::cout << "Czy znaleziono " << x << ": " << result << std::endl;

        std::cout << std::endl << "n | # Porównań kluczy | Czas wykonywania" << std::endl;
    }
    std::cout << size_global << " " << counter_if << " " << duration.count() << std::endl;

    return 1;
}

int bin_search(int tab[], int l, int r, int x) {
    if(r >= l) {
        int index = l + ((r - l) / 2);

        counter_if++;
        if(x == tab[index]) return 1;
        counter_if++;
        if(x < tab[index]) return bin_search(tab, l, index - 1, x);
        else return bin_search(tab, index + 1, r, x);
    }
    return 0;
}