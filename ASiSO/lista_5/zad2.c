#include <stdio.h>
#include <signal.h>
#include <unistd.h>

struct sigaction siga;

void f(int sig) {
    printf("Caught signal %d\n", sig);
}

// sets f as handler to all the possible signals.
void myfunct(void(*f)(int sig)) {
    siga.sa_handler = f;
    for (int sig = 1; sig <= SIGRTMAX; ++sig) {
        // this might return -1 and set errno, but we don't care
        sigaction(sig, &siga, NULL);
    }
}

int main() {
    myfunct(f);
    pause(); // wait for signal
    return 0;
}