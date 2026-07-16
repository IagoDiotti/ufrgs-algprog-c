#include <stdlib.h>
#include <stdio.h>
int main() {
    int m[4][4];
    int i, j;
    int par = 0;
    int diag = 0;

    /* preenchendo a matriz*/
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("Digite o número da posição %d x %d\n", i+1, j+1);
            scanf("%d", &m[i][j]);
        }
    }
    /* Contando os pares*/
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(m[i][j] % 2 == 0){
                par += 1;
            }
        }
    }
    /*calculando a soma da diagonal secundaria*/
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(m[i][j] == m[0][3]){
                diag += m[i][j];
            }
            if (m[i][j] == m[1][2]){
                diag += m[i][j];
            }
            if (m[i][j] == m[2][1]){
                diag += m[i][j];
            }
            if (m[i][j] == m[3][0]){
                diag += m[i][j];
            }
        }
    }
    /* substituindo os negativos*/
     for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(m[i][j] < 0){
                m[i][j] = 0;
            }
        }
    }





    /*imprimindo os resultados*/
    printf("numero de pares: %d\n", par);
    printf("soma diagonal secundaria: %d\n", diag);

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    return 0;
    }
