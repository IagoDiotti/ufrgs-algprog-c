#include <stdio.h>
#include <math.h>

int main() {
    float saldoInicial = 0;
    float valorDesejado = 0;
    float valorEco = 0;
    float saldoAtual = 0;
    double meses = 0;

    printf("Digite o saldo inicial: ");
    scanf("%f", &saldoInicial);

    printf("\nDigite o valor desejado: ");
    scanf("%f", &valorDesejado);

    printf("\nDigite a economia mensal: ");
    scanf("%f", &valorEco);

    valorDesejado = valorDesejado - saldoInicial;
    meses = valorDesejado / valorEco;
    meses = ceil(meses);

    printf("Meses necessários: %f", meses);

    return 0;
}
