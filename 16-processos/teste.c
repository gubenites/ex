#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/resource.h>

int main(){
  pid_t pai, filho;

  for(int i = 1 ; i <= 8 ; i++){
    filho = fork();

    if (filho == 0) {
      pai = getpid();

      printf("Eu sou o processo filho %d, meu pai é %d \n", filho,pai);
      break
    }else{
      wait(NULL);
    }
  }
  return 0;
}
