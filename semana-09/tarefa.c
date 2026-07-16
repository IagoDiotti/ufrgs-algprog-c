#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REGISTROS 200

typedef struct {
    char nome[40];
    int quantidade;
} COMPONENTE;

typedef struct {
    int codigo;
    char descricao[20];
    float preco;
    COMPONENTE comp[10]; 
    int numComp;       
} PECA;

//Funcao 1: Imprime os campos codigo, descricao, preco e numComp
void imprimirArquivo(const char *nomeArquivo) {
    FILE *arq;
    PECA peca;

    arq = fopen(nomeArquivo, "rb");
    if (arq == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo '%s'.\n", nomeArquivo);
        return;
    }

    printf("\n--- CONTEUDO DO ARQUIVO ---\n");
    printf("%s\t %s\t %s\t %s\n", "COD", "DESCRICAO", "PRECO", "NCOMP");

    while (fread(&peca, sizeof(PECA), 1, arq) == 1) {
        printf("%d\t %s\t %.2f\t %d\n",
               peca.codigo,
               peca.descricao,
               peca.preco,
               peca.numComp);
    }

    fclose(arq);
}

// Funcao 2: edita o preco de uma peca identificada pelo codigo.
void editarPreco(const char *nomeArquivo) {
    FILE *arq;
    PECA vetor[MAX_REGISTROS];
    int numRegistros = 0;
    int codigoBuscado;
    float novoPreco;
    int i;
    int encontrado = 0;

    // Carrega todo o conteudo do arquivo em um vetor 
    arq = fopen(nomeArquivo, "rb");
    if (arq == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo '%s'.\n", nomeArquivo);
        return;
    }

    while (numRegistros < MAX_REGISTROS &&
           fread(&vetor[numRegistros], sizeof(PECA), 1, arq) == 1) {
        numRegistros++;
    }
    fclose(arq);

    // Solicita o codigo da peca a ser editada 
    printf("\nInforme o codigo da peca a ser editada: ");
    scanf("%d", &codigoBuscado);

    // Busca a peca no vetor e realiza a alteracao
    for (i = 0; i < numRegistros; i++) {
        if (vetor[i].codigo == codigoBuscado) {
            encontrado = 1;
            printf("Peca encontrada:\n");
            printf("  Codigo   : %d\n", vetor[i].codigo);
            printf("  Descricao: %s\n", vetor[i].descricao);
            printf("  Preco atual: %.2f\n", vetor[i].preco);
            printf("Informe o novo preco: ");
            scanf("%f", &novoPreco);
            vetor[i].preco = novoPreco;
            printf("Preco atualizado com sucesso.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Peca com codigo %d nao encontrada.\n", codigoBuscado);
        return;
    }

    // Salva o vetor de volta no arquivo, sobrescrevendo todos os dados anteriores
    arq = fopen(nomeArquivo, "wb");
    if (arq == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo '%s' para escrita.\n", nomeArquivo);
        return;
    }

    fwrite(vetor, sizeof(PECA), numRegistros, arq);
    fclose(arq);
}

// Funcao 3: Exporta todos os registros do arquivo binario para um arquivo texto.
void exportarParaTexto(const char *nomeArquivoBin, const char *nomeArquivoTxt) {
    FILE *arqBin;
    FILE *arqTxt;
    PECA peca;

    arqBin = fopen(nomeArquivoBin, "rb");
    if (arqBin == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo binario '%s'.\n", nomeArquivoBin);
        return;
    }

    arqTxt = fopen(nomeArquivoTxt, "w");
    if (arqTxt == NULL) {
        printf("Erro: nao foi possivel criar o arquivo texto '%s'.\n", nomeArquivoTxt);
        fclose(arqBin);
        return;
    }

    while (fread(&peca, sizeof(PECA), 1, arqBin) == 1) {
        fprintf(arqTxt, "%d|%s|%.2f|%d\n",
                peca.codigo,
                peca.descricao,
                peca.preco,
                peca.numComp);
    }

    fclose(arqBin);
    fclose(arqTxt);

    printf("Exportacao concluida. Dados gravados em %s\n", nomeArquivoTxt);
}

int main(void) {
    char nomeArqBin[100];
    char nomeArqTxt[100];
    int i;

    //nome do arquivo binario
    printf("Informe o nome do arquivo binario de pecas: ");
    scanf("%s", nomeArqBin);

    for(i = 0; i < 3; i++){
        imprimirArquivo(nomeArqBin);
        editarPreco(nomeArqBin);
    }


    // Entrada do nome do arquivo texto
    printf("\nInforme o nome do arquivo texto a ser gerado: ");
    scanf("%s", nomeArqTxt);

    //exporta os dados para o arquivo texto
    exportarParaTexto(nomeArqBin, nomeArqTxt);

    return 0;
}
