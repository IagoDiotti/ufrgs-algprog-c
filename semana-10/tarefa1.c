#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int linhas, colunas;
    int matriz[10][10];

    // Leitura das dimensões
    printf("Digite o numero de linhas(Max: 10): ");
    scanf("%d", &linhas);

    printf("Digite o numero de colunas(Max: 10): ");
    scanf("%d", &colunas);
    

    // preenchendo a matriz.
    srand(time(NULL));
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            matriz[i][j] = rand() % 100;

    //mostra a matriz gerada
    printf("\nMatriz gerada:\n\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            printf("%02d  ", matriz[i][j]);
        printf("\n");
    }

    // salva no arquivo matriz.txt
    FILE *arq = fopen("matriz.txt", "w");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    fprintf(arq, "%d %d\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (j > 0) fprintf(arq, " ");
            fprintf(arq, "%02d", matriz[i][j]);
        }
        fprintf(arq, "\n");
    }
    fclose(arq);

    printf("\nArquivo matriz.txt gerado com sucesso.\n");

    // Leitura do valor
    int X;
    printf("\nDigite o valor: ");
    scanf("%d", &X);

    // Reabre o arquivo em modo leitura/escrita
    arq = fopen("matriz.txt", "r+");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo para leitura/escrita.\n");
        return 1;
    }

    // Pula a primeira linha
    int L, C;
    fscanf(arq, "%d %d\n", &L, &C);

    // Percorre todos os valores no arquivo
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            long pos_antes = ftell(arq);
            int val;
            fscanf(arq, "%d", &val);

            if (val < X) {
                fseek(arq, pos_antes, SEEK_SET);
                fprintf(arq, "%02d", 0);
                fflush(arq);
                fseek(arq, pos_antes + 2, SEEK_SET);
            }

            // pula o espaço entre os números
            if (j < C - 1)
                fseek(arq, 1, SEEK_CUR);
        }
        // Pula o '\n' ao final de cada linha
        fseek(arq, 1, SEEK_CUR);
    }

    fclose(arq);

    printf("\nValores menores que %d foram substituidos por 00.\n", X);
    printf("Abra o arquivo matriz.txt no bloco de notas para verificar.\n");

    return 0;
}
