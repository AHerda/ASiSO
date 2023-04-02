#include <iostream>
#include <vector>

//all us
void print_tab(std::vector<int>* tab, int size);
void print_tab(int* tab, int size, int start = 0);
void swap(int* a, int* b);

//generator
void generator_rand(std::vector<int>* tab, int n);
void generator_asc(std::vector<int>* tab, int n);
void generator_desc(std::vector<int>* tab, int n);

//insertion
void insertion_sort(int n, int* tab);

//merge
void merge_sort(int* tab, int const begin, int const end);
void merge(int* tab, int const left, int const mid, int const right);

//quick
void quick_sort(int* tab, int lewy, int prawy);

//dual_quick
void swap2(int* A, int i, int j);
void dual_pivot_quick_sort(int* tab, int low, int high);
void partition(int* tab, int low, int high, int* left_pivot, int* right_pivot);
void sort(int* A, int left, int right);