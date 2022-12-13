#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
    fork();
    setuid(0);
    system("/bin/bash");
    return 0;
}