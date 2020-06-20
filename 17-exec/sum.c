#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  if(argc < 2){
    return -1;
  }

  int num = atoi(argv[1]);

  if(num < 0) return -1;

  return !(num % 2);
}
