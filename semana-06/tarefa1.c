#include <stdio.h>
#include <math.h>
//calculando juros simples
float calculo_simples(float capital, float juros, int tempo){
    float juros_simples;

    juros_simples = capital * juros * tempo;

    return juros_simples;

}
// calculando montante final com juros compostos
float calculo_composto(float capital, float juros, int tempo){
    float montante_composto;

    montante_composto = capital * (pow((1 + juros), tempo));

    return montante_composto;

}

int main() {
    int tempo;
    float capital, juros, montante, juros_simples, montante_composto;

    //pedindo dados.
    printf("Digite o capital incial: \n");
    scanf("%f", &capital);

    printf("Digite a taxa de juros: \n");
    scanf("%f", &juros);

    printf("Digite a quantidade de  meses: \n");
    scanf("%d", &tempo);

    juros = juros /100;

    juros_simples = calculo_simples(capital, juros, tempo);

    // imprimindo valores.
    printf("valor dos juros simples: %.2f\n", juros_simples);

    montante_composto = calculo_composto(capital, juros, tempo);

    printf("montante final com juros composto: %.2f\n", montante_composto);

    printf("Diferença: %.2f", montante_composto - (capital + juros_simples));





    return 0;
}
