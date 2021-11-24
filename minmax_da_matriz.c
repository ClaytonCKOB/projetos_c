/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        Criar uma matriz 4x7 com valores aleatorios entre -10 e 10. Depois disso, indicar
    o MINMAX, que eh o maior valor na linha do menor valor
*/
#include <stdio.h>
#include <stdlib.h>

#define TAMANHOX 7 //Numero de colunas da matriz
#define TAMANHOY 4 //Numero de linhas da matriz

#define MAX 10  
#define MIN -10

int main() {
    int mat[TAMANHOY][TAMANHOX] = {0};
    int i;
    int r;
    int posx = 0;
    int posy = 0;

    srand(8);

//CRIACAO DA MATRIZ
    for(i = 0; i < TAMANHOY; i++){
        for(r = 0; r < TAMANHOX; r++){
            mat[i][r] = ((rand()%(MAX - MIN + 1) + MIN));
        }
    }

    int min = mat[0][0];
    int max = mat[0][0];

//EXIBINDO MATRIZ
    printf("Matriz: \n");
    for(i = 0; i < TAMANHOY; i++){
        for(r=0; r < TAMANHOX; r++){
            printf("%5.d", mat[i][r]);
        }
        printf("\n");
    }
//VALOR MINIMO
    for(i = 0; i < TAMANHOY; i++){
        for(r = 0; r < TAMANHOX; r++){ //Faz a comparacao de cada valor da matriz com a variavel min
            //Caso o elemento seja menor que "min", entao min torna-se o proprio elemento
            if(mat[i][r] < min){
                min = mat[i][r];
                posy = i; //Indica em qual linha esta o valor
            }
        }
    }
//VALOR MAXIMO
    for(r = 0; r < TAMANHOX; r++){
        //Se o elemento eh maior que "max", entao max torna-se o proprio elemento
        if(mat[posy][r] > max){
            max = mat[posy][r];
            posx = r; //indica a coluna do valor max
        }
    }

//OUTPUT
    printf("\n");
    printf("O elemento MINMAX eh %d. Ele esta em mat[%d][%d]\n", max, posy, posx);

    return 0;
}