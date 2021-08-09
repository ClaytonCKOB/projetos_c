#include <stdlib.h>
#include <stdio.h>

int main(){
    // Uma variável pode ter seu valor alterado
    int num = 4;
    printf("%d\n", num);
    num = 3;
    printf("%d\n", num);

    // Porém uma constante não

    const int num1 =7;
    printf("%d\n", num1);

}