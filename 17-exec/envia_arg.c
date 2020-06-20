#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main(){
  int num, ret_eh_par, st;
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
    }else {
      wait(&st);
      if (WIFEXITED(st)){
        ret_eh_par = (char) WEXITSTATUS(st);
        if (ret_eh_par == 0) {
          printf("É impar\n");
        } else if(ret_eh_par == 1){
          printf("É par\n");
        }
      }
    }
  } while (ret_eh_par != -1);

  return 0;
}
