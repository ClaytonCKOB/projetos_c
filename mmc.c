/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 05 / EXERCÍCIO 05.b

    ALUNO: Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        O algoritmo armazenara dois valores e, a partir deles, fara o MMC.
*/
#include <stdio.h>

// mmc: Number ... Number -> String

void mmc(int x, int y){//Fara o mmc pelo metodo da fatoracao
    int num1 = x;
    int num2 = y;
    int multi = 1; 
    int i = 2;

    do{    
        if(num1 % i == 0 && num2 % i == 0){ //Caso ambos sejam divisiveis, dividi-los e armazenar os novos valores
            printf("%4d%4d | %d\n", num1, num2, i);
            num1 = num1 / i;
            num2 = num2 / i;
            multi = multi * i;
        }

        else if(num1 % i == 0 && num2 % i != 0){ // Caso somente um seja divisivel, alterar o valor de somente uma variavel
            printf("%4d%4d | %d\n", num1, num2, i);
            num1 = num1 / i;
            multi = multi * i;
        }

        else if(num1 % i != 0 && num2 % i == 0){
            printf("%4d%4d | %d\n", num1, num2, i);
            num2 = num2 / i;
            multi = multi * i;
        }

        if(num1 % i != 0 && num2 % i != 0){ //Caso nenhum dos dois sejam divisiveis por i, entao realizar i += 1.
            if(x != 1 && y != 1){
                i += 1;
            }
        }

    }while (num1 != 1 || num2 != 1);
    
    printf("   1   1 |\n");
    printf("\n");
    printf("MMC: %d\n", multi);
}

int main() {
    int x = 0;
    int y = 0;

    do{ //Verifica os valores inseridos
        printf("Informe os dois numeros: \n");
        scanf("%d%d", &x, &y);
        if(x < 0 || y < 0){
            printf("Valores invalidos! Informe novamente...");
        }
        printf("\n");
    }while (x < 0 || y < 0);

    mmc(x, y);

    return 0;
}