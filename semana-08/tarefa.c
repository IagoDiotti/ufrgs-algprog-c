#include <stdio.h>
#define N 3

// definição da struct
typedef struct struct_imovel {
    int cod;
    float area;
    float valor;
}IMOVEL;


int main () {
    // declaração das variáveis
    FILE *arq;
    int i, cod;
    IMOVEL imoveis[N];
    float area, valor;

    // for inicial para preencher o vetor
    for(i=0;i < N; i++){
        printf("Digite o código do imóvel: \n");
        scanf("%d", &cod);
        printf("Digite a area do imóvel: \n");
        scanf("%f", &area);
        printf("Digite o valor do imóvel: \n");
        scanf("%f", &valor);
        imoveis[i].cod = cod;
        imoveis[i].area = area;
        imoveis[i].valor = valor;
    }


    // testa se o arquivo foi criado
    if(!(arq = fopen("Registro_imoveis.bin", "wb"))){
        printf("erro na abertura do arquivo\n");
    } else {
        //testa se a escrita foi correta
        if (fwrite (imoveis, sizeof(IMOVEL), N, arq) == N){
            printf("Escrita correta\n");
        } else{
            printf("escrita incorreta");
        }
    }

    // fecha o arquivo
    fclose(arq);


    // testa se o arquivo foi criado
    if(!(arq = fopen("Registro_imoveis.bin", "rb"))){
        printf("erro na abertura do arquivo para leitura\n");
    } else {
        //testa se a leitura foi correta.
        if (fread (imoveis, sizeof(IMOVEL), N, arq) == N){
            printf("leitura correta\n");
        } else{
            printf("leitura incorreta");
        }
    }
      // fecha o arquivo
    fclose(arq);

        printf("-----------------------------------------\n");
        printf("Relatório dos imoveis cadastrados: \n");
        printf("-----------------------------------------\n");
        printf("COD \tAREA \tVALOR\n");
        printf("-----------------------------------------\n");

    for(i=0; i < N; i++){
        printf("%d \t%f \t%f", imoveis[i].cod, imoveis[i].area, imoveis[i].valor);
    }


        printf("\n\n\n\n\n-----------------------------------------\n");
        printf("Relatório dos imoveis cadastrados pós ajuste: \n");
        printf("-----------------------------------------\n");
        printf("COD \tAREA \tVALOR\n");
        printf("-----------------------------------------\n");

    for(i=0; i < N; i++){
        imoveis[i].valor = imoveis[i].valor * 1.10;

        printf("%d \t%f \t%f\n", imoveis[i].cod, imoveis[i].area, imoveis[i].valor);
    }










    return 0;
    }
