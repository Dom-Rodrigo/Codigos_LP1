#include <stdio.h>
#include <string.h>

#define X 30
#define Y 30


char matrix[X][Y];
char clean(char matrix[X][Y]);
char print_matrix(char matrix[X][Y]);
char fill_line(int x, int y, char word[], char number);
char fill_column(int x, int y, char word[], char number);

int main(){

  clean(matrix);

  int word_quantity = 7;
  char words[][Y] = {"HONDA", "PYTHON", "PORTUGAL", "ARISTOTELES", "BRASIL", "LOGICA", "CAFE"};
  int positions[][2] = {{21, 5}, {15, 9}, {15, 9}, {10, 13}, {10, 11}, {18, 13}, {17, 18}};


  fill_line(21, 5, "_____", '1');
  fill_line(15, 9, "______", '2');
  fill_column(15, 9, "________", '3');
  fill_column(10, 13, "___________", '4');
  fill_line(10, 11, "______", '5');
  fill_line(18, 13, "______", '6');
  fill_column(17, 18, "____", '7');


  print_matrix(matrix);
  printf("1. Marca de moto: \n");
  printf("2. Linguagem de programação famosa na ciência de dados: \n");
  printf("3. Nação fundada em 1143 d.C: \n");
  printf("4. Considerado o pai da palavra 6: \n");
  printf("5. País com mais católicos do mundo: \n");
  printf("6. Estuda os métodos e princípios de um raciocínio correto: \n");
  printf("7. Bebida, que não é água, mais consumida por programadores: \n");


  int item = 0;
  while (item != -1){
    printf("Digite um item e resposta: ");
    scanf("%d\n", &item);

    char word[Y];
    fgets(word, Y, stdin);
    word[strlen(word)-1] = 0; // REmove o \n do final da string

    if (strcmp(word, words[item-1]) == 0){
      printf("Certa resposta!");
      if (item == 1 || item == 2 || item == 5 || item == 6 ){
        fill_line(positions[item-1][0], positions[item-1][1], words[item-1], ' ');
      }
      else{
        fill_column(positions[item-1][0], positions[item-1][1], words[item-1], ' ');
      }
    }
    else {
      printf("Errou!");
    }
    print_matrix(matrix);
    printf("1. Marca de moto: \n");
    printf("2. Linguagem de programação famosa na ciência de dados: \n");
    printf("3. Nação fundada em 1143 d.C: \n");
    printf("4. Considerado o pai da palavra 6: \n");
    printf("5. País com mais católicos do mundo: \n");
    printf("6. Estuda os métodos e princípios de um raciocínio correto: \n");
    printf("7. Bebida, que não é água, mais consumida por programadores: \n");
  }



  return 0;
}

char clean(char matrix[X][Y]){
  /**Limpa a matriz que contem as palavras cruzadas.*/
  for (int i=0; i < X; i++){
    for (int j=0; j < Y; j++){
      matrix[i][j] = 32;
    }
  }
}

char print_matrix(char matrix[X][Y]){
  /**Mostra a matriz.*/

  for (int i=0; i < X; i++){
    for (int j=0; j < Y; j++){
      printf(" %c ", matrix[i][j]);
    }
    printf("\n");
  }
}

char fill_line(int x, int y, char word[], char number){
  /**Entra com a cordenada da primeira letra, completa o resto na linha a direita.*/
  matrix[x][y-2] = number;

  int p = 0;
  for (int i = y; i < (y + strlen(word)); i++){
    matrix[x][i] = word[p];
    p++;
  }
}

char fill_column(int x, int y, char word[], char number){

  /**Entra com a cordenada da primeira letra, completa na coluna para baixo.*/
  matrix[x-2][y] = number;

  int p = 0;
  for (int i = x; i < (x + strlen(word)); i++){
    matrix[i][y] = word[p];
    p++;
  }
}
