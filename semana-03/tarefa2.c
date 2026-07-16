#include <stdio.h>
#define Secreto 50

int main() {
    // inicializando e declarando as variaveis
    int tentativas, palpite, acerto, par;
    par = 0;
    tentativas = 0;
    acerto = 0;
    palpite = 0;

    // verificando se o numero secreto é par ou impar
    if (Secreto % 2 == 0)
        par = 1;

    // loop até acertar o numero secreto
    while(acerto == 0){
        printf("Escolha um numero entre 0 e 100: \n");
        scanf("%d", &palpite);
        // verificando acerto
        if (palpite == Secreto) {
            printf("Acertou!\n");
            acerto = 1;
            tentativas += 1;
            printf("Número de tentativas necessárias: %d\n", tentativas);
        } else {
            // verificando se palpite é maior ou menor que o número secreto
            if (palpite > Secreto){
                printf("Numero secreto é menor\n");
                tentativas += 1;
            } else {
                printf("Numero secreto é maior\n");
                tentativas +=1;
            }
            // verificando o número de tentativas
            if (tentativas >= 10){
                if (par == 1) {
                    printf("O numero secreto é par.\n");
                } else {
                printf("O numero secreto é impar.\n");
            }
        }
        }





    }

    return 0;
}
