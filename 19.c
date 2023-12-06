#include <stdio.h>

int main(){
  float capital;
  float taxa; //anual
  int dias;

  while (capital != 0){
    printf("Entre com o valor do emprestimo (0 pra finalizar): ");
    scanf("%f", &capital);
    if (capital == 0) break;

    printf("Entre com a taxa de juros: ");
    scanf("%f", &taxa);
    if (taxa == 0) break;


    printf("Entre com o periodo do emprestimo (dias): ");
    scanf("%d", &dias);
    if (dias == 0) break;


    float juros = capital * taxa * dias/365;
    printf("O valor dos juros é: $%.2f\n", juros);
  }


  return 0;
}
