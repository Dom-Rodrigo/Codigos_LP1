#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 10
#define Y 10

#define RANGE 100

int random_fill(int linhas, int colunas, int range);
int show(int linhas, int colunas);
int clean(int linhas, int colunas);
int uni_clean(int arr[], int size);
int bitoone(int arr[X][Y], int arr1[X*Y]);
int onetobi(int arr[X][Y], int arr1[X*Y]);
int *bubble_sort(int arr[], int size);
int somar_linhas(int arr[][Y], int linhas, int colunas);



int arr[X][Y];
int arr1[X*Y];

int main(){
  srand(time(NULL));
  clean(X, Y);
  random_fill(X, Y, RANGE);
  show(X, Y);
  printf("SOMA DAS LINHAS: \n");
  somar_linhas(arr, X, Y);
  bitoone(arr, arr1);
  bubble_sort(arr1, X*Y);
  onetobi(arr, arr1);
  show(X, Y);
  printf("SOMA DAS LINHAS: \n");
  somar_linhas(arr, X, Y);



  return 0;
}
int clean(int linhas, int colunas) {
  for (int i = 0; i < linhas; i++){
    for(int j=0; j < colunas; j++){
      arr[i][j] = 0;
    }
  }
  return 0;
}

int random_fill(int linhas, int colunas, int range) {
  for (int i = 0; i < linhas; i++){
    for(int j=0; j < colunas; j++){
      arr[i][j] = rand() % range + 1;
    }
  }
}

int show(int linhas, int colunas) {
  for (int i = 0; i < linhas; i++){
    for(int j=0; j < colunas; j++){
      printf("[%3d] ", arr[i][j]);
    }
    printf("\n");
  }
}

int bitoone(int arr[X][Y], int arr1[X*Y]){
  int a = 0;
  for (int i = 0; i < X; i++){
    for(int j=0; j < Y; j++){
      arr1[a] = arr[i][j];
      a++;
    }
  }
}

int onetobi(int arr[X][Y], int arr1[X*Y]){
  int a = 0;
  for (int i = 0; i < X; i++){
    for(int j=0; j < Y; j++){
      arr[i][j] = arr1[a];
      a++;
    }
  }
}

int *bubble_sort(int arr[], int size) {

  int sorted_arr[size];


  for (int i = 0; i < size; i++) {
    sorted_arr[i] = arr[i];
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

int somar_linhas(int arr[][Y], int linhas, int colunas){
  int soma_linhas[linhas];
  uni_clean(soma_linhas, linhas);
  for (int i = 0; i < linhas; i++){
    for(int j=0; j < colunas; j++){
      soma_linhas[i]+=arr[i][j];
    }
    printf("%d \n", soma_linhas[i]);
  }
  printf("\n");
}

int uni_clean(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = 0;
  }
  return 0;
}
