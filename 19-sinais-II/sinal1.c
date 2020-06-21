#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int status = 0;

void operacao_lenta() {
    sleep(10);
}

void sigint_handler(int num) {
  status += 1;
  printf("Chamou Ctrl+C; status=%d\n", status);
  operacao_lenta();
  printf("SIGINT: Vou usar status agora! status=%d\n", status);
}

void sigterm_handler(int num){
  status += 1;
  printf("Chamou SIGTERM; status=%d\n", status);
  operacao_lenta();
  printf("SIGTERM: Vou usar status agora! status=%d\n", status);
}

int main() {
    /* TODO: registre a função sig_handler
     * como handler do sinal SIGINT
     */
    struct sigaction s;
    printf("Meu pid: %d\n", getpid());
    s.sa_handler = sigint_handler;
    sigemptyset(&s.sa_mask);

    sigaddset(&s.sa_mask, SIGTERM);

    s.sa_flags = 0;
    sigaction(SIGINT, &s, NULL);


    /* TODO: registar SIGTERM aqui. */
    struct sigaction sigterm;
    sigterm.sa_handler = sigterm_handler;
    sigemptyset(&sigterm.sa_mask);

    sigaddset(&sigterm.sa_mask, SIGINT);

    sigterm.sa_flags = 0;
    sigaction(SIGTERM, &sigterm, NULL);

    while(1) {
      sleep(1);
    }
    return 0;
}
