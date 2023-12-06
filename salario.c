#include <stdio.h>

int main(void) {

  float salario_bruto, salario_liquido, vale, dependentes = 0;
  float salario_minimo = 1320;
  float desconto_inss, desconto_irrf, desconto_dependente = 0;
  float inss, irrf, inss_parcela, irrf_parcela = 0;

  printf("Salário: ");
  scanf("%f", &salario_bruto);

  printf("Vale alimentação: ");
  scanf("%f", &vale);

  printf("Número de dependentes: ");
  scanf("%f", &dependentes);

  /* Descontando Inss */
  if (salario_bruto < salario_minimo) {
     inss = 7.5;
     inss_parcela = 0;
  }
  else if (salario_bruto < 2571.29) {
    inss = 9.0;
    inss_parcela = 19.53;
  }
  else if (salario_bruto < 3856.94) {
    inss = 12.0;
    inss_parcela = 96.67;
  }
  else if (salario_bruto < 7507.49 | salario_bruto > 7507.49) {
    inss = 14.0;
    inss_parcela = 173.81;
  }

  desconto_inss = (salario_bruto * (inss/100)) - inss_parcela; // Desconto INSS
  desconto_dependente = dependentes * 189.59; // Desconto por dependente

  /* Descontando IRFF */
  if (salario_liquido < 2112.00) {
    irrf = 0;
    irrf_parcela = 0;
  }
  else if (salario_liquido > 2112.00 && salario_liquido <= 2826.65) {
    irrf = 7.5;
    irrf_parcela = 158.40;
  }
  else if (salario_liquido <= 3751.05) {
    irrf = 15.0;
    irrf_parcela = 370.40;
  }
  else if (salario_liquido <= 4664.68) {
    irrf = 22.5;
    irrf_parcela = 651.73;
  }
  else if (salario_liquido > 4664.68) {
    irrf = 27.5;
    irrf_parcela = 884.96;
  }

  desconto_irrf = ((salario_bruto - desconto_inss - desconto_dependente - vale) * (irrf/100)) - irrf_parcela;
  salario_liquido = salario_bruto - desconto_inss - desconto_irrf;
  if (salario_liquido > salario_minimo) {
    printf("Salário Líquido: R$%.2f\n", salario_liquido);
  }
  else {
    printf("Salário Líquido: R$1320");
  }
  return 0;
}
