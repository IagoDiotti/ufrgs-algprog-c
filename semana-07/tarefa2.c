#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// funcao A
void FuncA(int mat[][20],int m, int n, int inicio, int fim){
    int i, j;

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
           mat[i][j] =  rand() % (fim - inicio + 1) + inicio;
        }
    }
}
//funcao B
void FuncB(int mat[][20], int m, int n){
    int i, j;

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
           printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }


}
//funcao C
float FuncC(int mat[][20], int m, int n, int vet[], int *indice){
    int i, j, ix = 0;
    float media = 0;
// acumulacao da media
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            media += mat[i][j];
        }
    }

    media = media / (m * n);
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            if (mat[i][j] > media){
                vet[ix] = mat[i][j];
                ix++;
            }
        }
    }
 // retorno do indice;
    *indice = ix;

    return media;
}




int main() {
    // seed aleatoria
    srand(time(NULL));
    int mat[20][20], vet[400] = {}, n, m, inicio, fim, i;
    float media;
    int indice = 0;


    printf("Digite a quantidade de linhas m: \n");
    scanf("%d", &m);

    printf("Digite a quantidade de colunas n: \n");
    scanf("%d", &n);

    printf("digite o valor inicial do intervalo: \n");
    scanf("%d", &inicio);

    printf("digite o valor final do intervalo: \n");
    scanf("%d", &fim);

    //chamada das funcoes
    FuncA(mat, m, n, inicio, fim);

    FuncB(mat, m, n);
    media = FuncC(mat, m, n, vet, &indice);

    printf("media da matriz: %3.2f\n", media);
    printf("numeros da matriz acima da media: ");
    for(i = 0;i < indice; i++){
            printf("%d ", vet[i]);
    }



    return 0;

}
