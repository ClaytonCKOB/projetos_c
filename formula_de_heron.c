/*
    Made by Clayton Barcelos

    O algorítmo tem como objetivo realizar a fórmula de Heron, calculando a 
    área de um triângulo a partir de três argumentos (lados do triângulo).

    O cálculo será feito em duas etapas:
    - Primeiro é encontrado o valor do semi-período;
    - Segundo é feito o cálculo da área de fato;

    *Acentos no corpo do código foram evitados
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Variáveis para os dados de entrada

    double a, b, c;

    printf("Qual o valor do lado a? \n");
    scanf("%le", &a);

    printf("Qual o valor do lado b? \n");
    scanf("%le", &b);

    printf("Qual o valor do lado c? \n");
    scanf("%le", &c);

    //semi-período
    double s = (a + b + c)/2;
    
    //área do triângulo
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    
    printf("A area do triangulo e %f\n", area);
    return 0;
}