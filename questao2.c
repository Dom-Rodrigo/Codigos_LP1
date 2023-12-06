#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define RANGE 10


int clean(int arr[], int size);
int show(int arr[], int size);
int random_fill(int arr[], int size, int range);
int max(int arr[], int size);
float average(int arr[], int size);
int *bubble_sort(int arr[], int size);
float median(int arr[], int size);
float std(int arr[], int size);
int *repeated_to_value(int arr[], int repeated_i[], int value, int size);
int frequency(int arr[], int size, int value,  int range);
int remove_repeated(int arr[], int value, int size);
int sum(int arr[], int size,  int value);

int arr[N];
int repeated_i[N];
int repeated_frequency[RANGE];
int sorted_unique[N];

int main() {

  srand(time(NULL));

  // Cleaning the arrays
  clean(repeated_i, N);
  clean(arr, N);
  clean(repeated_frequency, RANGE);


  printf("\nARRAY ALEATÓRIO DE %d ELEMENTOS, DE 1 a %d: \n", N, RANGE);
  random_fill(arr, N, RANGE);
  show(arr, N);

  printf("VALOR MÁXIMO: %d\n", max(arr, N));
  printf("MÉDIA: %.2f\n", average(arr, N));
  float media = average(arr, N);
  printf("MEDIANA: %.2f\n", median(arr, N));
  printf("DESVIO PADRÃO: %.4f\n\n", std(arr, N));

  printf("Ordenando...\n");
  bubble_sort(arr, N);
  //repeated_to_zero(arr, repeated_i, N);
  //frequency(arr, N, RANGE);

  printf("ARRAY ORDENADO: \n");
  show(arr, N);

  printf("ARRAY COM O INDEXs DOS N. REPETIDOS (1 = valor repetido a ser removido): \n");
  show(repeated_i, N);

  printf("ARRAY TRANFORMADO OS VALORES REPETIDOS EM 0: (pode-se tranformar em qualquer numero) \n");
  repeated_to_value(arr, repeated_i, 0, N);
  show(arr, N);

  // printf("EXEMPLO TRANFORMADO OS VALORES REPETIDOS PRA MÉDIA: \n");
  // repeated_to_value(arr, repeated_i, media, N);
  // show(arr, N);

  printf("FREQUÊNCIA DOS VALORES REPETIDOS: \n");
  frequency(arr, N, 0, RANGE);

  printf("\nARRAY TENDO REMOVIDO OS N. REPETIDOS: \n");
  remove_repeated(arr, 0, N);

  return 0;
}

int clean(int arr[], int size) {
  /**Limpa o array.*/
  for (int i = 0; i < size; i++) {
    arr[i] = 0;
  }
  return 0;
}

int show(int arr[], int size) {
  /**Mostra os números no array.*/
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  printf("\n");

  return 0;
}

int random_fill(int arr[], int size, int range) {
  /**Preenche o array com números aleatórios, dado um range para esses números.*/
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % range + 1;
  }
}

int max(int arr[], int size) {
  /**Retorna o maior valor número dentro do array.*/
  int max = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

float average(int arr[], int size) {
  /**Retorna a média dos valores.*/
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return (sum / size);
}

int *bubble_sort(int arr[], int size) {
  /**Algoritmo de bolha para sortear os números do array.*/

  int sorted_arr[size];

  for (int i = 0; i < size; i++) {
    sorted_arr[i] = arr[i];
    repeated_i[i] = 0;
  }

  int maior = arr[0];

  int c = 0;
  int i = 0;
  int swap = 0;
  while (i <= size - 1) {


    if (arr[i] > arr[i + 1]) {
      sorted_arr[i] = arr[i + 1];
      sorted_arr[i + 1] = arr[i];
      swap += 1;
    }


    if (sorted_arr[i] == sorted_arr[i + 1]) {
      repeated_i[i] = 1;
      repeated_i[i + 1] = 0;

    }
    else {
      repeated_i[i] = 0;
      repeated_i[i + 1] = 0;
    }




    for (int i = 0; i <= size - 1; i++) {
      arr[i] = sorted_arr[i];
    }

    i = i + 1;

    if (i == size - 1) {
      if (swap == 0) {
        break;
      } else {
        swap = 0;
      }
      i = 0;
      c++;

      if (c == size - 1) {
        break;
      }
    }
  }

  return arr;
}

float median(int arr[], int size) {
  /**Retorna a mediana dos números no array.*/
  bubble_sort(arr, size);
  float a = arr[(size / 2) - 1];
  float b = arr[size / 2];
  if (size % 2 == 0) {
    return ((a + b) / 2);

  } else {
    return (b);
  }
}

float std(int arr[], int size) {
  /**Retorna o desvio padrão dos números no array.*/
  float avg = average(arr, size);
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum += ((arr[i] - avg) * (arr[i] - avg)) / size;
  }
  return sum;
}

int *repeated_to_value(int arr[], int repeated_i[], int value, int size) {
  /**Tranforma os valores repetidos no array em um outro numero.*/
  for (int i = 0; i < size; i++) {
    if (repeated_i[i] == 1) {
      arr[i] = value;
    }
  }
  return arr;
}

int frequency(int arr[], int size, int value,  int range){
  /**Mostra a frequência de números repetidos no array.*/
  int zeros = 0;
  for (int i = 0; i < size; i++){
    if (arr[i] == value)
      zeros++;
    if (arr[i] != value){
      repeated_frequency[arr[i]] = zeros + 1;
      zeros = 0;
    }
  }
  //show(repeated_frequency, N);
  for (int i = 0; i < range+1; i++){
    //printf("%d\n", repeated_frequency[i]);
    if (repeated_frequency[i] != value){
      printf("%d: ", i);
      for (int j = 0; j < repeated_frequency[i]; j++){
        printf("#");
      }
      printf("\n");
    }
  }
}

int remove_repeated(int arr[], int value, int size) {
  /**Remove os números repetidos que foram transformados.*/
  int new_array[size - sum(arr, size, value)];
  int ni = 0;
  for (int i = 0; i < size; i++){
    if (arr[i] != value) {
      new_array[ni] = arr[i];
      ni++;
    }
  }
  show(new_array, size - sum(arr, size, value));
}

int sum(int arr[], int size,  int value){
  /**Retorna o total de valores repetidos.*/
  int sum_repeated = 0;
  for (int i =0; i < size; i++){
    if (arr[i] == value){
      sum_repeated+=1;
    }
  }
  return sum_repeated;
}
