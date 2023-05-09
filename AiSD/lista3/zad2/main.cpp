#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include "utils.hpp"
#include "generator.hpp"
#include "select.hpp"
#include "rand_select.hpp"
#include "select_5.hpp"
#include "bin_search.hpp"
#include "quick.hpp"
#include "dual_quick.hpp"

int main(int argc, char** argv) {
    std::ofstream myfile;

    /*myfile.open("select.txt");
    for(int n = 100; n <= 10000; n += 100) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_rand_tab(tab, n);

            counter_if = 0; counter_swap = 0;
            select(tab, 0, n - 1, mt() % n + 1);

            myfile << n << " " << counter_if << " " << counter_swap << std::endl;
            delete [] tab;
        }
    }
    myfile.close();

    myfile.open("rand_select.txt");
    for(int n = 100; n <= 10000; n += 100) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_rand_tab(tab, n);

            counter_if = 0; counter_swap = 0;
            rand_select(tab, 0, n - 1, mt() % n + 1);

            myfile << n << " " << counter_if << " " << counter_swap << std::endl;
            delete [] tab;
        }
    }
    myfile.close();*/

    for(int j = 3; j <= 9; j += 2) {
        std::string filename = "select_5_" + std::to_string(j) + ".txt";

        myfile.open(filename);
        for(int n = 100; n <= 10000; n += 100) {
            for(int i = 0; i < 100; i++) {
                int* tab = new int[n];
                generator_rand_tab(tab, n);

                counter_if = 0; counter_swap = 0;
                int k = mt() % n;

                auto start = std::chrono::high_resolution_clock::now();
                select_5(tab, 0, n - 1, k, j);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                myfile << n << " " << counter_if << " " << counter_swap << " " << duration.count() << std::endl;
                delete [] tab;
            }
        }
        myfile.close();
    }

    /*myfile.open("bin_search_lewo.txt");
    for(int n = 1000; n <= 100000; n += 1000) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_asc(tab, n);

            counter_if = 0; counter_swap = 0;

            auto start = std::chrono::high_resolution_clock::now();
            bin_search(tab, 0, n - 1, 10);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

            myfile << n << " " << counter_if << " " << duration.count() << std::endl;
            delete [] tab;
        }
    }
    myfile.close();

    myfile.open("bin_search_srodek.txt");
    for(int n = 1000; n <= 100000; n += 1000) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_asc(tab, n);

            counter_if = 0; counter_swap = 0;

            auto start = std::chrono::high_resolution_clock::now();
            bin_search(tab, 0, n - 1, n - 20);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

            myfile << n << " " << counter_if << " " << duration.count() << std::endl;
            delete [] tab;
        }
    }
    myfile.close();

    myfile.open("bin_search_prawo.txt");
    for(int n = 1000; n <= 100000; n += 1000) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_asc(tab, n);

            counter_if = 0; counter_swap = 0;

            auto start = std::chrono::high_resolution_clock::now();
            bin_search(tab, 0, n - 1, 2 * n - 20);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

            myfile << n << " " << counter_if << " " << duration.count() << std::endl;
            delete [] tab;
        }
    }
    myfile.close();

    myfile.open("bin_search_rand.txt");
    for(int n = 1000; n <= 100000; n += 1000) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_asc(tab, n);

            counter_if = 0; counter_swap = 0;

            int x = mt() %  (2 * n);

            auto start = std::chrono::high_resolution_clock::now();
            bin_search(tab, 0, n - 1, x);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

            myfile << n << " " << counter_if << " " << duration.count() << std::endl;
            delete [] tab;
        }
    }
    myfile.close();

    myfile.open("quick_new.txt");
    for(int n = 100; n <= 10000; n += 100) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_desc(tab, n);

            counter_if = 0; counter_swap = 0;
            
            auto start = std::chrono::high_resolution_clock::now();
            quick_sort(tab, 0, n - 1);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

            myfile << n << " " << counter_if << " " << duration.count() << std::endl;
            delete [] tab;
        }
    }
    myfile.close();

    myfile.open("quick_old.txt");
    for(int n = 100; n <= 10000; n += 100) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_desc(tab, n);

            counter_if = 0; counter_swap = 0;
            
            auto start = std::chrono::high_resolution_clock::now();
            quick_sort_old(tab, 0, n - 1);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

            myfile << n << " " << counter_if << " " << duration.count() << std::endl;
            delete [] tab;
        }
    }
    myfile.close();

    myfile.open("dual_quick_new.txt");
    for(int n = 100; n <= 10000; n += 100) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_desc(tab, n);

            counter_if = 0; counter_swap = 0;
            
            auto start = std::chrono::high_resolution_clock::now();
            dual_pivot_quick_sort(tab, 0, n - 1);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

            myfile << n << " " << counter_if << " " << duration.count() << std::endl;
            delete [] tab;
        }
    }
    myfile.close();

    myfile.open("dual_quick_old.txt");
    for(int n = 100; n <= 10000; n += 100) {
        for(int i = 0; i < 100; i++) {
            int* tab = new int[n];
            generator_desc(tab, n);

            counter_if = 0; counter_swap = 0;
            
            auto start = std::chrono::high_resolution_clock::now();
            dual_pivot_quick_sort(tab, 0, n - 1, true);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

            myfile << n << " " << counter_if << " " << duration.count() << std::endl;
            delete [] tab;
        }
    }
    myfile.close();*/

    return 0;
}