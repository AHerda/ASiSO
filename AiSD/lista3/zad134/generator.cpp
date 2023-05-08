#include <iostream>
#include <string.h>
#include <random>
#include <set>
#include <vector>
#include "utils.hpp"

std::mt19937 mt(std::random_device{}()); 


int main(int argc, char** argv) {
    if(argc != 3) return 0;

    int n;
    sscanf(argv[1], "%d", &n);
    
    std::vector<int> tab;
    if(strcmp(argv[2], "RANDOM") == 0) {
        generator_rand(&tab, n);
    }
    else if(strcmp(argv[2], "ASC") == 0) {
        generator_asc(&tab, n);
    }
    else if(strcmp(argv[2], "DESC") == 0) {
        generator_desc(&tab, n);
    }
    else {
        return 0;
    }
    std::cout << n << " ";
    print_tab(&tab, n);
    return 1;
}



void generator_rand(std::vector<int>* tab, int n) {
    for(int i = 0; i < n; i++) {
        tab->push_back(mt() % (2 * n));
    }
}

void generator_asc(std::vector<int>* tab, int n) {
    std::multiset<int> rand_asc;
    for(int i = 0; i < n; i++) {
        rand_asc.insert(mt() % (2 * n));
    }

    *tab = std::vector<int>(rand_asc.begin(), rand_asc.end());
}

void generator_desc(std::vector<int>* tab, int n) {
    std::multiset<int, std::greater<int>> rand_desc;
    for(int i = 0; i < n; i++) {
        rand_desc.insert(mt() % (2 * n));
    }
    
    *tab = std::vector<int>(rand_desc.begin(), rand_desc.end());
}

void generator_rand_tab(int* tab, int n) {
    for(int i = 0; i < n; i++) {
        tab[i] = mt() % (2 * n);
    }
}