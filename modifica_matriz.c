/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        O algoritmo ira criar uma matriz 10x10 com valores aleatorios e depois disso fara trocas entre
        linhas e colunas.
        Primeira troca: linha 2 com a linha 8;
        Segunda troca: coluna 4 com a coluna 10;
        Terceira troca: diagonal principal com a diagonal secundaria;
        Quarta troca: linha 5 com a coluna 10; 
*/
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define MIN 10
#define MAX 99

int main()
{
    int matriz_ori[TAMANHO][TAMANHO] = {0}; //Matriz original
    int i;                                  //Variaveis para contagem
    int r;
    int a = 0;
    int b = 0;

    //CRIACAO DA MATRIZ ORIGINAL
    for (i = 0; i < TAMANHO; i++)
    {

        for (r = 0; r < TAMANHO; r++)
        { //Preenchimento de cada elemento da linha i
            matriz_ori[i][r] = ((rand() % (MAX - MIN + 1) + MIN));
        }
    }

    //EXIBINDO MATRIZ ORIGINAL
    printf("Matriz original: \n");

    for (i = 0; i < TAMANHO; i++)
    {
        for (r = 0; r < TAMANHO; r++)
        {
            printf("%4.d ", matriz_ori[i][r]);
        }
        printf("\n");
    }

    //TROCANDO A LINHA 2 PELA LINHA 8
    for (i = 0; i < TAMANHO; i++)
    {
        a = matriz_ori[1][i];
        b = matriz_ori[7][i];

        matriz_ori[1][i] = b;
        matriz_ori[7][i] = a;
    }

    //TROCANDO A COLUNA 4 COM A COLUNA 10
    for (i = 0; i < TAMANHO; i++)
    {
        a = matriz_ori[i][3];
        b = matriz_ori[i][9];

        matriz_ori[i][3] = b;
        matriz_ori[i][9] = a;
    }

    //TROCANDO A DIAGONAL PRINCIPAL PELA SECUNDARIA
    for (i = 0; i < TAMANHO; i++)
    {
        a = matriz_ori[i][i];
        b = matriz_ori[i][9 - i];

        matriz_ori[i][9 - i] = a;
        matriz_ori[i][i] = b;
    }

    //TROCANDO LINHA 5 COM A COLUNA 10
    for (i = 0; i < TAMANHO; i++)
    {
        a = matriz_ori[4][i];
        b = matriz_ori[i][9];

        matriz_ori[i][9] = a;
        matriz_ori[4][i] = b;
    }

    //EXIBINDO MATRIZ RESULTANTE
    printf("Matriz resultante: \n");

    for (i = 0; i < TAMANHO; i++)
    {
        for (r = 0; r < TAMANHO; r++)
        {
            printf("%4.d ", matriz_ori[i][r]);
        }
        printf("\n");
    }

    return 0;
}