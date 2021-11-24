/*
    Made by CLAYTON KAUÃ OLIVEIRA BARCELOS

    O algorítmo tem como objetivo realizar o cálculo da ração restante
    sendo que há dois gatos que comem x e y gramas diárias de um saco 
    com z quilogramas em cinco dias.

    O cálculo iniciará com os dados de entrada:
    - x, y, z => valores numéricos inteiros.

    Posteriormente, será feita a soma de x e y e a multiplicação do re-
    sultado por cinco. Deverá ser feita também a conversão de gramas para
    quilogramas.

    Por fim, será feita a subtração de 5 - (x + y).

    *Acentos no corpo do código foram evitados
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    double x, y, z;

    printf("Quantas gramas o primeiro gato consome diariamente? \n");
    scanf("%lf", &x);

    printf("Quantas gramas o segundo gato consome diariamente? \n");
    scanf("%lf", &y);

    printf("Quantos quilogramas tem o saco da racao? \n");
    scanf("%lf", &z);

    double usoDiario = x + y;
    double consumoCinco = (5 * usoDiario) / 1000;
    double restante = z - consumoCinco;

    printf("Apos 5 dias restarao no saco %.1f kg de racao\n", restante);
    return 0;
}