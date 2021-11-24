/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        O algoritmo gerara valores aleatorios entre 0 1000 e entre 0 e 10. Depois pegara cada valor da primeira geracao
    e dira os valores da segunda que sao divisores inteiros.


*/
#include <stdio.h>
#include <stdlib.h>
#define TAMANHOV1 10
#define TAMANHOV2 5
#define LIM_V1 1000
#define LIM_V2 10
#define MIN 100
#define MIN2 1

int main() {
    int vetor01[TAMANHOV1] = { 0 }; //Vetor de numeros entre 0 e 1000
    int vetor02[TAMANHOV2] = { 0 }; //Vetor de numeros entre 0 e 10
    int i = 0;
    int i2 = 0;
    int r = 0;
    int div = 0;
    srand(3);

    /*ADICAO DE VALORES NOS VETORES*/
    for(i = 0; i < TAMANHOV1; i++){//Vetor1
        vetor01[i] = (- MIN + (rand()%(LIM_V1 - MIN + 1)));
    } 
    for(i=0; i < TAMANHOV2; i++){//Vetor2
        vetor02[i] = (- MIN2 + (rand()%(LIM_V2 - MIN2 + 1)));
    }
    /*---------------//---------------*/

    
    /*EXIBINDO O VETOR 1*/
    printf("Vetor 1 [ ");
    for(i = 0; i < TAMANHOV1; i++){
        printf("%d ", vetor01[i]);
    }
    printf("]\n");

    /*EXIBINDO O VETOR 2*/
    printf("Vetor 2 [ ");
    for(i = 0; i < TAMANHOV2; i++){
        printf("%d ", vetor02[i]);
    }
    printf("]\n");
    /*---------------//---------------*/
    

    printf("\n");//Quebra de linha para melhor visualizacao
    

    //VERIFICACAO DOS DIVISORES
    for(i = 0, r = 0, i2 = 0; i < TAMANHOV1; i++){
        printf("Numero %d\n", vetor01[i]);//Exibe o numero que esta sendo analisado

        for(i2 = 0, r = 0; i2 < TAMANHOV2; i2++){

            div = vetor01[i] % vetor02[i2];//A variavel div ira guardar o resto da divisao
                                           //entre o numero analisado e os numeros do vetor2

            if(div == 0){//Caso tenha resto igual a zero, então o divisor e valido
                printf("Divisivel por %d na posicao %d\n", vetor02[i2], i2);
                r += 1; //r representa o numero de divisores para que, caso seja igual a zero,
                        //indicar que o numero nao possui divisores no vetor2
            }
        }
        if(r == 0){
            printf("Nao possui divisores no segundo vetor.\n");
        }
        printf("\n");
    }


    return 0;
}