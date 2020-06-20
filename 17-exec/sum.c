#include <unistd.h>
#include <stdio.h>


int main(int argc, char *argv[]){
  if(argc < 2){
    printf("ERROR");
    break;
  }else{
    int counter = 0;

    for(int i = 0; i < argc ; i++){
      int foo = atoi(argv[i]);
      counter += foo;
      printf("Value: %d", counter);
    }
    
  }
}
