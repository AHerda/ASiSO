#ifndef sorts_hpp
#define sorts_hpp

#include <iostream>
#include <vector>
#include <string>

//all usage

int size_global;
int counter_if = 0, counter_swap = 0;


void print_tab(std::vector<int>* tab, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << (*tab)[i];
        if(i + 1 != size) {
            std::cout << " ";
        }
    }
}

void print_tab(int* tab, int size, int start = 0) {
    for (int i = start; i < size; i++)
        std::cout << tab[i] << " ";
    std::cout << std::endl;
}

void swap(int* a, int* b, int &counter_swap) {
    int temp = *a;
    *a = *b;
    *b = temp;

    counter_swap += 1;
}

//generator
void generator_rand(std::vector<int>* tab, int n);
void generator_asc(std::vector<int>* tab, int n);
void generator_desc(std::vector<int>* tab, int n);
void generator_rand_tab(int* tab, int n);

//insertion
std::string insertion_sort(int n, int* tab);

//merge
std::string merge_sort(int* tab, int const begin, int const end);
void merge(int* tab, int const left, int const mid, int const right);

//quick
std::string quick_sort(int* tab, int lewy, int prawy);

//dual_quick
std::string dual_pivot_quick_sort(int* tab, int low, int high);
void partition(int* tab, int low, int high, int* left_pivot, int* right_pivot);

//hybrid (quick => insertion)
std::string quick_sort_hybrid(int* tab, int lewy, int prawy);
void insertion_sort_hybrid(int n, int* tab);

#endif