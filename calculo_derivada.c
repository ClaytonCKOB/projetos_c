/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        O algoritmo tem o objetivo de calcular a derivada de um polinomio a partir da insercao dos coeficientes e do grau.
*/
#include <stdio.h>
#define TAM 10

int entreUmNove(int a){//Funcao que indica se o numero esta no intervalo [1, 9];
    if(a >= 1 && a <=9){
        return 1;
    }else return 0;
}

void deriva(double* poli, int grau, double* out){//Fara o calculo dos novos coeficientes
    for(int i = 0; i <= grau; i++){
        int temp = *(poli + i);
        int nCoefi = temp * (grau - i);
        *(out + i) = nCoefi;
    }
}

int main() {
    double coefi[TAM] = {0};     //Coeficientes do polinomio
    double newCoefi[TAM] = {0};   //Coeficientes do polinomio resultante
    int grau;                   //Grau do polinomio
    int valid = 0;

    double *poli = &coefi[0];   //Ponteiro do vetor de coeficientes
    double *out = &newCoefi[0]; //Ponteiro do vetor com os novos coeficientes

    //OBTENDO DADOS
    while(valid == 0){
        printf("Informe o grau do polinomio: ");
        scanf("%d", &grau);
        valid = entreUmNove(grau);
        if(valid == 0){
            printf("Valor invalido! Por favor informe um valor entre 1 e 9.\n");
        }
    }
    
    for(int i = 0; i <= grau; i++){
        printf("Informe o valor da componente x^%d: ", (grau - i));
        scanf("%lf", &coefi[i]);
    }
   
    //EXIBINDO POLINOMIO DE ENTRADA
    printf("Polinomio de entrada: ");
    for(int i = 0; i <= grau; i++){
        printf("%.2lfx^%d ", coefi[i], (grau - i));
        if((grau - i) != 0){
            printf("+ ");}
    }
    printf("\n");

    //DERIVADA
    deriva(poli, grau, out);

    printf("Derivada: ");
    for(int i = 0; i <= grau; i++){
        if(((grau - 1)- i) >= 0){
            printf("%.2lfx^%d ", newCoefi[i], ((grau - 1)- i));
            if(((grau - 1)- i) != 0){
                printf("+ ");}
        }
    }
    printf("\n");

    return 0;
}