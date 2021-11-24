/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        Dada uma data, o programa retorna o dia seguinte
*/
#include <stdio.h>

struct data{ //Estrutura que guardara o dia, o mes e o ano.
    int dia;
    int mes;
    int ano;
};


int isBissexto(int a){ //Indica se o ano eh bissexto
    if(a % 4 == 0 && (a % 100 != 0 || a % 400 == 0)){
        return 1;
    }return 0;
}

int howManyD(int m, int a){ //Dado um mes e um ano, retorna o numero de dias daquele mes
    switch (m){
    case 1:  return 31; break;
    case 2:  return (28 + isBissexto(a)); break;
    case 3:  return 31; break;
    case 4:  return 30; break;
    case 5:  return 31; break;
    case 6:  return 30; break;
    case 7:  return 31; break;
    case 8:  return 31; break;
    case 9:  return 30; break;
    case 10: return 31; break;
    case 11: return 30; break;
    case 12: return 31; break;
    }
}

void createNextDay(int* d, int* m, int* a){ //dada uma data, indicara o proximo dia
    int ultDia = howManyD(*m, *a);
    if(*d == ultDia){
        if(*m == 12){
            *d = 1;
            *m = 1;
            *a = *a + 1;
        }else{
            *d = 1;
            *m = *m + 1;
        }
    }
    else{
        *d = *d + 1;
    }
    
}

int validaDias(int d){ //Fara a validacao do dia
    if(d >= 1 && d <= 31){
        return 1;
    }else return 0;
}

int validaMes(int m){ //Fara a validacao do mes
    if(m >= 1 && m <= 12){
        return 1;
    }else return 0;
}

int validaAno(int a){ //Fara a validacao do ano
    if(a >= 1900 && a <= 2100){
        return 1;
    }else return 0;
}

int main() {
    int quant;
    int valid = 0;

    printf("Informe a quantidade de datas que serao lidas: ");
    scanf("%d", &quant);

    for(int i = 0; i < quant; i++){
        int d, m, a;
        valid = 0;
       
        while(valid != 3){
            valid = 0;
            printf("Informe o dia, mes e ano: ");
            scanf("%d%d%d", &d, &m, &a);
            valid += validaDias(d);
            valid += validaMes(m);
            valid += validaAno(a);
            if(valid != 3){
                printf("Data invalida! Informe novamente...\n");
            }
        }
        //Ponteiros direcionados para o dia, mes e ano.
        int *pDay = &d; 
        int *pMon = &m;
        int *pYea = &a;

        printf("O dia seguinte de %d/%d/%d", d, m, a);
        
        createNextDay(pDay, pMon, pYea);//Caso necessario, fara a alteracao dos valores das variaveis.

        printf(" eh %d/%d/%d\n\n", d, m, a);
    }

    return 0;
}