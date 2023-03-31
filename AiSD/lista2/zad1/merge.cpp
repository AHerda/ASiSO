#include <iostream>

void merge_sort(int n, int* tab);
void merge(int* into, int l, int* left,int r, int* right);

int main(int argc, char** argv) {
    std::cout << argv[8] << std::endl;
    int size = sizeof(argv) / sizeof(char);
    int tab[size];
    for(int i = 0; i < size; i++) {
        sscanf(argv[i], "%d", &(tab[i]));
    }
    std::cout << tab[8] << std::endl;
    merge_sort(size, tab);

    for(int i = 0; i < size; i++) {
        std::cout << tab[i] << ", ";
    }
}

void merge_sort(int n, int* tab) {
    if(n = 1)
        return;
    
    int i = (n - (n % 2)) / 2;
    int* left = tab;
    int* right = tab + (i * sizeof(int));
	merge_sort(i, left);
	merge_sort(n - i, right);


    merge(tab, i, left, n - i, right);
}

void merge(int* into, int l, int* left,int r, int* right) {
	int* result = new int(l + r);
	int li = 0, ri = 0;

	for(int i = 0; i < l + r; i++) {
		if(li == l) {
			result[i] = right[ri];
			ri++;
		}
		else if(ri == r) {
			result[i] = left[li];
			li++;
		}
		else {
			result[i] = (left[li] <= right[ri]) ? left[li++] : right[ri++];
		}
	}

    for(int i = 0; i < l + r; i++) {
        into[i] = result[i];
    }

    delete [] result;
}