#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main(){
  int num;
  char prog[] = "./sum";
  char *args[3];
  char num_send[20];
  do{
    scanf("%d", &num);

    if(fork() == 0){
      sprintf(num_send, "%d" , num);
      args[0] = prog;
      args[1] = num_send;
      args[2] = NULL;
      execvp(prog, args);
    }
  }
}
