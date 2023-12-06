#include <stdio.h>
#include <math.h>

int main(){
  for (int m = 0; m <= 60; m++){
    for (int n = 0; n <= 60; n++){
      int a = pow(m, 2) - pow(n, 2);
      int b = 2 * m * n;
      int c = pow(m, 2) + pow(n, 2);
      if (((pow(a, 2) + pow(b, 2))== pow(c, 2)) && a > 0 && b > 0 && c >0){
        if (a <= 500 && b <= 500 && c<=500) {
          printf("(%d, %d, %d) é uma tripla pitagórica\n", a, b, c);
        }
      }
    }
  }

  return 0;
}
