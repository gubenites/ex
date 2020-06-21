#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int counter = 0;

void sig_handler(int num) {
    printf("Chamou Ctrl+C\n");

    counter += 1;
    if (counter == 3) {
      exit(-1);
    }
}

int main() {
    /* TODO: registre a função sig_handler
     * como handler do sinal SIGINT
     */
    printf("Meu pid: %d\n", getpid());
    signal(SIGINT, sig_handler);

    while(1) {

    }
    return 0;
}
