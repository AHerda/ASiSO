#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	for(int i = 0; i < 16; i += 1) {
		printf("\x1B[38;5;%dmHello world!\x1B[0m\n", i);
	}
	return 0;
}
//tak terminal moze wyswietlic wiecej niz 256 kolorow
