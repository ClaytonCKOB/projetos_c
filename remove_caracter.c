/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        O algoritmo recebera do usuario uma string e um caractere. Apos isso, ira retornar a string, porem sem o caractere
    apresentado
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO_S 100

int main() {
    char phrase[TAMANHO_S] = {""};
    char c;
    char new_phrase[TAMANHO_S] = {""};
    int i;

    printf("Informe uma string: \n"); //Recebendo a frase
    fgets(phrase, 100, stdin);

    printf("Informe o caracter a ser removido da string: \n"); //Recebendo o caracter que vai ser removido
    scanf("%c", &c);

    for(i = 0; i < TAMANHO_S; i++){//Fara a analise de cada caracter do texto informado
        char a = phrase[i];

        if(a != c && a != '\n'){//Comparativo com o caracter nao desejado
            strncat(new_phrase, &phrase[i], 1);//Atribuicao do caracter valido para a nova frase
        }
    }
    printf("A string original sem o caracter [%c] eh [%s] \n", c, new_phrase);

    return 0;
}