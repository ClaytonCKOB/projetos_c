/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
       O algoritmo criará um retângulo com as coordenadas inseridas pelo usuário. Após a criação,
    o programa receberá mais um ponto e a partir dele indicará se ele está dentro, sobre ou fora do
    retângulo.
*/
#include <stdio.h>
#include <stdlib.h>

int isDataValid(int v1x, int v1y, int v2x, int v2y){ //Funcao valida a entrada dos dados.
    if(v1x < v2x && v1y < v2y){
        return 1;
    }else return 0;
}

int whoIsBigger(int a, int b){//Dados dois numeros, retorna o maior.
    if(a >= b){
        return a;
    }else return b;
}

int whoIsSmaller(int a, int b){ //Dados dois numeros, retorna o menor.
    if(a <= b){
        return a;
    }else return b;
}

int isOutside(int hMin, int hMax, int wMin, int wMax, int x, int y){//Verifica se o ponto esta fora do retangulo
    if (y < hMin || y > hMax){
        return 1;
    }
    else if(x < wMin || x > wMax){
        return 1;
    }
    else return 0;
}

int borda(int hMin, int hMax, int wMin, int wMax, int x, int y){//Verifica se o ponto esta sobre a borda do retangulos
    if(y == hMin || y == hMax || x == wMin || x == wMax){
        return 1;
    }else return 0;
}

char dentroRetangulo(int v1x, int v1y, int v2x, int v2y, int x, int y){//Funcao que indica em que posicao esta o ponto inserido
    int fora;
    int b;

    int hMin = whoIsSmaller(v1y, v2y);
    int hMax = whoIsBigger(v1y, v2y);
    int wMin = whoIsSmaller(v1x, v2x);;
    int wMax = whoIsBigger(v1x, v2x);;

    fora = isOutside(hMin, hMax, wMin, wMax, x, y);
    b = borda(hMin, hMax, wMin, wMax, x, y);

    if(fora == 1){
        return 'F';
    }
    else if(b == 1){
        return 'B';
    }
    else return 'D';

};

int main() {
    int v1x, v1y, v2x, v2y, x, y;
    int valid;
    char resultado;

    printf("=== Coordenadas do Retangulo ===\n");
    printf("Informe as coordenadas do canto inferior esquerdo: ");
    scanf("%d%d",&v1x, &v1y);

    do{
        printf("Informe as coordenadas do canto superior direito: ");
        scanf("%d%d",&v2x, &v2y);

        valid = isDataValid(v1x, v1y, v2x, v2y);
        
        if(valid != 1){
            printf("COORDENADAS INVALIDAS! Informe novamente\n");
        }
    }while(valid != 1);

    printf("=== PONTOS ===\n");

    do{
        printf("Informe as coordenadas (x, y): ");
        scanf("%d%d", &x, &y);
        resultado = dentroRetangulo(v1x, v1y, v2x, v2y, x, y);

        //POSICAO DO PONTO
        if(x != 9999){
            if(resultado == 'F'){

                printf("O ponto ( %d, %d) encontra-se fora do retangulo.\n", x, y);
            }else if(resultado == 'B'){
                printf("O ponto ( %d, %d) encontra-se sobre as bordas do retangulo.\n", x, y);
            }else{
                printf("O ponto ( %d, %d) encontra-se dentro do retangulo.\n", x, y);
            }
        }
    } while (x != 9999);
    
    return 0;
}