
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int a, b;
  char name[10];
  
  printf("What is your name?\n>");
  scanf("%s", &name);
  printf("Hello, %s\n", name);
  
  srand((unsigned int) time(NULL));
  a = rand() % 6 + 1;
  b = rand() % 6 + 1;

  printf("Rolling the dice...\n");
  printf("Die 1: %d\n", a);
  printf("Die 2: %d\n", b);
  printf("Total value: %d\n", a + b);
  return 0;

}
