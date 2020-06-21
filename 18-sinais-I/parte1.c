#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

int main() {
    pid_t filho, pai;
    int st;
    struct timespec tim, tim2;
    tim.tv_nsec = 0;
    tim.tv_sec = 10;

    filho = fork();
    if (filho == 0) {
      pai = getppid();
      kill(getpid(), SIGINT);
    }else{
      wait(&st);
      if (WIFEXITED(st)) printf("return: %d\n", WEXITSTATUS(st));
      if (WIFSIGNALED(st)) printf("signal: %s\n", strsignal(WTERMSIG(st)));

      nanosleep(&tim, &tim2);
      kill(pai, SIGKILL);
    }
}
