#include <stdlib.h>
#include <stdio.h>

/*
    scanf é o input da linguagem c
    É preciso primeiro declarar o tipo do valor a ser inserido
    e depois "linkar" com o destido do valor com: &nomevar
*/

int main(){
    int age;
    char grade;
    char name[20];

    printf("Whats your age? \n");
    scanf("%d", &age);

    printf("%d \n", age);


    printf("Tell me your grade. \n");
    scanf("%c", &grade);

    printf("Your grade is %c \n", grade);

    /*
        fgets consegue pegar toda a linha
    */
    printf("Say your name: \n");
    fgets(name, 20, stdin);

    printf("Your name is %s \n", name);

}