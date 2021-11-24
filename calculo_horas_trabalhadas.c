/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        Busca imprimir na tela a quantidade de horas trabalhadas, alem de frizar as horas extras.
*/
#include <stdio.h>

int minutos_trabalhados(int h1, int m1, int h2, int m2){ //Calculara os minutos trabalhados
    //Conversao de horas para minutos
    int inicio = (h1 * 60) + m1;
    int fim = (h2 * 60) + m2;
    int total = fim - inicio;

    return total; 
}

int main() {
    //Variaveis que guardarao os valores totais
    int total_minutos = 0;
    int total_extra = 0;
    //Numero do funcionario
    int fun = 1;

    do{
        // "First turno horas entrada (fh1)"
        // As variaveis seguem o modelo:
        //   08   00   12   00
        int fh1, fm1, fh2, fm2;
        int sh1, sm1, sh2, sm2;

        printf("\n");
        printf("Funcionario %d\n", fun);
        printf("Informe o horario de entrada e saida do primeiro turno: \n");
        scanf("%d%d%d%d", &fh1, &fm1, &fh2, &fm2);
        printf("Informe o horario de entrada e saida do segundo turno: \n");
        scanf("%d%d%d%d", &sh1, &sm1, &sh2, &sm2);
        printf("\n");

        int min_trabalhados = minutos_trabalhados(fh1, fm1, fh2, fm2);
        min_trabalhados += minutos_trabalhados(sh1, sm1, sh2, sm2);

        total_minutos += min_trabalhados;

        if (min_trabalhados > 480){
            int min_adicionais = min_trabalhados - 480;
            total_extra += min_adicionais;

            printf("Total de minutos trabalhados pelo funcionario %d: %d minutos (%d minutos extras)\n", fun, min_trabalhados, min_adicionais);

            fun ++;
        }else{
            printf("Total de minutos trabalhados pelo funcionario %d: %d minutos \n", fun, min_trabalhados);
            fun ++;
        }
        
        
        
    }while(fun < 6); //Loop funcionara ate que o numero do funcionario alcance 6

    printf("\n");
    printf("TOTAL DE MINUTOS TRABALHADOS: %d minutos.\n", total_minutos);
    printf("MINUTOS EXTRAS QUE FORAM TRABALHADOS: %d minutos.\n", total_extra);
    return 0;
}