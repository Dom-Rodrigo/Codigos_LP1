#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define RANGE 10


int clean_int(int arr[], int size);
float clean_float(float arr[], int size);

int show(int arr[], int size);
float show_float(float arr[], int size);
float random_fill(float arr[], int size, int range);
float max(float arr[], int size);
float average(float arr[], int size);
float *bubble_sort(float arr[], int size);
float median(float arr[], int size);
float std(float arr[], int size);
float *repeated_to_value(float arr[], int repeated_i[], int value, int size);
float remove_repeated(float arr[], int value, int size);
int sum(float arr[], int size,  int value);


float arr[N];
int repeated_i[N];
float repeated_frequency[RANGE];
float sorted_unique[N];

int main() {

  srand(time(NULL));

  // Cleaning the arrays
  clean_int(repeated_i, N);
  clean_float(arr, N);
  clean_float(repeated_frequency, RANGE);


  printf("\nARRAY ALEATÓRIO DE %d ELEMENTOS, DE 1 a %d: \n", N, RANGE);
  random_fill(arr, N, RANGE);
  show_float(arr, N);

  printf("VALOR MÁXIMO: %f\n", max(arr, N));
  printf("MÉDIA: %.2f\n", average(arr, N));
  float media = average(arr, N);
  printf("MEDIANA: %.2f\n", median(arr, N));
  printf("DESVIO PADRÃO: %.4f\n\n", std(arr, N));

  printf("Ordenando...\n");
  bubble_sort(arr, N);
  //repeated_to_zero(arr, repeated_i, N);
  //frequency(arr, N, RANGE);

  printf("ARRAY ORDENADO: \n");
  show_float(arr, N);

  printf("ARRAY COM O INDEXs DOS N. REPETIDOS (1 = valor repetido a ser removido): \n");
  show(repeated_i, N);

  printf("ARRAY TRANFORMADO OS VALORES REPETIDOS EM 0: (pode-se tranformar em qualquer numero) \n");
  repeated_to_value(arr, repeated_i, 0, N);
  show_float(arr, N);

  // printf("EXEMPLO TRANFORMADO OS VALORES REPETIDOS PRA MÉDIA: \n");
  // repeated_to_value(arr, repeated_i, media, N);
  // show(arr, N);


  printf("\nARRAY TENDO REMOVIDO OS N. REPETIDOS: \n");
  remove_repeated(arr, 0, N);

  return 0;
}

int clean_int(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = 0;
  }
  return 0;
}

float clean_float(float arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = 0;
  }
  return 0;
}
int show(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  printf("\n");

  return 0;
}

float show_float(float arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%.3f ", arr[i]);
  }
  printf("\n");
  printf("\n");

  return 0;
}

float random_fill(float arr[], int size, int range) {
  for (int i = 0; i < size; i++) {
    arr[i] = ((float) rand()/(float) RAND_MAX) * range;
  }
}

float max(float arr[], int size) {
  ""
  "Por enquanto só mostra o maior valor"
  "";
  float max = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  //printf("Max: %d \n", max);
  return max;
}

float average(float arr[], int size) {
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return (sum / size);
}

float *bubble_sort(float arr[], int size) {

  float sorted_arr[size];

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
      /** Se for maior, troca as posições. */
      sorted_arr[i] = arr[i + 1];
      sorted_arr[i + 1] = arr[i];
      swap += 1;
    }


    if (sorted_arr[i] == sorted_arr[i + 1]) {
      /* Se forem iguais, marque com 1 o index pra ser removido */
      repeated_i[i] = 1;
      repeated_i[i + 1] = 0;

    }
    else {
      /* Se forem diferentes, marque com 0, ou seja, não vai remover nenhum dos dois */
      repeated_i[i] = 0;
      repeated_i[i + 1] = 0;
    }




    for (int i = 0; i <= size - 1; i++) {
      /** Agora a arr a ser ordenada é aquela em que foram trocadas as
       * posições.*/
      arr[i] = sorted_arr[i];
    }

    i = i + 1;

    if (i == size - 1) {
      /** Faz o while funcionar o suficiente para ordenar o array. */
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

float median(float arr[], int size) {
  bubble_sort(arr, size);
  float a = arr[(size / 2) - 1];
  float b = arr[size / 2];
  if (size % 2 == 0) {
    return ((a + b) / 2);

  } else {
    return (b);
  }
}

float std(float arr[], int size) {
  float avg = average(arr, size);
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum += ((arr[i] - avg) * (arr[i] - avg)) / size;
  }
  return sum;
}

float *repeated_to_value(float arr[], int repeated_i[], int value, int size) {

  for (int i = 0; i < size; i++) {
    if (repeated_i[i] == 1) {
      arr[i] = value;
    }
  }
  return arr;
}

float remove_repeated(float arr[], int value, int size) {
  float new_array[size - sum(arr, size, value)];
  int ni = 0;
  for (int i = 0; i < size; i++){
    if (arr[i] != value) {
      new_array[ni] = arr[i];
      ni++;
    }
  }
  show_float(new_array, size - sum(arr, size, value));
}

int sum(float arr[], int size,  int value){
  int sum_repeated = 0;
  for (int i =0; i < size; i++){
    if (arr[i] == value){
      sum_repeated+=1;
    }
  }
  return sum_repeated;
}
