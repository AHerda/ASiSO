int bin_search(int tab[], int l, int r, int x) {
    if(r >= l) {
        int index = l + ((r - l) / 2);

        counter_if++;
        if(x == tab[index]) return 1;
        counter_if++;
        if(x < tab[index]) return bin_search(tab, l, index - 1, x);
        else return bin_search(tab, index + 1, r, x);
    }
    return 0;
}