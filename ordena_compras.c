/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        Busca simular o caixa de um mercado e fazer o ordenamento das compras.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM 21
#define TAMC 20
#define FIM "FIM"


typedef struct item{ //Estrutura que representa um item
    char produto[TAM];
    int quantProd;
    double valor;
} item_t;


typedef struct compra{ //Estrutura que representa a compra de uma pessoa
    char nome[TAM];
    double total;
    item_t compras[TAMC];
    int quantItens;
} compra_t;


void removeNewLine(char *string){ //Funcao que retira o '\n' de uma string
    string[strcspn(string, "\n")] = '\0';
}


void valorTotal(compra_t *pessoa){//Fara o calculto do valor total de uma compra
    double total = 0;
    double unidades;
    double valor;

    item_t *compras = pessoa->compras;

    for (int i = 0; i < pessoa->quantItens; i++){
        unidades = 0;
        unidades += (compras + i)->quantProd;
        valor = (compras + i)->valor;
        total += unidades * valor;
    }

    pessoa->total = total;
}

void makeCompra(compra_t *self){ //Funcao que estrutura uma compra
    int contagem = 0;
    int numItens = 0;
    item_t *p;

    printf("Informe o nome do cliente: ");
    fgets(self->nome, TAMC, stdin);
    removeNewLine(self->nome);

    printf("=== LISTA DE PRODUTOS ==\n");

    do{
        p = (self->compras + contagem);

        printf("Informe o nome produto: ");
        fgets(p->produto, TAMC, stdin);
        removeNewLine(p->produto);

        if ((strcmp(p->produto, FIM) != 0)){

            printf("Informe a quantidade de itens comprados: ");
            scanf("%d", &p->quantProd);
            getchar();

            printf("Informe o preco unitario do produto: ");
            scanf("%lf", &p->valor);
            getchar();

            printf("\n");

            if ((numItens + p->quantProd) > TAMC){
                p->quantProd = TAMC - numItens;
            }
            
            numItens += p->quantProd;
            contagem++;
        }
    } while (strcmp(p->produto, FIM) != 0 || numItens == TAMC);
    
    //Calculando valor total
    self->quantItens = contagem;
    valorTotal(self);

    printf("Itens comprados: %d\n", contagem);
    printf("Total: %.2f\n\n", self->total);
}

void sortByValue(compra_t *pessoas){ //Ordenamento a partir do valor total da compra
    compra_t aux;
    int valid = 1;
    while(valid != 0){
        valid = 0;
        for(int i = 0; i < 4; i++){
            aux = *(pessoas + i);
            if(aux.total < (pessoas + (i + 1))->total){
                *(pessoas + i) = *(pessoas + (i + 1));
                *(pessoas + (i + 1)) = aux;
                valid = 1;
            }
        }
    }

}

int valorLetra(char nome[TAM]){ //Atribui a cada letra um valor
    char aux = toupper(nome[0]);
    switch (aux){
        case 'A': return 1; break;
        case 'B': return 2; break;
        case 'C': return 3; break;
        case 'D': return 4; break;
        case 'E': return 5; break;
        case 'F': return 6; break;
        case 'G': return 7; break;
        case 'H': return 8; break;
        case 'I': return 9; break;
        case 'J': return 10; break;
        case 'K': return 11; break;
        case 'L': return 12; break;
        case 'M': return 13; break;
        case 'N': return 14; break;
        case 'O': return 15; break;
        case 'P': return 16; break;
        case 'Q': return 17; break;
        case 'R': return 18; break;
        case 'S': return 19; break;
        case 'T': return 20; break;
        case 'U': return 21; break;
        case 'V': return 22; break;
        case 'W': return 23; break;
        case 'X': return 24; break;
        case 'Y': return 25; break;
        case 'Z': return 26; break;
    }
}

void sortByName(compra_t *pessoas){//Ordenamento alfabetico
    compra_t aux;
    int valid = 1;
    while(valid != 0){
        valid = 0;
        for(int i = 0; i < 4; i++){
            aux = *(pessoas + i);
            if(valorLetra((pessoas + i)->nome) > valorLetra((pessoas + (i + 1))->nome)){
                *(pessoas + i) = *(pessoas + (i + 1));
                *(pessoas + (i + 1)) = aux;
                valid = 1;
            }
        }
    }
}

int main(){
    compra_t pessoas[5];
    char criterio;

    //Obtendo dados
    for (int i = 0; i < 5; i++){
        makeCompra((pessoas + i));
    }

    //Ordenando
    printf("Indique o criterio de ordenamento, Nome[N] ou Valor[V]: ");
    scanf("%c", &criterio);
    getchar();

    if(criterio == 'V'){
        sortByValue(pessoas);
    }else sortByName(pessoas);

    //Exibindo dados
    for (int i = 0; i < 5; i++){
        compra_t *a = (pessoas + i);

        printf("-----------------------------------------\n");
        printf("Cliente: %s\n",   (a->nome));
        printf("Total: R$%.2f\n", (a->total));
        printf("-----------------------------------------\n");

        for (int r = 0; r < a->quantItens; r++)
        {
            printf("ITEM %d ",                (r + 1));
            printf("Produto: %s ",            (a->compras + r)->produto);
            printf("Quantidade: %d ",         (a->compras + r)->quantProd);
            printf("Preco Unitario: %.2lf\n", (a->compras + r)->valor);
        }

        printf("-----------------------------------------\n");
    }

    return 0;
}