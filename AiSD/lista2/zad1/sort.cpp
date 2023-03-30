void insertion(int n, int* tab) {
	for(int i = 1; i < n; i++) {
		int key = tab[i];
		int j = i - 1;

		while(j > 0 && tab[j] > key) {
			tab[j + 1] = tab[j];
			j -= 1;
		}
		
		tab[j + 1] = key;
	}
}

int* merge(int l, int* left,int r, int* right) {
	int result[l + r];
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
			result[i] = (left[li] < right[ri]) ? left[li++] : right[ri++];
		}
	}

	return result;
}

void merge_sort(int n, int* tab){
    if(n = 1)
        return;
    
    int i = (n - (n % 2)) / 2;
    int* left = tab;
    int* right = tab + (i * sizeof(int));
	merge_sort(i, left);
	merge_sort(n - i, right);


    tab = merge(i, left, n - i, right);
}


void quick_sort(int n, int* tab);