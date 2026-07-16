#include <stdio.h>
#include <math.h>


int main() {
    float numeros[20] = {};
    int i, tam, num, j;
    float maior, menor, prox1, prox2, dif;

    menor = 100.0;
    maior = -1.0;

    printf("digite quantos números(1 a 20): \n");
    scanf("%d", &tam);


    for (i = 0; i < tam; i++){
        printf("digite o número: \n");
        scanf("%F", &numeros[i]);
        }




    dif = 100.0;
    for(i = 0; i < tam; i++){
        printf("[%f]", numeros[i]);
        if (numeros[i] > maior){
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }

    }


    for (i = 0; i < tam; i++){
        for (j = i + 1; j < tam; j++){
            if ((numeros[i] - numeros[j]) < fabsf(dif)){
                dif = fabsf(numeros[i] - numeros[j]);
                prox1 = numeros[i];
                prox2 = numeros[j];
            }

        }






    }

    printf("Maior: %f\n", maior);
    printf("Menor: %f\n", menor);
    printf("dif: %f\n", dif);
    printf("dois mais proximos: %f , %f\n", prox1, prox2);


    return 0;


}
