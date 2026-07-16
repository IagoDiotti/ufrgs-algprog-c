#include <stdio.h>
#include <string.h>

int main() {
    char str1[25];
    char str2[25];
    int tam, i, j, iguais;




    printf("Digite o texto: \n");
    gets(str1);



    tam = strlen(str1);
    j = 0;

    for(i = tam - 1; i >= 0; i--) {
        str2[j] = str1[i];
        j++;
    }
    str2[j] = '\0';
    i = 0;
    printf("%s\n", str2);


    if (strcasecmp(str1, str2) == 0){
        printf("é um palindromo");
    } else {
        printf("não é um palindromo");
    }



    return 0;
}
