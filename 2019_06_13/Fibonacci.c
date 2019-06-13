#include <stdio.h>

int fibonacci(int n) {
   if (n == 0) return 0;
   if (n == 1) return 1;
   else return fibonacci (n - 1)+ fibonacci(n - 2);
}

int main(int argc, char** argv){
  printf("%d\n", fibonacci(3));
  printf("%d\n", fibonacci(4));
  printf("%d\n", fibonacci(5));
} 
