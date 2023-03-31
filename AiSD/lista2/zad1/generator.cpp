#include <iostream>
#include <string.h>
#include <random>
#include <set>
#include <vector>

std::mt19937 mt(std::random_device{}()); 

void print_tab(std::vector<int>* tab, int size);
void generator_rand(std::vector<int>* tab, int n);
void generator_asc(std::vector<int>* tab, int n);
void generator_desc(std::vector<int>* tab, int n);

int main(int argc, char** argv) {
    if(argc != 3) return 0;

    int n;
    sscanf(argv[1], "%d", &n);
    
    std::vector<int> tab;
    int sorted;
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

    print_tab(&tab, n);
    return 1;
}

void generator_rand(std::vector<int>* tab, int n) {
    for(int i = 0; i < n; i++) {
        tab->push_back(mt());
    }
}

void generator_asc(std::vector<int>* tab, int n) {
    std::multiset<int> rand_asc;
    for(int i = 0; i < n; i++) {
        rand_asc.insert(mt());
    }

    *tab = std::vector<int>(rand_asc.begin(), rand_asc.end());
}

void generator_desc(std::vector<int>* tab, int n) {
    std::multiset<int, std::greater<int>> rand_desc;
    for(int i = 0; i < n; i++) {
        rand_desc.insert(mt());
    }
    
    *tab = std::vector<int>(rand_desc.begin(), rand_desc.end());
}

void print_tab(std::vector<int>* tab, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << (*tab)[i];
        if(i + 1 != size) {
            std::cout << " ";
        }
    }
}