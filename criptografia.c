/*
    Made by Clayton Kaua Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        Busca criar um sistema para fazer a criptografia e descriptografia de um arquivo
*/

#include <stdio.h>
#include <string.h>

#define TAM   20
#define TAM_C 130
#define SAIDA "SAIDA.txt"

//Definicao de funcoes
void criptografia(char arquivo[TAM], int key, int action);
    /*Dados o nome do arquivo, chave que sera usada e a acao que deve ser realizada, a funcao fara a criptografia do arquivo.*/

//Funcoes
void criptografia(char arquivo[TAM], int key, int action){
    int i = 0;
    char conteudo[TAM_C] = {'\0'};

    FILE *arq = fopen(arquivo, "r+");
    FILE *file = fopen(SAIDA, "w");

    if(action == 2){
        key = -key;
    }

    if (arq && file){
        while (!feof(arq)){
            conteudo[i] = fgetc(arq);

            if(conteudo[i] != '\n'){
                conteudo[i] = conteudo[i] + key;
            }
            i++;
        }
    }

    else{
        printf("Nao foi possivel inicializar o arquivo.\n");
    }

    conteudo[strlen(conteudo) - 1] = '\0';

    fprintf(file, "%s", conteudo);
    fclose(file);
    fclose(arq);
}


int main(){
    char arquivo[TAM];
    int key;
    int action;

    //OBTENDO INFORMACOES
    printf("Informe o nome do arquivo texto: ");
    fgets(arquivo, 20, stdin);
    arquivo[strcspn(arquivo, "\n")] = '\0';

    printf("Informe a chave de criptografia: ");
    scanf("%d", &key);
    getchar();

    printf("O que deseja fazer com este arquivo? [1] - Criptografar [2] - Descriptografar ");
    scanf("%d", &action);

    criptografia(arquivo, key, action);

    printf("Operacao de criptografia concluida!\n");
}