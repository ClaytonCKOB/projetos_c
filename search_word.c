/*
    Made by Clayton Kaua Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        Fara a busca de uma palavra em um texto.
*/
#include <stdio.h>
#include <string.h>

#define TAM 15
#define TAM_T 300

int isHere(char *phrase, char *palavra){
    char aux[strlen(phrase)];
    strcpy(aux, phrase);
    char *p = strtok(aux, " ");
    while(p != NULL){
        if(strcmp(p, palavra) == 0){
            return 1;
        }

        p = strtok(NULL, " ");
    }

    return 0;
}

void searchWord(char arquivo[TAM], char word[TAM]){
    char texto[TAM_T] = {' '};
    int linha = 1;
    int ocorrencias = 0;

    FILE *text = fopen(arquivo, "r");

    while(fgets(texto, TAM_T, text)){
        if(isHere(texto, word) == 1){
            texto[strlen(texto) - 1] = '\0';
            printf("[LINHA %d] %s\n", linha, texto);
            ocorrencias++;
        }

        linha++;
    }

    printf("Foram encontradas %d ocorrencias de %s no arquivo %s\n", ocorrencias, word, arquivo);

    fclose(text);
}

int main(){
    char arquivo[TAM];
    char palavra[TAM];

    //OBTENDO INFORMACOES
    printf("Informe o nome do arquivo: ");
    fgets(arquivo, TAM, stdin);
    arquivo[strlen(arquivo) - 1] = '\0';

    printf("Informe a palavra a ser encontrada: ");
    fgets(palavra, TAM, stdin);
    palavra[strlen(palavra) - 1] = '\0';

    //EXIBINDO DADOS
    searchWord(arquivo, palavra);


    return 0;
}