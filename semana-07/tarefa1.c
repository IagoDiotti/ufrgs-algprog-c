#include <stdio.h>
#include <ctype.h>
// define saldo inicial

void simulaFinancas(float *saldo, float valor, char operacao){
// faz a operação
    if (operacao == 'D') {
        *saldo = *saldo + valor;
    } else if (operacao == 'S') {
        *saldo = *saldo - valor;
    } else {
        *saldo = *saldo * valor;
    }

    printf("Saldo após operação: %3.2f\n", *saldo);



}

int main() {

char resposta;
float saldo, valor;

printf("Digite o  saldo inicial: \n");
scanf("%f", &saldo);
// incia o loop
 while(resposta != 'N'){
    printf("Digite a letra da operação: \n");
    scanf(" %c", &resposta);
    resposta = toupper(resposta);

    // verifica a operacao
    if (resposta == 'D'){
        printf("Digite o valor do depósito: \n");
        scanf("%f", &valor);
        simulaFinancas(&saldo, valor, resposta);
    } else if (resposta == 'S'){
        printf("Digite o valor do saque: \n");
        scanf("%f", &valor);
        simulaFinancas(&saldo, valor, resposta);
    } else if (resposta == 'R'){
        simulaFinancas(&saldo, 1.05, resposta);
    } else if (resposta == 'T'){
        simulaFinancas(&saldo, 0.98, resposta);
    } else if (resposta == 'N'){
    printf("encerrando");
    } else {
        printf("Operação inválida.\n");
    }

 }



return 0;
}
