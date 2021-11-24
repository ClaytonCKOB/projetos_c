/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        Algoritmo busca criar um jogo baseado no jogo de azar "craps".
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 1
#define MAX 6

int jogadorVence(int soma, int jogada, int firstP){ //indicara se o jogador venceu
    if(jogada == 1){
        if(soma == 7 || soma == 11){
            return 1;
        }else return 0;
    }
    else if(soma == firstP){
        return 1;
    }else return 0;
}

int jogadorPerde(int soma, int jogada, int firstP){ // indicara se o jogador perdeu 
    if(jogada == 1){
        if(soma == 2 || soma == 3 || soma == 12){
            return 1;
        }else return 0;
    }
    else if(soma == 7){
        return 1;
    }else return 0;
}

int main() {
    int jogo = 1; //Indica se o jogo deve continuar ou nao.
    int d1, d2; //Dados
    int soma; //soma dos pontos
    int jogada = 1; //Indica em qual jogada esta
    int firstP; //Valor da primeira jogada
    srand(time(NULL));

    do{ //Loop do jogo
        d1 = (rand() % (MAX - MIN + 1) + MIN);
        d2 = (rand() % (MAX - MIN + 1) + MIN);
        soma = d1 + d2;

        if(jogada == 1){
            firstP = soma;
        }

        printf("O Jogador lancou %d + %d = %d\n", d1, d2, soma);

        if(jogadorVence(soma, jogada, firstP) == 1){    //Verifica se o jogador venceu
            printf("Jogador vence\n");
            jogo = 0;
        }
        else if(jogadorPerde(soma, jogada, firstP) == 1){ //Verifica se o jogador perdeu
            printf("Jogador perde\n");
            jogo = 0;
        }
        jogada++;
    }while(jogo != 0);

    return 0;
}