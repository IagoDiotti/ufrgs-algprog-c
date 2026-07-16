#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define NALUNOS 5
#define NPROVAS 2
#define NQUESTOES 5

int main() {
    int notas[NALUNOS][NPROVAS][NQUESTOES];
    int i, j, c;
    float media, nota, r, mediaAlu;
    srand(100);
    media = 0;

    // preenchendo arranjo
    for (i = 0; i < NALUNOS; i++){
         for (j = 0; j < NPROVAS; j++){
            for (c = 0; c < NQUESTOES; c++){
                r =  (rand() % 101) / 10.0;
                notas[i][j][c] = r;
            }
         }
    }

    // calculando media
    for (i = 0; i < NALUNOS; i++){
        media += notas[i][0][1];
        }

    media = media / NALUNOS;
    printf("Media da turma na segunda questao da primeira prova: %.1f\n", media);


    // calculando e imprimindo a media de cada aluno
for (i = 0; i < NALUNOS; i++){
    float totalAlu = 0;
    for (j = 0; j < NPROVAS; j++){
        for (c = 0; c < NQUESTOES; c++){
            totalAlu += notas[i][j][c];
        }
    }
    printf("Média do aluno %d: %.2f\n", i + 1, totalAlu / (NPROVAS * NQUESTOES));
}









    return 0;
    }
