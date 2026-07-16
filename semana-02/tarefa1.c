#include <stdio.h>

int main() {
    float lado1 = 0;
    float lado2 = 0;
    float lado3 = 0;

    printf("Digite o primeiro número: ");
    scanf("%f", &lado1);
    printf("Digite o segundo número: ");
    scanf("%f", &lado2);
    printf("Digite o terceiro número: ");
    scanf("%f", &lado3);

    // verificando se é um triângulo
    if ((lado1 + lado2 > lado3) && (lado1 + lado3 > lado2) && (lado2 + lado3 > lado1)) {
        printf("\nOs números formam um triângulo.\n");

        // Verificando qual triângulo
        if ((lado1 == lado2) && (lado2 == lado3)) {
            printf("Triângulo equilátero\n");
        }
        else if ((lado1 == lado2) || (lado1 == lado3) || (lado2 == lado3)) {
            printf("Triângulo isósceles\n");
        }
        else {
            printf("Triângulo escaleno\n");
        }
    }
    else {
        printf("\nNão é um triângulo\n");
    }

    return 0;
}

