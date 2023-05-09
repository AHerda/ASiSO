#include <climits>

int select_quick(int tab[], int l, int r, int k);
int partition_quick(int tab[], int l, int r);

void quick_sort(int* tab, int l, int r) {
	if(r <= l) return;
	
	int i = l - 1;
	int j = r + 1;
	int pivot = select(tab, l, r, (r - l + 1) / 2);
	
	while(1) {
        counter_if++;
		while(pivot > tab[++i]) {
            counter_if++;
        }

        counter_if++;
		while(pivot < tab[--j]) {
            counter_if++;
        }
		
		if(i <=  j) {
            swap(&tab[i], &tab[j]);
        }
		else {
            break;
        }
	}
    
	
	if(j > l)
		quick_sort(tab, l, j);
	if(i < r)
		quick_sort(tab, i, r);
}

void quick_sort_old(int* tab, int lewy, int prawy) {
	if(prawy <= lewy) return;
	
	int i = lewy - 1;
	int j = prawy + 1;
	int pivot = tab[prawy];
	
	while(1) {
        counter_if++;
		while(pivot > tab[++i]) {
            counter_if++;
        }

        counter_if++;
		while(pivot < tab[--j]) {
            counter_if++;
        }
		
		if(i <=  j) {
            swap(&tab[i], &tab[j]);
        }
		else {
            break;
        }
	}
    
	
	if(j > lewy)
		quick_sort_old(tab, lewy, j);
	if(i < prawy)
		quick_sort_old(tab, i, prawy);
}


// Zapasowe implementacje 

int select_quick(int tab[], int l, int r, int k) {
    if(k > 0 && k <= r - l + 1) {
        int i = partition(tab, l, r);

        if(i - l + 1 == k) {
            return tab[i];
        }
        if(i - l + 1 > k) {
            return select(tab, l, i - 1, k);
        }
        return select(tab, i + 1, r, k - i + l - 1);
    }
    return INT_MAX;
}

int partition_quick(int tab[], int l, int r) {
    int pivot = tab[(r + l) / 2];
    int i = l;

    for(int j = l; j <= r - 1; j++) {
        counter_if++;
        if(tab[j] <= pivot) {
            swap(&tab[i], &tab[j]);
            i++;
        }
    }
    swap(&tab[i], &tab[r]);
    return i;
}