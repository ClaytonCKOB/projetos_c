/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        Possibilitar ao usuário escolher dentre quatro operações, inserir valores e
        imprimir o resultado.
*/
#include <stdio.h>
#include <math.h>
#include <ctype.h>

void a_trapezio(int a, int b, int c){
    //Realizaremos o calculo da area de um trapezio


    double area = ((double)(a + b)/2) * c;
    printf("A area do trapezio de bases %d e %d, com altura %d eh: %.2lf\n", a, b, c, area);;
}

void bhaskara(int a, int b, int c){
    //Calculando a equacao do segundo grau

    //Calculo do delta
    double delta = pow(b, 2) -4*a*c;

    if (delta < 0){
        printf("Esta equacao nao possui raizes reais.\n");
    }

    else if(delta == 0){
        double x_1 = (-b + sqrt(delta))/(2*a); 
        printf("A equacao %d^2 + %dx + %d = 0 possui uma raiz: %.2lf\n", a, b, c, x_1);
    }
    else{
        double x_1 = (-b + sqrt(delta))/(2*a); 
        double x_2 = (-b - sqrt(delta))/(2*a);

        printf("A equacao %d^2 + %dx + %d = 0 possui duas raizes: %.2lf e %.2lf\n", a, b, c, x_1, x_2);
    }
}

void media_geo(int a, int b, int c){
    //Fara a media geometria dos valores inseridos
    double m = cbrt(a*b*c);
    printf("A media geometrica dos valores [%d, %d, %d] eh: %.2lf\n", a, b, c, m);
}

void intervalo(int a, int b, int c){
    //Fara algo semelhante a uma progressao aritmetica.
    double soma;
    int i = 0;

    for ( i = a, soma = 0; i < b; i += c)
    {
        soma += i;
    }

    printf("A soma de %d ate %d (de %d em %d) eh: %.2lf\n", a, b, c, c, soma);


}

int main() {
    int a, b, c;
    char i;

    printf("A - Area do trapezio\n");
    printf("B - Equação do segundo grau\n");
    printf("C - Media Geometrica\n");
    printf("D - Soma do Intervalo\n");
    printf("\n");
    printf("Informe o codigo i: \n");
    scanf("%c", &i);
    printf("Entre com os valores a, b e c: \n");
    scanf("%d%d%d", &a, &b, &c);

    i = toupper(i);

    if (a > b || a < 0 || b < 0 || c < 0){
        printf("Valores inconsistentes!\n");
    }
    else{
        switch (i)
        {
            case 'A':
                a_trapezio(a, b, c);
                break;

            case 'B':
                bhaskara(a, b, c);
                break;

            case 'C':
                media_geo(a, b, c);
                break;

            case 'D':
                intervalo(a, b, c);
                break;

            default:
                printf("O codigo informado eh invalido!\n");
                break;
        }
    }
    return 0;
}