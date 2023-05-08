#ifndef utils_hpp
#define utils_hpp

#include <iostream>
#include <vector>
#include <string>

// All usage

int size_global;
int counter_if = 0, counter_swap = 0;

void insertion_sort(int tab[], int l, int r);

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

void swap(int* a, int* b, int* counter_swap = nullptr) {
    int temp = *a;
    *a = *b;
    *b = temp;

    if(counter_swap) *counter_swap += 1;
}

// Generator
void generator_rand(std::vector<int>* tab, int n);
void generator_asc(std::vector<int>* tab, int n);
void generator_desc(std::vector<int>* tab, int n);
void generator_rand_tab(int* tab, int n);

// Zadanie 1
int select(int tab[], int l, int r, int k);
int partition(int tab[], int l, int r);

int rand_select(int tab[], int l, int r, int k);
int partition2(int tab[], int l, int r);

// Zadanie 3
int select(int tab[], int l, int r, int k, int partitions);
int partition_5(int tab[], int l, int r, int partitions);
int* find_median(int tab[], int l, int r, int k);

// Zadanie 4
int bin_search(int tab[], int l, int r, int x);

// Zadanie 5
void quick_sort(int* tab, int l, int r, bool count = false);
void quick_sort_old(int* tab, int lewy, int prawy);

void dual_pivot_quick_sort(int* tab, int low, int high);
void partition(int* tab, int low, int high, int* left_pivot, int* right_pivot);
void partition_old(int* tab, int low, int high, int* left_pivot, int* right_pivot);

#endif