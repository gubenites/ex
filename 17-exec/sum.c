#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  if(argc < 2){
    printf("ERROR");
  }else{
    int counter = 0;

    for(int i = 0; i < argc ; i++){
      int foo = atoi(argv[i]);
      counter += foo;
      printf("Value: %d\n", counter);
    }

  }
}
