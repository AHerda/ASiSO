#include <random>
#include <set>
#include <vector>

std::mt19937 mt(std::random_device{}());


void generator_rand(std::vector<int>* tab, int n) {
    for(int i = 0; i < n; i++) {
        tab->push_back(mt() % (2 * n));
    }
}

void generator_asc(int tab[], int n) {
    std::multiset<int> rand_asc;
    for(int i = 0; i < n; i++) {
        rand_asc.insert(mt() % (2 * n));
    }

    std::vector<int> temp = std::vector<int>(rand_asc.begin(), rand_asc.end());
    for(int i = 0; i < n; i++) {
        tab[i] = temp[i];
    }
}

void generator_desc(int tab[], int n) {
    std::multiset<int, std::greater<int>> rand_desc;
    for(int i = 0; i < n; i++) {
        rand_desc.insert(mt() % (2 * n));
    }
    
    std::vector<int> temp = std::vector<int>(rand_desc.begin(), rand_desc.end());
    for(int i = 0; i < n; i++) {
        tab[i] = temp[i];
    }
}

void generator_rand_tab(int* tab, int n) {
    for(int i = 0; i < n; i++) {
        tab[i] = mt() % (2 * n);
    }
}