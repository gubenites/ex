#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

int main() {
    pid_t filho;
    filho = fork();
    if (filho == 0) {
        printf("%d\n", getpid());
        return 5;
        while(1){

        }
    }
    sleep(10);
    int st;
    pid_t filho_acabou = waitpid(filho,&st,WHONANG);
    if (filho_acabou == 0) {
      kill(filho, SIGKILL);
      wait(&st);
    }

    if (WIFEXITED(st)) printf("return: %d\n", WEXITSTATUS(st));
    if (WIFSIGNALED(st)) printf("signal: %s\n", strsignal(WTERMSIG(st)));

    return 0;
}
