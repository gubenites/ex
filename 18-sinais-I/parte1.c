#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <string.h>

int main() {
    if (fork() == 0) {
        printf("%d\n", getpid());
        while(1){

        }
    } else {
        int st;
        wait(&st);
        if (WIFEXITED(st)) printf("return: %d\n", WEXITSTATUS(st));
        if (WIFSIGNALED(st)) printf("signal: %s\n", strsignal(WTERMSIG(st)));
    }
}
