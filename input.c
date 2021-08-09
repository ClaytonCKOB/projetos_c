#include <stdlib.h>
#include <stdio.h>

/*
    scanf é o input da linguagem c
    É preciso primeiro declarar o tipo do valor a ser inserido
    e depois "linkar" com o destido do valor com: &nomevar
*/

int main(){
    int age;

    printf("Whats your age? \n");
    scanf("%d", &age);

    printf("%d \n", age);
}