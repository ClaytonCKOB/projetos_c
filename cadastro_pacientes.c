/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        Busca criar um sistema para cadastro de pacientes, podendo salvar e expor os dados
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
#define PATH "pacientes.b"

typedef struct Paciente {
    char  nome[40];  /* nome do paciente */
    int   idade;     /* idade em anos */
    char  sexo;      /* sexo: (M)asculino ou (F)eminino */
    float altura;    /* altura do paciente (em metros) */
    int   peso;      /* peso (em kg) */
} t_paciente;


//DEFINICAO DE FUNCOES
void salva_pacientes(t_paciente pacientes[TAM], int n);
    /* Dados um vetor de pacientes e o numero de pacientes, a funcao salvara os dados 
    em um arquivo binario. */

void le_pacientes(t_paciente pacientes[TAM], int *n);
    /* Dados um vetor e um ponteiro, a funcao fara a leitura de um arquivo binario e 
    guardara os dados no vetor passado, alem de passar para o ponteiro o numero de 
    pacientes. */

void escreve_pacientes(t_paciente pacientes[TAM], int n);
    /* A funcao fara a escrita da relacao dos pacientes cadastrados*/


//FUNCOES
void removeNewLine(char *string){ //Funcao que retira o '\n' de uma string
    string[strcspn(string, "\n")] = '\0';
}

void salva_pacientes(t_paciente pacientes[TAM], int n){
    FILE *arquivo = fopen(PATH, "w");
    if(arquivo){
        fwrite(&n, sizeof(int), 1, arquivo);
        fwrite(pacientes, sizeof(t_paciente), n, arquivo);
        fclose(arquivo);
        arquivo = NULL;
    }
    else{
        printf("Erro com o arquivo [%s]\n", PATH);
    }
}

void le_pacientes(t_paciente pacientes[TAM], int *n){
    FILE *arquivo = fopen(PATH, "r");

    if(arquivo){
        fread(n, sizeof(int), 1, arquivo);
        fread(pacientes, sizeof(t_paciente), *n, arquivo);
        fclose(arquivo);
        arquivo = NULL;
    }
    else{
        printf("Erro com o arquivo [%s]\n", PATH);
    }

}

void escreve_pacientes(t_paciente pacientes[TAM], int n){
    printf("\nSalvei %d pacientes!\n", n);
    printf("-----------------------------------------------\n");
    printf("LISTA DE PACIENTES\n");
    printf("-----------------------------------------------\n");

    for(int i = 0; i < n; i++){
        printf("NOME    :%s\n", (pacientes + i)->nome);
        printf("IDADE   :%d\n", (pacientes + i)->idade);
        printf("SEXO    :%c\n", (pacientes + i)->sexo);
        printf("ALTURA  :%.2f\n", (pacientes + i)->altura);
        printf("PESO    :%d\n", (pacientes + i)->peso);
        printf("-----------------------------------------------\n");
    }
}


int main(){
    t_paciente pacientes[TAM] = {0};
    t_paciente l_pacientes[TAM] = {0};
    
    int n_pacientes;
    int valid = 1;
    int contagem = 0;

    int *n = &n_pacientes;

    //OBTENDO DADOS
    while(valid != 0 && contagem != 50){
        printf("INFORMACOES DO PACIENTE:\n");

        printf("    NOME: ");
        fgets((pacientes + contagem)->nome, 40, stdin);
        removeNewLine((pacientes + contagem)->nome);

        printf("    IDADE: ");
        scanf("%d", &(pacientes + contagem)->idade);
        getchar();

        printf("    SEXO: ");
        scanf("%c", &(pacientes + contagem)->sexo);
        getchar();

        printf("    ALTURA: ");
        scanf("%f", &(pacientes + contagem)->altura);
        getchar();

        printf("    PESO: ");
        scanf("%d", &(pacientes + contagem)->peso);
        getchar();

        contagem++;

        printf("Deseja cadastrar outro paciente? [0] NAO [1] SIM  ");
        scanf("%d", &valid);
        getchar();

    }

    //SALVANDO OS DADOS
    salva_pacientes(pacientes, contagem);

    //LEITURA DOS DADOS
    le_pacientes(l_pacientes, n);

    //EXIBINDO DADOS
    escreve_pacientes(l_pacientes, *n);
}