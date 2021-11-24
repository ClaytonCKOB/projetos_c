/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        O algorítmo busca calcular o time vencedor após duas partidas.
    
    PASSOS:
    - Obter dados de entrada: GolI1, GolG1, GolI2, GolG2. Caso haja empate no final,
    será feita uma terceira partida, GolI3 e GolG3.
    - Devemos fazer a comparação de gols de cada partida.
    - Armazenar em cada variável determinada o valor de pontos.
    - Imprimir número de pontos e o resultado
*/
#include <stdio.h>
#include <stdlib.h>

//Funções
int calPontosInter(int gols_i, int gols_g){
    if(gols_i > gols_g){
        return 3;
    }
    else if(gols_i == gols_g){
        return 1;
    }
    else{
        return 0;
    }
}

int calPontosGremio(int gols_i, int gols_g){
    if(gols_i > gols_g){
        return 0;
    }
    else if(gols_i == gols_g){
        return 1;
    }
    else{
        return 3;
    }
}

int main() {
    int goli1, golg1, goli2, golg2, goli3, golg3;
    int pontos_i = 0;
    int pontos_g = 0;

    //Obtenção dos dados

    printf("Informe o número de gols do Internacional na primeira partida: \n");
    scanf("%d", &goli1);

    printf("Informe o número de gols do Grêmio na primeira partida: \n");
    scanf("%d", &golg1);

    printf("Informe o número de gols do Internacional na segunda partida: \n");
    scanf("%d", &goli2);

    printf("Informe o número de gols do Grêmio na segunda partida: \n");
    scanf("%d", &golg2);

    //Primeira rodada
    pontos_i += calPontosInter(goli1, golg1);
    pontos_g += calPontosGremio(goli1, golg1);

    //Segunda rodada
    pontos_i += calPontosInter(goli2, golg2);
    pontos_g += calPontosGremio(goli2, golg2);

    // Dados de saída
    printf("\n");  
    printf("Pontuação final:\n");
    printf("Internacional: %d pontos\n", pontos_i);
    printf("Grêmio: %d pontos\n", pontos_g);
    printf("\n");

    if(pontos_i == pontos_g){
        printf("Empate! Os dois times jogarão a partida final.\n");
        printf("Informe o número de gols do Internacional na terceira partida: \n");
        scanf("%d", &goli3);
    
        printf("Informe o número de gols do Grêmio na terceira partida: \n");
        scanf("%d", &golg3);
    
        //Terceira rodada
        pontos_i += calPontosInter(goli3, golg3);
        pontos_g += calPontosGremio(goli3, golg3);

    }

    if(pontos_i > pontos_g){
        printf("O vencedor é o INTERNACIONAL!\n");
    }
    else if(pontos_i < pontos_g){
        printf("O vencedor é o GRÊMIO!\n");
    }
    else{
        printf("Houve empate!\n");
    }
    return 0;
    } 