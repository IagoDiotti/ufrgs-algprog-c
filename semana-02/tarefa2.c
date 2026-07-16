#include <stdio.h>

int main() {
    int classe = 0;
    int nivel = 0;
    int atqFinal = 0;

    printf("Digite o código referente a classe desejada: ");
    scanf("%d", &classe);

    printf("\nDigite o nível desejado: ");
    scanf("%d", &nivel);

    // Verificando se nivel é válido
    if (nivel >= 1) {
        switch (classe){
            case 1:
                printf("\nClasse escolhida: Guerreiro");
                atqFinal = 30 + (nivel - 1) * 5;
                printf("Ataque final: %d", atqFinal);
                break;
            case 2:
                printf("\nClasse escolhida: Arqueiro");
                atqFinal = 25 + (nivel - 1) * 4;
                printf("\nAtaque final: %d", atqFinal);
                break;
            case 3:
                printf("\nClasse escolhida: Mago");
                atqFinal = 20 + (nivel - 1) * 6;
                printf("\nAtaque final: %d", atqFinal);
                break;
            case 4:
                printf("\nClasse escolhida: Ladino");
                atqFinal = 22 + (nivel - 1) * 5;
                printf("\nAtaque final: %d", atqFinal);
                break;
            default:
                printf("\nCódigo de classe inválido");
            }
    } else {
        printf("\nNível inválido");
    }


    return 0;
}
