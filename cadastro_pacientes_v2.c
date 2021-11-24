/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        Busca criar um sistema para controle dos cadastros de pacientes, podendo visualizar e alterar dados.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
#define PATH "pacientes.b"
#define INDEX "index.b"

typedef struct Paciente {
    char  nome[40];  /* nome do paciente */
    int   idade;     /* idade em anos */
    char  sexo;      /* sexo: (M)asculino ou (F)eminino */
    float altura;    /* altura do paciente (em metros) */
    int   peso;      /* peso (em kg) */
} t_paciente;

typedef struct Index{
    char nome[40];
    long posicao;
} t_index;

//DEFINICAO DE FUNCOES
void le_pacientes(t_paciente pacientes[TAM], int *n);
    /* Dados um vetor e um ponteiro, a funcao fara a leitura de um arquivo binario e 
    guardara os dados no vetor passado, alem de passar para o ponteiro o numero de 
    pacientes. */

void escreve_pacientes(t_paciente pacientes[TAM], int n);
    /* A funcao fara a escrita da relacao dos pacientes cadastrados*/

void acimaDoPeso(t_paciente pacientes[TAM], int n, t_paciente n_pacientes[TAM], int *num);
    /* Dentre uma lista de pacientes, a funcao selecionara somente os que estao 
    acima do peso.*/

void geraIndex();
    /* Funcao gerara um arquivo binario contendo as informacoes necessarias para localizar os pacientes*/

void atualizaPeso();
    /* Funcao que fara a atualizacao do peso de determinado paciente*/


//FUNCOES
void removeNewLine(char *string){ //Funcao que retira o '\n' de uma string
    string[strcspn(string, "\n")] = '\0';
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

void acimaDoPeso(t_paciente pacientes[TAM], int n, t_paciente n_pacientes[TAM], int *num){
    t_paciente *aux;
    t_paciente *nPac;
    int contagem = 0;

    for(int i = 0; i < n; i++){
        aux = (pacientes + i);
        nPac = (n_pacientes + contagem);

        float pesoIdealM = (72.7 * aux->altura) - 58; 
        float pesoIdealF = (62.1 * aux->altura) - 44.7; 


        if(aux->sexo == 'M'){
            if(aux->peso > pesoIdealM){
                *(n_pacientes + contagem) = *(pacientes + i);
                contagem++;
            }
        }

        else{
            if(aux->peso > pesoIdealF){
                *(n_pacientes + contagem) = *(pacientes + i);
                contagem++;
            }
        }
        *num = contagem;
    }
}

void geraIndex(){
    t_paciente aux;
    t_index aux0 = {0};

    FILE *pacientes = fopen(PATH, "r");
    FILE *index = fopen(INDEX, "w");

    fseek(pacientes, sizeof(int), SEEK_CUR);

    while (!feof(pacientes)){
        long posicao = ftell(pacientes);

        fread(&aux, sizeof(t_paciente), 1, pacientes);

        strcpy(aux0.nome, aux.nome);
        aux0.posicao = posicao;

        fwrite(&aux0, sizeof(t_index), 1, index);
    }

    fclose(pacientes);
    fclose(index);
}

void atualizaPeso(int n){
    t_index index;
    t_paciente aux0 = {0};

    int valid = 0;
    char nome[40] = {0};

    printf("Insira o nome do paciente: ");
    fgets(nome, 40, stdin);
    removeNewLine(nome);

    FILE *pacientes = fopen(PATH, "r+");
    FILE *Findex = fopen(INDEX, "r");

    if(pacientes == NULL || Findex == NULL){
        printf("Erro fatal na abertura dos arquivos.\n");
    }

    else{
        while(!feof(Findex) && valid == 0){
            fread(&index, sizeof(t_index), 1, Findex);
            if (strcmp(index.nome, nome) == 0){
                valid = 1;
            }
        }
        if(valid == 1){
            fseek(pacientes, index.posicao, SEEK_SET);
            fread(&aux0, sizeof(t_paciente), 1, pacientes);

            printf("Informe o novo peso do paciente %s: [Peso anterior %dKg] ", nome, aux0.peso);
            scanf("%d", &aux0.peso);
            getchar();

            fseek(pacientes, index.posicao, SEEK_SET);
            fwrite(&aux0, sizeof(t_paciente), 1, pacientes);

            printf("Peso atualizado com sucesso!\n");
        }
        else{
            printf("Paciente nao encontrado\n");
        }

    }
    
    fclose(pacientes);  
    fclose(Findex);
}

int main(){
    int action;
    t_paciente pacientes[TAM] = {0};
    t_paciente acimaPeso[TAM] = {0};
    int num;
    int *n = &num;

    do{
        //OPERACAO
        printf("Informe a operacao desejada: \n");
        printf("    [1] Atualizar o peso\n");
        printf("    [2] Listar pacientes acima do peso ideal\n");
        printf("    [3] Listar todos os pacientes\n");
        printf("    [4] Encerrar\n");
        printf("? ");
        scanf("%d", &action);
        getchar();

        switch (action){
        case 1: 
            geraIndex();
            atualizaPeso(num);
            break;

        case 2:
            le_pacientes(pacientes, n);
            acimaDoPeso(pacientes, *n, acimaPeso, n);
            escreve_pacientes(acimaPeso, *n);
            break;

        case 3:
            le_pacientes(pacientes, n);
            escreve_pacientes(pacientes, *n);
            break;
        }
    }while(action != 4);

    return 0;
}
