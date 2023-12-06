#include <stdio.h>

int linha(int n);

int main(){

  int n = 0;
  printf("N:");
  scanf("%d", &n);

  linha(n);
  for (int i=0; i<n-2; i++){
    printf("#");
    for (int i=0; i<n-2; i++){
      printf(" ");
    }
    printf("#\n");
  }
  linha(n);

  return 0;
}

int linha(int n){
  for (int i=0; i<n; i++){
    printf("#");
  }
  printf("\n");
  return 0;
}
