#include <stdio.h>

int main() {
    // Declaração das variaveis
    int nEscolha, divisores, soma, primo, i;
    divisores = 0;
    soma = 0;

    printf("Digite um número inteiro positivo: \n");
    scanf("%d", &nEscolha);

    // verificando se o número é valido
    if (nEscolha >= 0) {
        // loop de repetição que divide o número escolhido por todos os inteiros entre o numero escolhido e 1
        for (i = nEscolha; i > 0; i--)
            {
            if (nEscolha % i == 0) {
                divisores += 1;
                soma += i;
            }
        }
        // print dos resultados
        printf("Divisores positivos: %d\n", divisores);
        printf("A soma de todos os divisores é: %d\n", soma);
        // verificando se é número primo
        if (divisores == 2){
            printf("É número primo\n");
        } else{
            printf("não é um número primo\n");
        }
    } else {
        printf("Número escolhido é inválido. ");
    }

    return 0;
}
