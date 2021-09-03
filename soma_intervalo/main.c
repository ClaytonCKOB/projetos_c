/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 05 / EXERCÍCIO 05.a

    ALUNO: Clayton Kauã Oliveira Barcelos

    CONTRATO:

    is_primo: Number -> Number
    soma_intervalo: Number ... Number -> Number

    OBJETIVO DO PROGRAMA:
        Este programa fara a soma dos termos primos dentro de um intervalo 
        determinado pelo usuario.

    DOCUMENTACAO:
        Numeros primos sao divisiveis por eles mesmos e por um, logo sao dois
        divisores. Assim, e preciso fazer os seguintes passos:
        1 - descobrir o intervalo;
        2 - dentro deste intervalo, encontrar os numeros primos;
        3 - somar os numeros primos;
        4 - apresenta-los na tela;


*/
#include <stdio.h>

int is_primo(int z){//Funcao retornara o numero de divisores.
    int divisores = 0;
    int i = 1;

    for (i = 1, divisores=0; i <= z; i++)
    {
        if((z % i) == 0){
            divisores += 1;
        }
    }
    return divisores;
}

int soma_intervalo(int x, int y){
    int n = 0;
    int m = 0;
    int soma = 0;
    int i = 1;

    if(x > y){ //Condicional dira qual valor e maior
        n += x;
        m += y;
    }else{
        n += y;
        m += x;
    }

    for (i = m; i <= n; i++){//Loop varrera todos os numeros do intervalo

        if (is_primo(i) == 2){//Caso haja somente dois divisores, soma-se i.
            soma += i;
        }
    }

    return soma;
}

int main() {
    int x, y;

    do{
        printf("Informe os valores de x e y: \n");
        scanf("%d%d", &x, &y); //Armazenamento dos valores inseridos
        
        if(x < 0 || y < 0){ //Tratamento dos dados. Valores negativos nao sao aceitos.
            printf("Valores invalidos! Informe novamente...\n");
        }

    }while (x < 0 || y < 0);



    int soma = soma_intervalo(x, y);
    if(x > y){
        printf("A soma dos primos entre %d e %d e %d\n", y, x, soma);
    }
    else{
        printf("A soma dos primos entre %d e %d e %d\n", x, y, soma);
    }
    

    return 0;
}