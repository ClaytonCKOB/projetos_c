/*
    Made by Clayton Kauã Oliveira Barcelos

    OBJETIVO DO PROGRAMA:
        Fazer o cálculo da nota do aluno e imprimir o conceito.
    
    PASSOS:
    - Obter dados de entrada: AP1, AP3 e TF; Caso a AP1 seja inferior a 6, deve-se 
    solicitar o valor da nota de recuperação. Nesse caso, o novo valor será a média entre 
    a nova nota e a antiga.
    -Cálculo da média: MF = AP1*0.35 + AP2*0.45 + TF*0.2.
    -Conversão para os conceitos.
    -Imprimir o resultado.

*/
#include <stdio.h>

int main() {
    //Variáveis
    double ap1, ap2, tf, rec, mf, recFinal;
    char status1[] = "aprovado";
    char status2[] = "reprovado";
    char conceito;

    //Valores
    printf("Informe a nota AP1: \n");
    scanf("%lf", &ap1);
    
    if(ap1 < 6){
        printf("Informe a nota de recuperacao: \n");
        scanf("%lf", &rec);
        printf("Nota AP1 apos recuperacao: %.2lf\n", (ap1 + rec)/2);
    }
    
    printf("Informe a nota AP2: \n");
    scanf("%lf", &ap2);
    printf("Informe a nota do Trabalho Final: \n");
    scanf("%lf", &tf);

    //Calculo
    if(ap1 < 6){
        mf = (((rec+ap1)/2)*0.35) + (ap2*0.45) + (tf*0.2);
    }
    else{
        mf = (ap1*0.35) + (ap2*0.45) + (tf*0.2);     
    }
    if(mf < 6){
        printf("Nota final antes da recuperacao: %.2lf\n", mf);
        printf("Informe a nota da recuperacao final: \n");
        scanf("%lf", &recFinal);
    }

    //Conversão
    if (mf < 6){
        if (((mf + recFinal)/2) < 6){
            conceito = 'D';
        }
        else if(((mf + recFinal)/2) >= 6){
            conceito = 'C';
        }

    }
    else{
        if(mf  >= 6 && mf < 7.5){
            conceito = 'C';
        }
        else if( mf >= 7.5 && mf < 8.5){
            conceito = 'B'; 
        }
        else{
            conceito = 'A';
        }
    }
    if(mf < 6){
        if (((mf + recFinal)/2) < 6){
            printf("o aluno foi %s com media %.2f e conceito %c\n", status2, ((mf + recFinal)/2), conceito);
        }
        else{
            printf("o aluno foi %s apos a recuperacao com media %.2f e conceito %c\n", status1, ((mf + recFinal)/2), conceito);
        }

    }
    else{
        printf("o aluno foi %s com nota %.2f e conceito %c\n", status1, mf, conceito);
    }
    return 0;
}