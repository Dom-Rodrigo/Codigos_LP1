#include <stdio.h>

// Função recursiva
void towerOfHanoi(int n, char do_pino, char para_pino, char aux_pino)
{
    if (n == 1)
    {
        printf("\n Mova o disco 1 do pino %c para o pino %c", do_pino, para_pino);
        return;
    }
    towerOfHanoi(n-1, do_pino, aux_pino, para_pino);
    printf("\n Mova o disco %d do pino %c para o pino %c", n, do_pino, para_pino);
    towerOfHanoi(n-1, aux_pino, para_pino, do_pino);
}

int main()
{
    int n = 4; // Numero de discos
    towerOfHanoi(n, 'A', 'C', 'B'); // Nome dos pinos
    printf("\n");
    return 0;
}
