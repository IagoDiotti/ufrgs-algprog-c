#include <stdio.h>

// Retorna a soma de todos os elementos do vetor usando recursão
int somaRec(int v[], int n) {
    if (n == 0)
        return 0;
    return v[n - 1] + somaRec(v, n - 1);
}

// Retorna o maior elemento do vetor usando recursão
int maiorRec(int v[], int n) {
    if (n == 1)
        return v[0];
    int maiorResto = maiorRec(v, n - 1);
    if (v[n - 1] > maiorResto)
        return v[n - 1];
    return maiorResto;
}

int main() {
    int v[20];
    int n;

    // Leitura do tamanho do vetor com validação
    printf("Digite o tamanho do vetor (1 a 20): ");
    scanf("%d", &n);
    

    // Leitura dos elementos
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &v[i]);
    }

    // Cálculo e exibição dos resultados
    int soma  = somaRec(v, n);
    int maior = maiorRec(v, n);

    printf("\nSoma dos elementos: %d\n", soma);
    printf("Maior valor: %d\n", maior);

    return 0;
}
