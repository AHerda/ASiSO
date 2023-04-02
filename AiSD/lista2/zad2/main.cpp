#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "sorts2.hpp"
#include "insertion.hpp"
#include "quick.hpp"
#include "merge.hpp"
#include "dual_quick.hpp"
#include "hybrid.hpp"


std::mt19937 mt(std::random_device{}());

void generator_rand_tab(int* tab, int n) {
    for(int i = 0; i < n; i++) {
        tab[i] = mt() % (2 * n);
    }
}

int main(int argc, char** argv) {
    std::ofstream myfile;

    myfile.open("insertion.txt");
    for(int n = 10; n <= 200; n += 10) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_rand_tab(tab, n);

            counter_if = 0; counter_swap = 0;
            std::string result = insertion_sort(n, tab);

            myfile << result;
            delete [] tab;
        }
    }
    myfile.close();

    myfile.open("merge.txt");
    for(int n = 10; n <= 200; n += 10) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_rand_tab(tab, n);

            counter_if = 0; counter_swap = 0;
            std::string result = merge_sort(tab, 0, n - 1);

            myfile << result;
            delete [] tab;
        }
    }

    for(int n = 1000; n <= 20000; n += 1000) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_rand_tab(tab, n);

            counter_if = 0; counter_swap = 0;
            std::string result = merge_sort(tab, 0, n - 1);

            myfile << result;
            delete [] tab;
        }
    }
    myfile.close();

    myfile.open("quick.txt");
    for(int n = 10; n <= 200; n += 10) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_rand_tab(tab, n);

            counter_if = 0; counter_swap = 0;
            std::string result = quick_sort(tab, 0, n - 1);

            myfile << result;
            delete [] tab;
        }
    }

    for(int n = 1000; n <= 20000; n += 1000) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_rand_tab(tab, n);

            counter_if = 0; counter_swap = 0;
            std::string result = quick_sort(tab, 0, n - 1);

            myfile << result;
            delete [] tab;
        }
    }
    myfile.close();

    myfile.open("dual_quick.txt");
    for(int n = 10; n <= 200; n += 10) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_rand_tab(tab, n);

            counter_if = 0; counter_swap = 0;
            std::string result = dual_pivot_quick_sort(tab, 0, n - 1);

            myfile << result;
            delete [] tab;
        }
    }

    for(int n = 1000; n <= 20000; n += 1000) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_rand_tab(tab, n);

            counter_if = 0; counter_swap = 0;
            std::string result = dual_pivot_quick_sort(tab, 0, n - 1);

            myfile << result;
            delete [] tab;
        }
    }
    myfile.close();

    myfile.open("hybrid.txt");
    for(int n = 10; n <= 200; n += 10) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_rand_tab(tab, n);

            counter_if = 0; counter_swap = 0;
            std::string result = quick_sort_hybrid(tab, 0, n - 1);

            myfile << result;
            delete [] tab;
        }
    }

    for(int n = 1000; n <= 20000; n += 1000) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_rand_tab(tab, n);

            counter_if = 0; counter_swap = 0;
            std::string result = quick_sort_hybrid(tab, 0, n - 1);

            myfile << result;
            delete [] tab;
        }
    }
    myfile.close();

    return 0;
}