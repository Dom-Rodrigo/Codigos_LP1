#include <stdio.h>
#include <math.h>

int main(){
  int i = 0;
  int n = 0;
  printf("N:");
  scanf("%d", &n);
  float pi = 4;
  float sum = 0;
  for(i; i<=n; i++){
    sum += pi * (pow(-1, i)/(2*i + 1));
  }
  printf("PI: %f\n", sum);
  return 0;
}
