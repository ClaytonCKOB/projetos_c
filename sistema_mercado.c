/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        Busca simular o caixa de um mercado.
*/
#include <stdio.h>
#include <stdlib.h>
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

int main(){
    compra_t pessoas[5];

    //Obtendo dados
    for (int i = 0; i < 5; i++){
        makeCompra((pessoas + i));

    }

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