# include <stdio.h>

// Rodrigo Almeida Pirôpo, 02/10/2023 UESC-BA

int main() {

  unsigned short int idade = 0;
  char sexo;
  float altura, peso, IMC = 0;

  // Recebe os valores
  printf("SEXO (M para masculino e F para feminino): ");
  scanf("%c", &sexo);

  printf("IDADE: ");
  scanf("%hd", &idade);

  printf("ALTURA: ");
  scanf("%f", &altura);

  printf("PESO: ");
  scanf("%f", &peso);

  // Calcula o IMC
  IMC = (peso / (altura * altura));
  printf("Seu IMC é: %f\n", IMC);

  if (idade < 10)
    printf("O sistema não categoriza IMC de crianças menores de 10 anos. \n");

  // Análisa o IMC para adultos acima de 20 anos
  if (idade >= 20) {
    if (IMC <= 18.5) {
      printf("Abaixo do peso\n");
    }

    if (IMC >= 18.5 &&  IMC <= 24.9) {
      printf("Peso ideal\n");
    }

    if (IMC >= 25 &&  IMC <= 29.9) {
      printf("Peso moderado\n");
    }

    if (IMC >= 30 &&  IMC <= 34.9) {
      printf("Obesidade grau I\n");
    }
    if (IMC >= 35 && IMC <= 39.9) {
      printf("Obesidade grau II\n");
    }
    if (IMC >= 40) {
      printf("Obesidade grau III\n");
    }
  }

  // Analisa o IMC para mulheres de 10 a 19 anos
  // F <-> 70, f <-> 102
  if (sexo == 102 || sexo == 70) {
    if (idade == 10) {
      if (IMC < 14.23) {
        printf("Abaixo do peso\n");
      }
      if (IMC >= 14.23 && IMC < 20.19) {
        printf("Peso ideal\n");
      }
      if (IMC >= 20.19) {
        printf("Sobrepeso\n");
      }
    }
    if (idade == 11) {
      if (IMC < 14.60) {
        printf("Abaixo do peso\n");
      }
      if (IMC >= 14.20 && IMC < 21.18) {
        printf("Peso ideal\n");
      }
      if (IMC >= 21.18) {
        printf("Sobrepeso\n");
      }
    }
    if (idade == 12) {
      if (IMC < 14.98) {
        printf("Abaixo do peso\n");
      }
      if (IMC >= 14.98 && IMC < 22.17) {
        printf("Peso ideal\n");
      }
      if (IMC >= 22.17) {
        printf("Sobrepeso\n");
      }
    }
    if (idade == 13) {
      if (IMC < 15.36) {
        printf("Abaixo do peso\n");
      }
      if (IMC >= 15.36 && IMC < 23.08) {
        printf("Peso ideal\n");
      }
      if (IMC >= 23.08) {
        printf("Sobrepeso\n");
      }
    }
    if (idade == 14) {
      if (IMC < 15.67) {
        printf("Abaixo do peso\n");
      }
      if (IMC >= 15.67 && IMC < 23.88) {
        printf("Peso ideal\n");
      }
      if (IMC >= 23.88) {
        printf("Sobrepeso\n");
      }
    }
    if (idade == 15) {
      if (IMC < 16.01) {
        printf("Abaixo do peso\n");
      }
      if (IMC >= 16.01 && IMC < 24.29) {
        printf("Peso ideal\n");
      }
      if (IMC >= 24.29) {
        printf("Sobrepeso\n");
      }
    }
    if (idade == 16) {
      if (IMC < 16.37) {
        printf("Abaixo do peso\n");
      }
      if (IMC >= 16.37 && IMC < 24.74) {
        printf("Peso ideal\n");
      }
      if (IMC >= 24.74) {
        printf("Sobrepeso\n");
      }
    }
    if (idade == 17) {
      if (IMC < 16.59) {
        printf("Abaixo do peso\n");
      }
      if (IMC >= 16.59 && IMC < 25.23) {
        printf("Peso ideal\n");
      }
      if (IMC >= 25.23) {
        printf("Sobrepeso\n");
      }
    }
    if (idade == 18) {
      if (IMC < 16.71) {
        printf("Abaixo do peso\n");
      }
      if (IMC >= 16.71 && IMC < 25.56) {
        printf("Peso ideal\n");
      }
      if (IMC >= 25.56) {
        printf("Sobrepeso\n");
      }
    }
    if (idade == 19) {
      if (IMC < 16.87) {
        printf("Abaixo do peso\n");
      }
      if (IMC >= 16.87 && IMC < 26.85) {
        printf("Peso ideal\n");
      }
      if (IMC >= 25.85) {
        printf("Sobrepeso\n");
      }
    }
  }

    // ANalisa o IMC para homens de 10 a 19 anos
    // M <-> 77, m <-> 109
    if (sexo == 77 || sexo == 109) {
      if (idade == 10) {
        if (IMC < 14.42) {
          printf("Abaixo do peso\n");
        }
        if (IMC >= 14.42 && IMC < 19.60) {
          printf("Peso ideal\n");
        }
        if (IMC >= 19.60) {
          printf("Sobrepeso\n");
        }
      }
      if (idade == 11) {
        if (IMC < 14.83) {
          printf("Abaixo do peso\n");
        }
        if (IMC >= 14.83 && IMC < 20.35) {
          printf("Peso ideal\n");
        }
        if (IMC >= 20.35) {
          printf("Sobrepeso\n");
        }
      }
      if (idade == 12) {
        if (IMC < 15.24) {
          printf("Abaixo do peso\n");
        }
        if (IMC >= 15.24 && IMC < 21.12) {
          printf("Peso ideal\n");
        }
        if (IMC >= 21.12) {
          printf("Sobrepeso\n");
        }
      }
      if (idade == 13) {
        if (IMC < 15.73) {
          printf("Abaixo do peso\n");
        }
        if (IMC >= 15.73 && IMC < 21.93) {
          printf("Peso ideal\n");
        }
        if (IMC >= 21.93) {
          printf("Sobrepeso\n");
        }
      }
      if (idade == 14) {
        if (IMC < 16.18) {
          printf("Abaixo do peso\n");
        }
        if (IMC >= 16.18 && IMC < 22.77) {
          printf("Peso ideal\n");
        }
        if (IMC >= 22.77) {
          printf("Sobrepeso\n");
        }
      }
      if (idade == 15) {
        if (IMC < 16.59) {
          printf("Abaixo do peso\n");
        }
        if (IMC >= 16.59 && IMC < 23.63) {
          printf("Peso ideal\n");
        }
        if (IMC >= 23.63) {
          printf("Sobrepeso\n");
        }
      }
      if (idade == 16) {
        if (IMC < 17.01) {
          printf("Abaixo do peso\n");
        }
        if (IMC >= 17.01 && IMC < 24.45) {
          printf("Peso ideal\n");
        }
        if (IMC >= 24.45) {
          printf("Sobrepeso\n");
        }
      }
      if (idade == 17) {
        if (IMC < 17.31) {
          printf("Abaixo do peso\n");
        }
        if (IMC >= 17.31 && IMC < 25.28) {
          printf("Peso ideal\n");
        }
        if (IMC >= 25.28) {
          printf("Sobrepeso\n");
        }
      }
      if (idade == 18) {
        if (IMC < 17.54) {
          printf("Abaixo do peso\n");
        }
        if (IMC >= 17.54 && IMC < 25.95) {
          printf("Peso ideal\n");
        }
        if (IMC >= 25.95) {
          printf("Sobrepeso\n");
        }
      }
      if (idade == 19) {
        if (IMC < 17.80) {
          printf("Abaixo do peso\n");
        }
        if (IMC >= 17.80 && IMC < 26.36) {
          printf("Peso ideal\n");
        }
        if (IMC >= 26.36) {
          printf("Sobrepeso\n");
        }
      }
    }

  return 0;
}
