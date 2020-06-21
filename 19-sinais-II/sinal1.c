#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int counter = 0;

void sig_handler(int num) {
    printf("Chamou Ctrl+C\n");

    counter += 1;
    if (counter == 3) {
      exit(0);
    }
}

int main() {
    /* TODO: registre a função sig_handler
     * como handler do sinal SIGINT
     */
    printf("Meu pid: %d\n", getpid());
    struct sigaction s;
    s.sa_handler = sig_handler;
    sigemptyset(&s.sa_mask);
    s.sa_flags = 0;

    sigaction(SIGINT, &s, NULL);

    while(1) {
      sleep(1);
    }
    return 0;
}
