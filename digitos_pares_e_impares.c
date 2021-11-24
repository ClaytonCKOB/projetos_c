/*
    Made by Clayton Kaua Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        Dado um numero, retornara a quantidade de digitos impares e pares.
*/

#include <stdio.h>
#include <math.h>

int digitos(int numero, int action){
    float resto;

    //Caso trivial
    if(numero == 0 && numero/10 == 0){
        if(action == 0 && numero > 0){
            return 1;
        }else return 0;
    }
    //Restante do codigo
    else{
        int un = (numero % 10);
        resto = un % 2;

        if(action == 0){
            if(resto == 0){
                return 1 + digitos(numero / 10, 0);
            }else return digitos(numero / 10, 0);
        }else{
            if(resto == 1){
                return 1 + digitos(numero / 10, 1);
            }else return digitos(numero / 10, 1);
        }


    }

}

int putTogether(int dm, int m, int c, int d, int u){
    int num = dm*pow(10, 4) + m*pow(10, 3) + c*pow(10, 2) + d*10 + u;
    return num;
}

int main(){
    int dm, m ,c, d, u, num;
    int par;
    int impar;

    printf("Digite um numero: ");
    scanf("%d%d%d%d%d", &dm, &m, &c, &d, &u);

    num = putTogether(dm, m, c, d, u);


    par   = digitos(num, 0);
    impar = digitos(num, 1);


    printf("O numero %d tem %d digitos pares\n",   num, par);
    printf("O numero %d tem %d digitos impares\n", num, impar);


}